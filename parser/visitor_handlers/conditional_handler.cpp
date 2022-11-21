#include "mlir/Dialect/Arithmetic/IR/Arithmetic.h"
#include "../visitor.hpp"
using namespace mlir;

std::any visitor::visitBranchingStatement(qasmParser::BranchingStatementContext *ctx) {
  //TODO: fill
  return this->visitChildren(ctx);
}
