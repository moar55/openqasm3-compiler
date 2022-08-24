#include "../visitor.hpp"
#include "mlir/Dialect/Arithmetic/IR/Arithmetic.h"

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
                      .output();
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

mlir::Value get_or_extract_qubit(const std::string &qreg_name,
                                 const std::size_t idx, mlir::Location location,
                                 ScopedSymbolTable &symbol_table,
                                 mlir::OpBuilder &builder) {
  auto key = symbol_table.array_qubit_symbol_name(qreg_name, idx);
  if (symbol_table.has_symbol(key)) {
    // Check if the cached qubit SSA var dominance properties in the current
    // scope:
    mlir::Value qubit_value = symbol_table.get_symbol(key);
    if (!symbol_table.verify_qubit_ssa_dominance_property(
            qubit_value, builder.getInsertionBlock())) {
      // The cache SSA value is not valid:
      symbol_table.erase_symbol(key);
      return get_or_extract_qubit(qreg_name, idx, location, symbol_table,
                                  builder);
    } else {
      return qubit_value;
    }
  } else {
    auto qubits = symbol_table.get_symbol(qreg_name);
    mlir::Value pos = get_or_create_constant_integer_value(
            idx, location, builder.getI64Type(), symbol_table, builder);
    auto value = builder.create<mlir::quantum::ExtractQubitOp>(
            location, get_custom_opaque_type("Qubit", builder.getContext()), qubits,
            pos);
    symbol_table.add_symbol(key, value);
    return value;
  }
}


std::any visitor::visitQuantumMeasurementAssignment(
        qasmParser::QuantumMeasurementAssignmentContext* context) {
  StringAttr str_attr = builder.getStringAttr("mz");
  auto measured_qreg = context->quantumMeasurement()->indexedIdentifier()->Identifier()->getText();
  auto qubits = symbol_table.get_symbol(measured_qreg);
  auto extract_qubit = get_or_extract_qubit(measured_qreg, 0, builder.getUnknownLoc(),
                                            symbol_table, builder);
  auto bit_variable_name =
          context->indexedIdentifier()->Identifier()->getText();
  auto bit_value = symbol_table.get_symbol(bit_variable_name);
  mlir::Value bit_idx_val = get_or_create_constant_integer_value(
          0, builder.getUnknownLoc(), builder.getI64Type(), symbol_table, builder);
  auto instop = builder.create<mlir::quantum::InstOp>(
          builder.getUnknownLoc(), result_type, str_attr,
          llvm::makeArrayRef(extract_qubit),
          llvm::makeArrayRef(std::vector<mlir::Value>{}));
  auto cast_bit_op = builder.create<mlir::quantum::ResultCastOp>(
          builder.getUnknownLoc(), builder.getIntegerType(1), instop.bit());
  builder.create<mlir::memref::StoreOp>(
          builder.getUnknownLoc(), cast_bit_op.bit_result(), bit_value,
          llvm::makeArrayRef(std::vector<mlir::Value>{bit_idx_val}));
  symbol_table.invalidate_qubit_extracts(measured_qreg, {0});
  return {};
}