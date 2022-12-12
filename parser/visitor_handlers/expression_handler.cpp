#include "../generated/qasmLexer.h"
#include "mlir/Dialect/Arithmetic/IR/Arithmetic.h"
#include <cmath>
#include "expression_handler.h"

using namespace mlir;

std::map<std::string, double> my_map = {
        {"pi", M_PI}, {"π", M_PI}, {"tau", M_PI * 2},
        {"𝜏", M_PI * 2}, {"euler", std::exp(1.0)}, {"ℇ", std::exp(1.0)}
};

qasm_expression_generator::qasm_expression_generator(OpBuilder &b, ScopedSymbolTable &table)
       : builder(b), symbol_table(table) {
  internal_value_type = builder.getI64Type();
}

qasm_expression_generator::qasm_expression_generator(OpBuilder& b, ScopedSymbolTable& table,Type t)
        : builder(b),
          internal_value_type(t),
          symbol_table(table) {}

void qasm_expression_generator::update_current_value(mlir::Value v) {
  last_current_value = current_value;
  current_value = v;
}

template <typename AtTy, typename OpTy, typename VTy>
Value qasm_expression_generator::createAttrOpFromVal(VTy val) {
  AtTy attr = AtTy::get(internal_value_type, val);
  return createOp<OpTy>(builder.getUnknownLoc(), attr);
}

std::any qasm_expression_generator::visitExpressionTerminator(qasmParser::ExpressionTerminatorContext *ctx) {
  std::cout << "the tokennn" << ctx->getText() << "\n";
  //TODO: make sure that this is *really* the correct location
  //TODO: type casting and adjusting bit width
  switch(ctx->getStart()->getType()) {
    case qasmLexer::Constant: {
      if (!internal_value_type.isa<FloatType>()) {
        printErrorMessage("Can't assign a floating point value to an integer identifier");
      }
      double constant_val = my_map.at(ctx->getText());
      return createAttrOpFromVal<FloatAttr, arith::ConstantOp, double>(constant_val);
    }
    case qasmLexer::Integer: {
      int int_val = std::stoi(ctx->getText());
      if (internal_value_type.isa<IntegerType>()) {
        return createAttrOpFromVal<IntegerAttr, arith::ConstantOp, int>(int_val);
      } else {
        return createAttrOpFromVal<FloatAttr, arith::ConstantOp, double>(int_val);
      }
    }
    case qasmLexer::RealNumber: {
      if (!internal_value_type.isa<FloatType>()) {
        printErrorMessage("Can't assign a floating point value to an int identifier", ctx);
        internal_value_type.dump();
      }
      auto value = std::stod(ctx->getText());
      return createAttrOpFromVal<FloatAttr, arith::ConstantOp, double>(value);
    }
    case qasmLexer::Identifier: {
      if (!symbol_table.has_symbol(ctx->getText())) {
        printErrorMessage("Identifier " + ctx->getText() + "is not declared.");
      }
      if (symbol_table.get_symbol(ctx->getText()).getType() != internal_value_type)
        printErrorMessage("Type mismatch for identifier " + ctx->getText());
      update_current_value(symbol_table.get_symbol(ctx->getText()));
    }
    default:
      return {};
  }
}

std::any qasm_expression_generator::visitExpression(qasmParser::ExpressionContext *ctx) {
  return qasmBaseVisitor::visitExpression(ctx);
}

std::any qasm_expression_generator::visitAdditiveExpression(qasmParser::AdditiveExpressionContext *ctx) {
  auto location = builder.getUnknownLoc();
  if (ctx->additiveExpression()) {
    this->visitAdditiveExpression(ctx->additiveExpression());
    auto lhs = current_value;
    this->visitMultiplicativeExpression(ctx->multiplicativeExpression());
    auto rhs = current_value;
    Value val;
    if (internal_value_type.isa<IntegerType>()) {
      val = createOp<arith::AddIOp>(location, lhs, rhs);
    } else if (internal_value_type.isa<FloatType>()){
      val = createOp<arith::AddFOp>(location, lhs, rhs);
    } else {
      printErrorMessage("Assigning to an identifier of this type is not supported yet!");
    }
    update_current_value(val);
  } else {
    this->visitMultiplicativeExpression(ctx->multiplicativeExpression());
  }
  return {};
}

std::any qasm_expression_generator::visitMultiplicativeExpression(qasmParser::MultiplicativeExpressionContext *ctx) {
    auto location = builder.getUnknownLoc();
    if (ctx->multiplicativeExpression()) {
      this->visitMultiplicativeExpression(ctx->multiplicativeExpression());
      auto lhs = current_value;
      this->visitUnaryExpression(ctx->unaryExpression());
      auto rhs = current_value;
      Value val;
      if (internal_value_type.isa<IntegerType>()) {
        val = createOp<arith::MulIOp>(location, lhs, rhs);
      } else if (internal_value_type.isa<FloatType>()){
        val = createOp<arith::MulFOp>(location, lhs, rhs);
      } else {
        printErrorMessage("Assigning to an identifier of this type is not supported yet!");
      }
      update_current_value(val);
    } else {
      this->visitUnaryExpression(ctx->unaryExpression());
    }
    return {};
  }