#pragma once

#include "mlir/IR/BuiltinOps.h"
#include "../visitor.hpp"
#include "../utils/qasm_utils.hpp"
#include "../utils/symbol_table.hpp"

using namespace mlir;
class qasm_expression_generator : public qasmBaseVisitor {
    protected:
       OpBuilder& builder;
       ModuleOp m_module;

        std::string indexed_variable_name = "";

        bool builtin_math_func_treat_ints_as_float = false;
        bool casting_indexed_integer_to_bool = false;
        bool found_negation_unary_op = false;
       Value indexed_variable_value;

       Type internal_value_type;


        ScopedSymbolTable& symbol_table;

        static bool is_complex_type(mlir::Value v);

        void update_current_value(mlir::Value v);

        template <typename OpTy, typename... Args>
        OpTy createOp(Args... args) {
          OpTy value = builder.create<OpTy>(args...);
          update_current_value(value);
          return value;
        }

      template <typename AtTy, typename OpTy, typename VTy>
      Value createAttrOpFromVal(VTy val);

    public:
       Value current_value;
       Type complex_type;
       Value last_current_value;

        qasm_expression_generator(mlir::OpBuilder& b, ScopedSymbolTable& table);
        qasm_expression_generator(mlir::OpBuilder& b, ScopedSymbolTable& table, Type t);

    std::any visitExpression(qasmParser::ExpressionContext* ctx) override;

//    std::any visitLogicalAndExpression(qasmParser::LogicalAndExpressionContext *ctx) override;
//
    std::any visitBitOrExpression(qasmParser::BitOrExpressionContext *ctx) override;
//
    std::any visitXOrExpression(qasmParser::XOrExpressionContext *ctx) override;

    std::any visitBitAndExpression(qasmParser::BitAndExpressionContext *ctx) override;
//
    std::any visitEqualityExpression(qasmParser::EqualityExpressionContext *ctx) override;
//
    std::any visitComparisonExpression(qasmParser::ComparisonExpressionContext *ctx) override;
//
//    std::any visitBitShiftExpression(qasmParser::BitShiftExpressionContext *ctx) override;
//
    std::any visitAdditiveExpression(qasmParser::AdditiveExpressionContext *ctx) override;
//
    std::any visitMultiplicativeExpression(qasmParser::MultiplicativeExpressionContext *ctx) override;
//
//    std::any visitUnaryExpression(qasmParser::UnaryExpressionContext *ctx) override;
//
//    std::any visitPowerExpression(qasmParser::PowerExpressionContext *ctx) override;
//
//    std::any visitIndexOperator(qasmParser::IndexOperatorContext *ctx) override;
//
//    std::any visitIndexExpression(qasmParser::IndexExpressionContext *ctx) override;
//
//    std::any visitIndexedIdentifier(qasmParser::IndexedIdentifierContext *ctx) override;

    std::any visitExpressionTerminator(qasmParser::ExpressionTerminatorContext *ctx) override;
    };