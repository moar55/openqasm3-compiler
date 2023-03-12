#include "quantum-mlir/Dialect/Quantum/IR/QuantumDialect.h"
#include <quantum-mlir/Dialect/RestrictedQuantum/IR/RestrictedQuantumDialect.h>
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/Dialect/SCF/IR/SCF.h"
#include "mlir/Dialect/Arith/IR/Arith.h"

#include "mlir/Dialect/Vector/IR/VectorOps.h"

#include "expression_handler.h"
#include "mlir/IR/BuiltinAttributes.h"

#include "../Visitor.hpp"
using namespace mlir;

std::any Visitor::visitBranchingStatement(qasmParser::BranchingStatementContext *ctx) {
  qasm_expression_generator generator(builder, symbol_table);
  generator.visitExpression(ctx->expression());
  auto &cond = generator.current_value;
  assert(cond.getType().isa<IntegerType>() && cond.getType().getIntOrFloatBitWidth() == 1); //make sure type is i1

  // Go over each unique variable to find out the return list and their types,
  // shadow build to find out the types first
  auto hasElseBlock = ctx->statementOrScope().size() == 2;

  auto builder_backup = builder;
  // -------------- begin shadow visit ----------------------------//
  //TODO: refactor in a function?
  auto context = std::make_unique<MLIRContext>();
  context->loadDialect<quantum::QuantumDialect, memref::MemRefDialect, arith::ArithDialect,
            vector::VectorDialect,
            scf::SCFDialect, func::FuncDialect, restquantum::RestrictedQuantumDialect>();
  OpBuilder shadow_builder(context.get());
  std::set<std::string> yield_symbols;

  builder = shadow_builder;
  symbol_table.enter_new_scope();
  // visit then scope nodes
  this->visitChildren(ctx->if_body);
  for (auto const& [symbol, val] : symbol_table.get_symbols_and_values_pair(symbol_table.get_current_scope())) { //TODO: refactor in a function
    if (symbol_table.has_symbol(symbol, symbol_table.get_parent_scope(), true)) {
      yield_symbols.insert(symbol);
    }
  }
  symbol_table.exit_scope();

  if (hasElseBlock) {
    symbol_table.enter_new_scope();
    // visit else scope nodes
    this->visitChildren(ctx->else_body);
    for (auto const& [symbol, val] : symbol_table.get_symbols_and_values_pair(symbol_table.get_current_scope())) {
      if (symbol_table.has_symbol(symbol, symbol_table.get_parent_scope(), true)) {
        yield_symbols.insert(symbol);
      }
    }
    symbol_table.exit_scope();
  }

  //-------------- end shadow build --------------------------//
  builder = builder_backup;

  std::vector<Type> yield_types;
  for (auto const& symbol: yield_symbols) {
      yield_types.push_back(get_symbol_type(symbol));
  }

  auto ifOp = builder.create<scf::IfOp>(builder.getUnknownLoc(), yield_types, cond, hasElseBlock);
  // Build the then part
  auto thenBodyBuilder = ifOp.getThenBodyBuilder();
  builder = thenBodyBuilder;
  symbol_table.enter_new_scope();
  // visit then scope nodes
  this->visitChildren(ctx->if_body);
  gen_yield_of_symbols(yield_symbols);
  symbol_table.exit_scope();

  if (hasElseBlock) {
    auto elseBodyBuilder = ifOp.getElseBodyBuilder();
    builder = elseBodyBuilder;
    symbol_table.enter_new_scope();
    // visit else scope nodes
    this->visitChildren(ctx->else_body);
    gen_yield_of_symbols(yield_symbols);
    symbol_table.exit_scope();
  }

  builder = builder_backup;

  auto it = ifOp.getResults().begin();
  for (auto const& symbol: yield_symbols) {
    symbol_table.add_symbol(symbol, *it, true);
    it = std::next(it);
  }
  return {};
}