#include "Quantum/IR/QuantumDialect.h"
#include <RestrictedQuantum/RestrictedQuantumDialect.h>
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/Dialect/SCF/SCF.h"
#include "mlir/Dialect/Arithmetic/IR/Arithmetic.h"

#include "expression_handler.h"
#include "mlir/IR/BuiltinAttributes.h"

#include "../visitor.hpp"
using namespace mlir;

std::any visitor::visitBranchingStatement(qasmParser::BranchingStatementContext *ctx) {
  qasm_expression_generator generator(builder, symbol_table, builder.getI1Type());
  generator.visitExpression(ctx->expression());
  auto &cond = generator.current_value;
  assert(cond.getType().isa<IntegerType>() && cond.getType().getIntOrFloatBitWidth() == 1); //make sure type is i1

  // TODO: Go over each unique variable to find out the return list and their types,
  //  disable building to find out the types first
  auto hasElseBlock = ctx->statementOrScope().size() == 2;

  auto builder_backup = builder;

  auto context = std::make_unique<MLIRContext>();
  context->loadDialect<quantum::QuantumDialect, memref::MemRefDialect, arith::ArithmeticDialect,
            scf::SCFDialect, func::FuncDialect, restquantum::RestrictedQuantumDialect>();

  OpBuilder shadow_builder(context.get());
//  auto shadow_module = ModuleOp::create(shadow_builder.getUnknownLoc());
//
//  llvm::StringRef name("quantum");
//  StringAttr n = StringAttr::get(context.get(), name); // namespace
//
//  auto int_type = shadow_builder.getI32Type();
//  auto argv_type =
//          OpaqueType::get(n, llvm::StringRef("ArgvType"));
//
//  std::vector<Type> arg_types_vec{int_type, argv_type};
//  auto func_type =
//          shadow_builder.getFunctionType(llvm::makeArrayRef(arg_types_vec), int_type);
//  auto proto =
//          func::FuncOp::create(shadow_builder.getUnknownLoc(), "main", func_type);
//  func::FuncOp function(proto);
//
//  auto &entryBlock = *function.addEntryBlock();
//  shadow_builder.setInsertionPointToStart(&entryBlock);
//  shadow_module.push_back(function);

  std::set<std::string> yield_symbols;

  builder = shadow_builder;
  symbol_table.enter_new_scope();
  // visit then scope nodes
  this->visitChildren(ctx->if_body);
  for (auto const& [symbol, val] : symbol_table.get_symbols_and_values_pair(symbol_table.get_current_scope())) {
    if (symbol_table.has_symbol(symbol, symbol_table.get_parent_scope())) {
      yield_symbols.insert(symbol);
    }
  }
  symbol_table.exit_scope();

  if (hasElseBlock) {
    symbol_table.enter_new_scope();
    // visit else scope nodes
    this->visitChildren(ctx->else_body);
    for (auto const& [symbol, val] : symbol_table.get_symbols_and_values_pair(symbol_table.get_current_scope())) {
      if (symbol_table.has_symbol(symbol, symbol_table.get_parent_scope())) {
        yield_symbols.insert(symbol);
      }
    }
    symbol_table.exit_scope();
  }

  builder = builder_backup;

  std::vector<Type> yield_types;
  for (auto const& symbol: yield_symbols) {
      yield_types.push_back(symbol_table.get_symbol(symbol).getType());
  }

  auto ifOp = builder.create<scf::IfOp>(builder.getUnknownLoc(), llvm::ArrayRef(yield_types), cond, hasElseBlock);

  // Build the then part
  auto thenBodyBuilder = ifOp.getThenBodyBuilder();
  builder = thenBodyBuilder;
  symbol_table.enter_new_scope();
  // visit then scope nodes
  this->visitChildren(ctx->if_body);
  for (auto const& symbol: yield_symbols) {
    builder.create<scf::YieldOp>(builder.getUnknownLoc(), symbol_table.get_symbol(symbol));
  }
  symbol_table.exit_scope();

  if (hasElseBlock) {
    auto elseBodyBuilder = ifOp.getElseBodyBuilder();
    builder = elseBodyBuilder;
    symbol_table.enter_new_scope();
    // visit else scope nodes
    this->visitChildren(ctx->else_body);
    for (auto const& symbol: yield_symbols) {
      builder.create<scf::YieldOp>(builder.getUnknownLoc(), symbol_table.get_symbol(symbol));
    }
    symbol_table.exit_scope();
  }

  builder = builder_backup;

  auto it = ifOp.getResults().begin();
  for (auto const& symbol: yield_symbols) {
    symbol_table.add_symbol(symbol, *it, {}, true);
    it = std::next(it);
  }
  return {};
}
