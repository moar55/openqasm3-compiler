#include "expression_handler.h"
#include "mlir/Dialect/Vector/IR/VectorOps.h"
using namespace mlir;

std::any visitor::visitBuiltInCall(qasmParser::BuiltInCallContext *ctx) {
  if (ctx->PRINT()) {
    auto expr = ctx->expressionList()->expression(0);
    qasm_expression_generator generator(builder, symbol_table);
    generator.visitExpression(expr);
    auto val = generator.current_value;
    builder.create<vector::PrintOp>(builder.getUnknownLoc(), val);
  } else {
    printErrorMessage("only print builtincall is currently supported");
  }
  return {};
}
