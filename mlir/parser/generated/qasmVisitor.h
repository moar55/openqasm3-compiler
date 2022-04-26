
// Generated from qasm.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "qasmParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by qasmParser.
 */
  class qasmVisitor : public antlr4::tree::AbstractParseTreeVisitor {
    public:

        /**
         * Visit parse trees produced by qasmParser.
         */
        virtual antlrcpp::Any visitProgram(qasmParser::ProgramContext *context) = 0;

        virtual antlrcpp::Any visitHeader(qasmParser::HeaderContext *context) = 0;

        virtual antlrcpp::Any visitVersion(qasmParser::VersionContext *context) = 0;

        virtual antlrcpp::Any visitInclude(qasmParser::IncludeContext *context) = 0;

        virtual antlrcpp::Any visitIoIdentifier(qasmParser::IoIdentifierContext *context) = 0;

        virtual antlrcpp::Any visitIo(qasmParser::IoContext *context) = 0;

        virtual antlrcpp::Any visitGlobalStatement(qasmParser::GlobalStatementContext *context) = 0;

        virtual antlrcpp::Any visitStatement(qasmParser::StatementContext *context) = 0;

        virtual antlrcpp::Any
        visitQuantumDeclarationStatement(qasmParser::QuantumDeclarationStatementContext *context) = 0;

        virtual antlrcpp::Any
        visitClassicalDeclarationStatement(qasmParser::ClassicalDeclarationStatementContext *context) = 0;

        virtual antlrcpp::Any visitClassicalAssignment(qasmParser::ClassicalAssignmentContext *context) = 0;

        virtual antlrcpp::Any visitAssignmentStatement(qasmParser::AssignmentStatementContext *context) = 0;

        virtual antlrcpp::Any visitReturnSignature(qasmParser::ReturnSignatureContext *context) = 0;

        virtual antlrcpp::Any visitDesignator(qasmParser::DesignatorContext *context) = 0;

        virtual antlrcpp::Any visitIdentifierList(qasmParser::IdentifierListContext *context) = 0;

        virtual antlrcpp::Any visitQuantumDeclaration(qasmParser::QuantumDeclarationContext *context) = 0;

        virtual antlrcpp::Any visitQuantumArgument(qasmParser::QuantumArgumentContext *context) = 0;

        virtual antlrcpp::Any visitQuantumArgumentList(qasmParser::QuantumArgumentListContext *context) = 0;

        virtual antlrcpp::Any visitBitType(qasmParser::BitTypeContext *context) = 0;

        virtual antlrcpp::Any visitSingleDesignatorType(qasmParser::SingleDesignatorTypeContext *context) = 0;

        virtual antlrcpp::Any visitNoDesignatorType(qasmParser::NoDesignatorTypeContext *context) = 0;

        virtual antlrcpp::Any visitNonArrayType(qasmParser::NonArrayTypeContext *context) = 0;

        virtual antlrcpp::Any visitArrayType(qasmParser::ArrayTypeContext *context) = 0;

        virtual antlrcpp::Any
        visitArrayReferenceTypeDimensionSpecifier(qasmParser::ArrayReferenceTypeDimensionSpecifierContext *context) = 0;

        virtual antlrcpp::Any visitArrayReferenceType(qasmParser::ArrayReferenceTypeContext *context) = 0;

        virtual antlrcpp::Any visitClassicalType(qasmParser::ClassicalTypeContext *context) = 0;

        virtual antlrcpp::Any visitNumericType(qasmParser::NumericTypeContext *context) = 0;

        virtual antlrcpp::Any visitConstantDeclaration(qasmParser::ConstantDeclarationContext *context) = 0;

        virtual antlrcpp::Any
        visitSingleDesignatorDeclaration(qasmParser::SingleDesignatorDeclarationContext *context) = 0;

        virtual antlrcpp::Any visitNoDesignatorDeclaration(qasmParser::NoDesignatorDeclarationContext *context) = 0;

        virtual antlrcpp::Any visitBitDeclaration(qasmParser::BitDeclarationContext *context) = 0;

        virtual antlrcpp::Any visitComplexDeclaration(qasmParser::ComplexDeclarationContext *context) = 0;

        virtual antlrcpp::Any visitArrayInitializer(qasmParser::ArrayInitializerContext *context) = 0;

        virtual antlrcpp::Any visitArrayDeclaration(qasmParser::ArrayDeclarationContext *context) = 0;

        virtual antlrcpp::Any visitClassicalDeclaration(qasmParser::ClassicalDeclarationContext *context) = 0;

        virtual antlrcpp::Any visitClassicalTypeList(qasmParser::ClassicalTypeListContext *context) = 0;

        virtual antlrcpp::Any visitClassicalArgument(qasmParser::ClassicalArgumentContext *context) = 0;

        virtual antlrcpp::Any visitClassicalArgumentList(qasmParser::ClassicalArgumentListContext *context) = 0;

        virtual antlrcpp::Any visitAnyTypeArgument(qasmParser::AnyTypeArgumentContext *context) = 0;

        virtual antlrcpp::Any visitAnyTypeArgumentList(qasmParser::AnyTypeArgumentListContext *context) = 0;

        virtual antlrcpp::Any visitAliasStatement(qasmParser::AliasStatementContext *context) = 0;

        virtual antlrcpp::Any visitAliasInitializer(qasmParser::AliasInitializerContext *context) = 0;

        virtual antlrcpp::Any visitRangeDefinition(qasmParser::RangeDefinitionContext *context) = 0;

        virtual antlrcpp::Any visitQuantumGateDefinition(qasmParser::QuantumGateDefinitionContext *context) = 0;

        virtual antlrcpp::Any visitQuantumGateSignature(qasmParser::QuantumGateSignatureContext *context) = 0;

        virtual antlrcpp::Any visitQuantumGateName(qasmParser::QuantumGateNameContext *context) = 0;

        virtual antlrcpp::Any visitQuantumBlock(qasmParser::QuantumBlockContext *context) = 0;

        virtual antlrcpp::Any visitQuantumLoop(qasmParser::QuantumLoopContext *context) = 0;

        virtual antlrcpp::Any visitQuantumLoopBlock(qasmParser::QuantumLoopBlockContext *context) = 0;

        virtual antlrcpp::Any visitQuantumStatement(qasmParser::QuantumStatementContext *context) = 0;

        virtual antlrcpp::Any visitQuantumInstruction(qasmParser::QuantumInstructionContext *context) = 0;

        virtual antlrcpp::Any visitQuantumPhase(qasmParser::QuantumPhaseContext *context) = 0;

        virtual antlrcpp::Any visitQuantumReset(qasmParser::QuantumResetContext *context) = 0;

        virtual antlrcpp::Any visitQuantumMeasurement(qasmParser::QuantumMeasurementContext *context) = 0;

        virtual antlrcpp::Any
        visitQuantumMeasurementAssignment(qasmParser::QuantumMeasurementAssignmentContext *context) = 0;

        virtual antlrcpp::Any visitQuantumBarrier(qasmParser::QuantumBarrierContext *context) = 0;

        virtual antlrcpp::Any visitQuantumGateModifier(qasmParser::QuantumGateModifierContext *context) = 0;

        virtual antlrcpp::Any visitPowModifier(qasmParser::PowModifierContext *context) = 0;

        virtual antlrcpp::Any visitCtrlModifier(qasmParser::CtrlModifierContext *context) = 0;

        virtual antlrcpp::Any visitQuantumGateCall(qasmParser::QuantumGateCallContext *context) = 0;

        virtual antlrcpp::Any visitUnaryOperator(qasmParser::UnaryOperatorContext *context) = 0;

        virtual antlrcpp::Any visitComparisonOperator(qasmParser::ComparisonOperatorContext *context) = 0;

        virtual antlrcpp::Any visitEqualityOperator(qasmParser::EqualityOperatorContext *context) = 0;

        virtual antlrcpp::Any visitLogicalOperator(qasmParser::LogicalOperatorContext *context) = 0;

        virtual antlrcpp::Any visitExpressionStatement(qasmParser::ExpressionStatementContext *context) = 0;

        virtual antlrcpp::Any visitExpression(qasmParser::ExpressionContext *context) = 0;

        virtual antlrcpp::Any visitLogicalAndExpression(qasmParser::LogicalAndExpressionContext *context) = 0;

        virtual antlrcpp::Any visitBitOrExpression(qasmParser::BitOrExpressionContext *context) = 0;

        virtual antlrcpp::Any visitXOrExpression(qasmParser::XOrExpressionContext *context) = 0;

        virtual antlrcpp::Any visitBitAndExpression(qasmParser::BitAndExpressionContext *context) = 0;

        virtual antlrcpp::Any visitEqualityExpression(qasmParser::EqualityExpressionContext *context) = 0;

        virtual antlrcpp::Any visitComparisonExpression(qasmParser::ComparisonExpressionContext *context) = 0;

        virtual antlrcpp::Any visitBitShiftExpression(qasmParser::BitShiftExpressionContext *context) = 0;

        virtual antlrcpp::Any visitAdditiveExpression(qasmParser::AdditiveExpressionContext *context) = 0;

        virtual antlrcpp::Any visitMultiplicativeExpression(qasmParser::MultiplicativeExpressionContext *context) = 0;

        virtual antlrcpp::Any visitUnaryExpression(qasmParser::UnaryExpressionContext *context) = 0;

        virtual antlrcpp::Any visitPowerExpression(qasmParser::PowerExpressionContext *context) = 0;

        virtual antlrcpp::Any visitIndexOperator(qasmParser::IndexOperatorContext *context) = 0;

        virtual antlrcpp::Any visitIndexExpression(qasmParser::IndexExpressionContext *context) = 0;

        virtual antlrcpp::Any visitIndexedIdentifier(qasmParser::IndexedIdentifierContext *context) = 0;

        virtual antlrcpp::Any visitExpressionTerminator(qasmParser::ExpressionTerminatorContext *context) = 0;

        virtual antlrcpp::Any visitBooleanLiteral(qasmParser::BooleanLiteralContext *context) = 0;

        virtual antlrcpp::Any visitBuiltInCall(qasmParser::BuiltInCallContext *context) = 0;

        virtual antlrcpp::Any visitBuiltInMath(qasmParser::BuiltInMathContext *context) = 0;

        virtual antlrcpp::Any visitCastOperator(qasmParser::CastOperatorContext *context) = 0;

        virtual antlrcpp::Any visitExpressionList(qasmParser::ExpressionListContext *context) = 0;

        virtual antlrcpp::Any visitEqualsExpression(qasmParser::EqualsExpressionContext *context) = 0;

        virtual antlrcpp::Any visitAssignmentOperator(qasmParser::AssignmentOperatorContext *context) = 0;

        virtual antlrcpp::Any visitDiscreteSet(qasmParser::DiscreteSetContext *context) = 0;

        virtual antlrcpp::Any visitSetDeclaration(qasmParser::SetDeclarationContext *context) = 0;

        virtual antlrcpp::Any visitProgramBlock(qasmParser::ProgramBlockContext *context) = 0;

        virtual antlrcpp::Any visitBranchingStatement(qasmParser::BranchingStatementContext *context) = 0;

        virtual antlrcpp::Any visitLoopSignature(qasmParser::LoopSignatureContext *context) = 0;

        virtual antlrcpp::Any visitLoopStatement(qasmParser::LoopStatementContext *context) = 0;

        virtual antlrcpp::Any visitEndStatement(qasmParser::EndStatementContext *context) = 0;

        virtual antlrcpp::Any visitReturnStatement(qasmParser::ReturnStatementContext *context) = 0;

        virtual antlrcpp::Any visitControlDirective(qasmParser::ControlDirectiveContext *context) = 0;

        virtual antlrcpp::Any visitExternDeclaration(qasmParser::ExternDeclarationContext *context) = 0;

        virtual antlrcpp::Any visitExternOrSubroutineCall(qasmParser::ExternOrSubroutineCallContext *context) = 0;

        virtual antlrcpp::Any visitSubroutineDefinition(qasmParser::SubroutineDefinitionContext *context) = 0;

        virtual antlrcpp::Any visitSubroutineBlock(qasmParser::SubroutineBlockContext *context) = 0;

        virtual antlrcpp::Any visitPragma(qasmParser::PragmaContext *context) = 0;

        virtual antlrcpp::Any visitTimingType(qasmParser::TimingTypeContext *context) = 0;

        virtual antlrcpp::Any visitTimingBox(qasmParser::TimingBoxContext *context) = 0;

        virtual antlrcpp::Any visitTimingIdentifier(qasmParser::TimingIdentifierContext *context) = 0;

        virtual antlrcpp::Any visitTimingInstructionName(qasmParser::TimingInstructionNameContext *context) = 0;

        virtual antlrcpp::Any visitTimingInstruction(qasmParser::TimingInstructionContext *context) = 0;

        virtual antlrcpp::Any visitTimingStatement(qasmParser::TimingStatementContext *context) = 0;

        virtual antlrcpp::Any visitCalibration(qasmParser::CalibrationContext *context) = 0;

        virtual antlrcpp::Any
        visitCalibrationGrammarDeclaration(qasmParser::CalibrationGrammarDeclarationContext *context) = 0;

        virtual antlrcpp::Any visitCalibrationDefinition(qasmParser::CalibrationDefinitionContext *context) = 0;

        virtual antlrcpp::Any visitCalibrationGrammar(qasmParser::CalibrationGrammarContext *context) = 0;

        virtual antlrcpp::Any visitCalibrationArgumentList(qasmParser::CalibrationArgumentListContext *context) = 0;


  };
