#include "../visitor.hpp"
#include "mlir/Dialect/Arith/IR/Arith.h"
#include "../utils/qasm_utils.hpp"


mlir::Value get_or_create_constant_integer_value(
        const std::size_t idx, mlir::Location location, mlir::Type type,
        ScopedSymbolTable &symbol_table, mlir::OpBuilder &builder) {
  auto width = type.getIntOrFloatBitWidth();
  if (symbol_table.has_constant_integer(idx, width)) {
    return symbol_table.get_constant_integer(idx, width);
  } else {
    // Handle unsigned int constant:
    // ConstantOp (std dialect) doesn't support Signed type (uint)
    if (!type.cast<mlir::IntegerType>().isSignless()) {
      auto signless_int_type =
              builder.getIntegerType(type.getIntOrFloatBitWidth());
      auto integer_attr = mlir::IntegerAttr::get(signless_int_type, idx);

      auto ret =
              builder
                      .create<mlir::quantum::IntegerCastOp>(
                              location, type,
                              builder.create<mlir::arith::ConstantOp>(location, integer_attr))
                      .getOutput();
      symbol_table.add_constant_integer(idx, ret, width);
      return ret;
    } else {
      auto integer_attr = mlir::IntegerAttr::get(type, idx);
      assert(integer_attr.getType().cast<mlir::IntegerType>().isSignless());
      auto ret = builder.create<mlir::arith::ConstantOp>(location, integer_attr);
      symbol_table.add_constant_integer(idx, ret, width);
      return ret;
    }
  }
}

mlir::Type get_custom_opaque_type(const std::string& type,
                                  mlir::MLIRContext* context) {
  llvm::StringRef name("quantum"), type_name(type);
  StringAttr n = StringAttr::get(context, name);
  return mlir::OpaqueType::get(n, type);
}

std::any visitor::visitQuantumMeasurement(
        qasmParser::QuantumMeasurementContext* context)  {
  return {};
}

std::any visitor::visitQuantumMeasurementAssignment(
        qasmParser::QuantumMeasurementAssignmentContext* context) {
  auto indexed_identifier = context->quantumMeasurement()->indexedIdentifier();
  auto qubit_var_name = indexed_identifier->Identifier()->getText();
  auto qubit_ident = symbol_table.get_symbol(qubit_var_name);
  auto is_single_qubit = qubit_ident.getType().dyn_cast<mlir::OpaqueType>().getTypeData() == "Qubit";
  std::vector<Value> qubits_to_be_measured;
  bool indexed = !indexed_identifier->indexOperator().empty();

  if (is_single_qubit && indexed) {
    printErrorMessage("can't index a single qubit", context);
  }
  int allocation_size;
  if (!is_single_qubit) {
    allocation_size = get_qubit_arr_size(qubit_ident);
    if (indexed) {
      auto index_expression = indexed_identifier->indexOperator().front()->expression(0);
      try {
        auto index = std::stoi(index_expression->getText()); //TODO: refactor into a function
        if ( index < 0 || index > allocation_size - 1) { //check that indexing is not out of bounds
          printErrorMessage("index out of bound for indexing variable " + qubit_var_name);
        }
        auto qubit = get_or_extrct_qubit(symbol_table, qubit_var_name, index, &builder, &qubit_type);
        qubits_to_be_measured.push_back(qubit);
      } catch(...) {
        printErrorMessage("currently only constant integer indices are supported", context);
      }
    } else {
      for (int i = 0; i < allocation_size; i++) {
        auto qubit = get_or_extrct_qubit(symbol_table, qubit_var_name, i, &builder, &qubit_type);
        qubits_to_be_measured.push_back(qubit);
      }
    }

  } else {
    qubits_to_be_measured.push_back(symbol_table.get_symbol(qubit_var_name));
    allocation_size = 1;
  }
  std::vector<Type> types(allocation_size, builder.getI1Type());
  builder.create<quantum::MzOp>(builder.getUnknownLoc(), types, qubits_to_be_measured);
  return {};
}