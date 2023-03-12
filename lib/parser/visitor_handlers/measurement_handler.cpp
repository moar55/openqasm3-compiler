#include "../Visitor.hpp"
#include "mlir/Dialect/Arith/IR/Arith.h"
#include "mlir/Dialect/Vector/IR/VectorOps.h"
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

std::any Visitor::visitQuantumMeasurement(
        qasmParser::QuantumMeasurementContext* context)  {
  auto indexed_identifier = context->indexedIdentifier();
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

  if (allocation_size == 1 || indexed) {
    return builder.create<quantum::MzOp>(builder.getUnknownLoc(), builder.getI1Type(), qubits_to_be_measured.front()).getBitResult();
  }

  std::vector<Value> measurements;
  auto temp_memref = builder.create<memref::AllocOp>(builder.getUnknownLoc(), MemRefType::get(allocation_size, builder.getI1Type()));
  for (int i = 0; i < qubits_to_be_measured.size(); i++) {
    auto qubit = qubits_to_be_measured[i];
    measurements.push_back(builder.create<quantum::MzOp>(builder.getUnknownLoc(), builder.getI1Type(), qubit).getBitResult());
    auto index_val = get_mlir_integer_val(builder, i, builder.getIndexType());
    builder.create<memref::StoreOp>(builder.getUnknownLoc(), measurements[i], temp_memref, index_val);
  }
  auto output = builder.create<vector::LoadOp>(builder.getUnknownLoc(), VectorType::get(allocation_size, builder.getI1Type()), temp_memref,
                                        get_mlir_integer_val(builder, 0, builder.getIndexType())).getResult();
  builder.create<memref::DeallocOp>(builder.getUnknownLoc(), temp_memref);
  return output;
}

std::any Visitor::visitQuantumMeasurementAssignment(
        qasmParser::QuantumMeasurementAssignmentContext* context) {
  if (context->ARROW()) {
    printErrorMessage("arrow based quantum measurement is not yet supported");
  } else {
    auto identifier_text = context->indexedIdentifier()->Identifier()->getText();
    if (!symbol_table.get_symbol(identifier_text)) {
      printErrorMessage("bit/bit array: " + identifier_text + ", is not declared!", context);
    }
    auto bit_arr = symbol_table.get_symbol(identifier_text);
    bool is_single = bit_arr.getType().isInteger(1);
    bool indexed = !context->indexedIdentifier()->indexOperator().empty();
    if (is_single && indexed) {
      printErrorMessage("cannot index a single bit!");
    }

    std::any visitOutput = this->visitQuantumMeasurement(context->quantumMeasurement());
    Value measurement_val;
    try {
      measurement_val = std::any_cast<TypedValue<IntegerType>>(visitOutput);
    } catch(...) {
      measurement_val = std::any_cast<TypedValue<VectorType>>(visitOutput);
    }

    measurement_val.getType().dump();
    //TODO: make sure width match
    if (!is_single && !indexed && (!measurement_val.getType().isa<VectorType>()  || bit_arr.getType().dyn_cast<VectorType>().getShape() !=
                      measurement_val.getType().dyn_cast<VectorType>().getShape())) {
      printErrorMessage("quantum measurement qubits size must match the size of the bit array assigned to ", context);
    }

    if ((is_single || indexed) && !measurement_val.getType().isInteger(1)) {
      printErrorMessage("cannot assign a measurement of mulitple qubits to a single bit");
    }


    if (!is_single) {
      auto bit_arr_shape = bit_arr.getType().dyn_cast<VectorType>().getShape();
      if (indexed) {
        try {
          auto index = std::stoi(context->indexedIdentifier()->indexOperator(0)->expression(0)->getText());
          auto index_val = get_mlir_integer_val(builder, index, builder.getIndexType());
          measurement_val = builder.create<vector::InsertElementOp>(builder.getUnknownLoc(), measurement_val, bit_arr, index_val);
//          auto temp_memref = builder.create<memref::AllocOp>(builder.getUnknownLoc(),
//                                                             MemRefType::get(bit_arr_shape, builder.getI1Type()));
//
//          builder.create<vector::StoreOp>(builder.getUnknownLoc(), bit_arr, temp_memref, zero_index);
//          builder.create<memref::StoreOp>(builder.getUnknownLoc(), measurement_val, temp_memref, index_val);
//          measurement_val = builder.create<vector::LoadOp>(builder.getUnknownLoc(), VectorType::get(bit_arr_shape, builder.getI1Type()),
//                                                           temp_memref, zero_index); //change to an array
//          builder.create<memref::DeallocOp>(builder.getUnknownLoc(), temp_memref);
        } catch (...) {
          printErrorMessage("non int constant designator index is not yet supported");
        }
      }
    }
    symbol_table.add_symbol(identifier_text, measurement_val, true);
  }
  return {};
}