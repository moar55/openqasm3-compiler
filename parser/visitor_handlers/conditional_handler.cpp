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

  auto context = std::make_unique<MLIRContext>();
  context->loadDialect<quantum::QuantumDialect, memref::MemRefDialect, arith::ArithmeticDialect,
          scf::SCFDialect, func::FuncDialect, restquantum::RestrictedQuantumDialect>();
  OpBuilder shadow_builder(context.get());
  auto temp = builder;
  builder = shadow_builder;
  symbol_table.enter_new_scope();
  // visit then scope nodes
  this->visitChildren(ctx->if_body);
  symbol_table.exit_scope();

  if (hasElseBlock) {
    builder = shadow_builder;
    symbol_table.enter_new_scope();
    // visit else scope nodes
    this->visitChildren(ctx->else_body);
    symbol_table.exit_scope();
  }

  builder = temp;

  auto ifOp = builder.create<scf::IfOp>(builder.getUnknownLoc(), llvm::ArrayRef{qubit_type, qubit_type}, cond, hasElseBlock);

  // Build the then part
  auto thenBodyBuilder = ifOp.getThenBodyBuilder();
  auto builder_backup = builder;
  builder = thenBodyBuilder;
  symbol_table.enter_new_scope();
  // visit then scope nodes
  this->visitChildren(ctx->if_body);
  symbol_table.exit_scope();

  if (hasElseBlock) {
    auto elseBodyBuilder = ifOp.getElseBodyBuilder();
    builder = elseBodyBuilder;
    symbol_table.enter_new_scope();
    // visit else scope nodes
    this->visitChildren(ctx->else_body);
//    builder.create<scf::YieldOp>(builder.getUnknownLoc(), temp.getResult());
    symbol_table.exit_scope();
  }
  builder = builder_backup;
  std::cout << "size " << ifOp.getResults().size() << "\n";
  return {};
}
