#include "Visitor.hpp"

#include "antlr4-runtime.h"

#include "quantum-mlir/Dialect/Quantum/IR/QuantumDialect.h"
#include <quantum-mlir/Dialect/RestrictedQuantum/IR/RestrictedQuantumDialect.h>
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/Dialect/Arith/IR/Arith.h"
#include "mlir/Dialect/SCF/IR/SCF.h"
#include "quantum-mlir/Dialect/Quantum/IR/QuantumOps.h"

// The constructor, instantiates commonly used opaque types
Visitor::Visitor(mlir::OpBuilder b, mlir::ModuleOp m, std::string &fname) : builder(b), m_module(m), file_name(fname) {
  auto context = b.getContext();
  llvm::StringRef name("quantum"), qubit_type_name("Qubit"), qubit_array_type("QubitArray"), result_type_name("Result");
  StringAttr n = StringAttr::get(context, name); // namespace
  qubit_type = mlir::OpaqueType::get(n, qubit_type_name);
  array_type = mlir::OpaqueType::get(n, qubit_array_type);
  result_type = mlir::OpaqueType::get(n, result_type_name);
  symbol_table.set_op_builder(builder);
}

void Visitor::gen_yield_of_symbols(const std::set<std::string> yield_symbols) {
  std::vector<Value> yield_qubits;
  for (auto const& symbol: yield_symbols) {
    if (symbol_table.has_symbol(symbol)) {
      yield_qubits.push_back(symbol_table.get_symbol(symbol));
    } else { // symbol is an indexed identifier that wasn't extracted till this point
      auto idx = get_index_from_indexed_name(symbol);
      auto idx_val = get_mlir_integer_val(builder, idx, builder.getI64Type());
      auto indexless_symbol = get_name_from_indexed_name(symbol);
      auto qubit_arr = symbol_table.get_symbol(indexless_symbol);
      mlir::Value qubit = builder.create<quantum::ExtractQubitOp>(builder.getUnknownLoc(), qubit_type, qubit_arr, idx_val);
      symbol_table.add_symbol(symbol, qubit); // TODO: check if  this line is unnecessary
      yield_qubits.push_back(qubit);
    }
  }
  builder.create<scf::YieldOp>(builder.getUnknownLoc(), yield_qubits);
}


mlir::Type Visitor::get_symbol_type(const std::string &var_name) {
  if (symbol_table.has_symbol(var_name)) {
    return symbol_table.get_symbol(var_name).getType();
  }
  if (symbol_table.has_symbol(var_name, true)) {
    return qubit_type;
  }

  printErrorMessage(("var " + var_name + " doesn't exist!"));
}



//void traverse_and_populate_symbols_list(antlr4::ParserRuleContext *context, ScopedSymbolTable &symbol_table, std::set<std::string> &yield_symbols) {
//  auto context = std::make_unique<MLIRContext>();
//  context->loadDialect<quantum::QuantumDialect, memref::MemRefDialect, arith::ArithDialect,
//          scf::SCFDialect, func::FuncDialect, restquantum::RestrictedQuantumDialect>();
//  OpBuilder shadow_builder(context.get());
//
//  symbol_table.enter_new_scope();
//  // visit then scope nodes
//  this->visitChildren(ctx->if_body);
//  for (auto const& [symbol, val] : symbol_table.get_symbols_and_values_pair(symbol_table.get_current_scope())) { //TODO: refactor in a funciton
//    if (symbol_table.has_symbol(symbol, symbol_table.get_parent_scope(), true)) {
//      yield_symbols.insert(symbol);
//    }
//  }
//  symbol_table.exit_scope();
//}


Visitor::~Visitor() {}