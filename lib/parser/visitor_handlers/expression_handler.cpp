#include "../generated/qasmLexer.h"
#include "mlir/Dialect/Arith/IR/Arith.h"
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
//      if (symbol_table.get_symbol(ctx->getText()).getType().operator!=(internal_value_type) //TODO: uncomment
//        printErrorMessage("Type mismatch for identifier " + ctx->getText());
      update_current_value(symbol_table.get_symbol(ctx->getText()));
      return {};
    }
    default:
      return this->visitChildren(ctx);
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
    if (internal_value_type.isa<IntegerType>() || internal_value_type.isa<VectorType>()) { //TODO: handle when vector is not an integer vector
      if (ctx->MINUS()) {
        if (internal_value_type.isa<VectorType>()) {
          rhs = builder.create<arith::MulIOp>(location, rhs, get_mlir_integer_val(builder, -1, builder.getI1Type()));
        } else {
          rhs = builder.create<arith::MulIOp>(location, rhs, get_mlir_integer_val(builder, -1, internal_value_type));
        }
        location = builder.getUnknownLoc();
      }
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
      if (internal_value_type.isa<IntegerType>() || internal_value_type.isa<VectorType>()) { //TODO: handle when vector is not an integer vector
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

std::any qasm_expression_generator::visitBitOrExpression(qasmParser::BitOrExpressionContext *ctx) {
  auto _xor = ctx->xOrExpression();
  // TODO: handle float types
  if (auto _or = ctx->bitOrExpression()) {
    this->visitBitOrExpression(_or);
    auto lhs = current_value;
    this->visitXOrExpression(_xor);
    auto rhs = current_value;
    auto val = builder.create<arith::OrIOp>(builder.getUnknownLoc(), lhs, rhs);
    update_current_value(val);
  } else {
    this->visitXOrExpression(_xor);
  }
  return {};
}

std::any qasm_expression_generator::visitXOrExpression(qasmParser::XOrExpressionContext *ctx) {
  auto bit_and = ctx->bitAndExpression();
  // TODO: handle float types
  if (auto _xor = ctx->xOrExpression()) {
    this->visitXOrExpression(_xor);
    auto lhs = current_value;
    this->visitBitAndExpression(bit_and);
    auto rhs = current_value;
    auto val = builder.create<arith::XOrIOp>(builder.getUnknownLoc(), lhs, rhs);
    update_current_value(val);
  } else {
    this->visitBitAndExpression(bit_and);
  }
  return {};
}

std::any qasm_expression_generator::visitBitAndExpression(qasmParser::BitAndExpressionContext *ctx) {
  auto eq_expr = ctx->equalityExpression();
  //TODO: handle float types
  if (auto bit_and = ctx->bitAndExpression()) {
    this->visitBitAndExpression(bit_and);
    auto lhs = current_value;
    this->visitEqualityExpression(eq_expr);
    auto rhs = current_value;
    auto val = builder.create<arith::AndIOp>(builder.getUnknownLoc(), lhs, rhs);
    update_current_value(val);
  } else {
    this->visitEqualityExpression(eq_expr);
  }
  return {};
}


std::any qasm_expression_generator::visitEqualityExpression(qasmParser::EqualityExpressionContext *ctx) {
  if (ctx->equalityExpression()) {
    this->visitEqualityExpression(ctx->equalityExpression());
    auto lhs = this->current_value;
    this->visitComparisonExpression(ctx->comparisonExpression());
    auto rhs = this->current_value;
    auto operator_str = ctx->equalityOperator()->getText();
    auto type = lhs.getType();     //TODO: handle different types and signed vs unsigned

    using namespace arith;
    if (type.isa<IntegerType>()) {
      std::map<std::string, CmpIPredicate> opeartor_to_comp_type = {
              {"==",  CmpIPredicate::eq},
              {"!=",  CmpIPredicate::ne}
      };
      auto val = builder.create<arith::CmpIOp>(builder.getUnknownLoc(), opeartor_to_comp_type[operator_str], lhs, rhs);
      update_current_value(val);
    } else if(type.isa<FloatType>()){
      std::map<std::string, CmpFPredicate> opeartor_to_comp_type = {
              {"==",  CmpFPredicate::OEQ},
              {"!=",  CmpFPredicate::ONE}
      };
      auto val = builder.create<arith::CmpFOp>(builder.getUnknownLoc(), opeartor_to_comp_type[operator_str], lhs, rhs);
      update_current_value(val);
    }
  } else {
    this->visitComparisonExpression(ctx->comparisonExpression());
  }
  return {};
}


std::any qasm_expression_generator::visitComparisonExpression(qasmParser::ComparisonExpressionContext *ctx) {
  if (ctx->comparisonExpression()) {
    this->visitComparisonExpression(ctx->comparisonExpression());
    auto lhs = this->current_value;
    this->visitBitShiftExpression(ctx->bitShiftExpression());
    auto rhs = this->current_value;
    auto operator_str = ctx->comparisonOperator()->getText();
    auto type = lhs.getType();
    //TODO: handle different types and signed vs unsigned

    using namespace arith;
    if (type.isa<IntegerType>()) {

      std::map<std::string, CmpIPredicate> opeartor_to_comp_type = {
              {">",  CmpIPredicate::sgt},
              {"<",  CmpIPredicate::slt},
              {">=", CmpIPredicate::sge},
              {"<=", CmpIPredicate::sle}
      };
      auto val = builder.create<arith::CmpIOp>(builder.getUnknownLoc(), opeartor_to_comp_type[operator_str], lhs, rhs);
      update_current_value(val);
    } else if(type.isa<FloatType>()){
      std::map<std::string, CmpFPredicate> opeartor_to_comp_type = {
              {">",  CmpFPredicate::OGT},
              {"<",  CmpFPredicate::OLT},
              {">=", CmpFPredicate::OGE},
              {"<=", CmpFPredicate::OLE}
      };
      auto val = builder.create<arith::CmpFOp>(builder.getUnknownLoc(), opeartor_to_comp_type[operator_str], lhs, rhs);
      update_current_value(val);
    }
  } else {
    this->visitBitShiftExpression(ctx->bitShiftExpression());
  }
  return {};
}


