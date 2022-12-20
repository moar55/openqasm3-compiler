#include "../utils/qasm_utils.hpp"
#include "mlir/Dialect/SCF/IR/SCF.h"
#include "../visitor.hpp"

using namespace mlir;

std::any visitor::visitLoopStatement(qasmParser::LoopStatementContext *ctx) {
  auto siganture = ctx->loopSignature();
//  ctx->pro
  if (siganture->getStart()->getText() == "while") {
    qasm_expression_generator generator(builder, symbol_table, builder.getI1Type());
    generator.visitExpression(siganture->expression());
    auto insertionPoint = builder.saveInsertionPoint();
//    builder.restoreInsertionPoint()
    auto &cond = generator.current_value;
    assert(cond.getType().isa<IntegerType>() && cond.getType().getIntOrFloatBitWidth() == 1); //make sure type is i1
    Value val = *get_mlir_integer_val(builder, 20);
    auto whileOp = builder.create<scf::WhileOp>(builder.getUnknownLoc(), std::vector{qubit_type}, std::vector{val});

//    builder.create
//    builder.createBlock()
//    whileOp.getBefore().push_back()
//    auto x = builder.createBlock()
  } else {
    printErrorMessage("for loops are not yet supported");
  }
  return {};
}
