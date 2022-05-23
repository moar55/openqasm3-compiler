
// Generated from qasm.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "qasmParser.h"


namespace mlir {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by qasmParser.
 */
class  qasmVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by qasmParser.
   */
    virtual std::any visitProgram(qasmParser::ProgramContext *context) = 0;

    virtual std::any visitHeader(qasmParser::HeaderContext *context) = 0;

    virtual std::any visitVersion(qasmParser::VersionContext *context) = 0;

    virtual std::any visitInclude(qasmParser::IncludeContext *context) = 0;

    virtual std::any visitIoIdentifier(qasmParser::IoIdentifierContext *context) = 0;

    virtual std::any visitIo(qasmParser::IoContext *context) = 0;

    virtual std::any visitGlobalStatement(qasmParser::GlobalStatementContext *context) = 0;

    virtual std::any visitStatement(qasmParser::StatementContext *context) = 0;

    virtual std::any visitQuantumDeclarationStatement(qasmParser::QuantumDeclarationStatementContext *context) = 0;

    virtual std::any visitClassicalDeclarationStatement(qasmParser::ClassicalDeclarationStatementContext *context) = 0;

    virtual std::any visitClassicalAssignment(qasmParser::ClassicalAssignmentContext *context) = 0;

    virtual std::any visitAssignmentStatement(qasmParser::AssignmentStatementContext *context) = 0;

    virtual std::any visitReturnSignature(qasmParser::ReturnSignatureContext *context) = 0;

    virtual std::any visitDesignator(qasmParser::DesignatorContext *context) = 0;

    virtual std::any visitIdentifierList(qasmParser::IdentifierListContext *context) = 0;

    virtual std::any visitQuantumDeclaration(qasmParser::QuantumDeclarationContext *context) = 0;

    virtual std::any visitQuantumArgument(qasmParser::QuantumArgumentContext *context) = 0;

    virtual std::any visitQuantumArgumentList(qasmParser::QuantumArgumentListContext *context) = 0;

    virtual std::any visitBitType(qasmParser::BitTypeContext *context) = 0;

    virtual std::any visitSingleDesignatorType(qasmParser::SingleDesignatorTypeContext *context) = 0;

    virtual std::any visitNoDesignatorType(qasmParser::NoDesignatorTypeContext *context) = 0;

    virtual std::any visitNonArrayType(qasmParser::NonArrayTypeContext *context) = 0;

    virtual std::any visitArrayType(qasmParser::ArrayTypeContext *context) = 0;

    virtual std::any visitArrayReferenceTypeDimensionSpecifier(qasmParser::ArrayReferenceTypeDimensionSpecifierContext *context) = 0;

    virtual std::any visitArrayReferenceType(qasmParser::ArrayReferenceTypeContext *context) = 0;

    virtual std::any visitClassicalType(qasmParser::ClassicalTypeContext *context) = 0;

    virtual std::any visitNumericType(qasmParser::NumericTypeContext *context) = 0;

    virtual std::any visitConstantDeclaration(qasmParser::ConstantDeclarationContext *context) = 0;

    virtual std::any visitSingleDesignatorDeclaration(qasmParser::SingleDesignatorDeclarationContext *context) = 0;

    virtual std::any visitNoDesignatorDeclaration(qasmParser::NoDesignatorDeclarationContext *context) = 0;

    virtual std::any visitBitDeclaration(qasmParser::BitDeclarationContext *context) = 0;

    virtual std::any visitComplexDeclaration(qasmParser::ComplexDeclarationContext *context) = 0;

    virtual std::any visitArrayInitializer(qasmParser::ArrayInitializerContext *context) = 0;

    virtual std::any visitArrayDeclaration(qasmParser::ArrayDeclarationContext *context) = 0;

    virtual std::any visitClassicalDeclaration(qasmParser::ClassicalDeclarationContext *context) = 0;

    virtual std::any visitClassicalTypeList(qasmParser::ClassicalTypeListContext *context) = 0;

    virtual std::any visitClassicalArgument(qasmParser::ClassicalArgumentContext *context) = 0;

    virtual std::any visitClassicalArgumentList(qasmParser::ClassicalArgumentListContext *context) = 0;

    virtual std::any visitAnyTypeArgument(qasmParser::AnyTypeArgumentContext *context) = 0;

    virtual std::any visitAnyTypeArgumentList(qasmParser::AnyTypeArgumentListContext *context) = 0;

    virtual std::any visitAliasStatement(qasmParser::AliasStatementContext *context) = 0;

    virtual std::any visitAliasInitializer(qasmParser::AliasInitializerContext *context) = 0;

    virtual std::any visitRangeDefinition(qasmParser::RangeDefinitionContext *context) = 0;

    virtual std::any visitQuantumGateDefinition(qasmParser::QuantumGateDefinitionContext *context) = 0;

    virtual std::any visitQuantumGateSignature(qasmParser::QuantumGateSignatureContext *context) = 0;

    virtual std::any visitQuantumGateName(qasmParser::QuantumGateNameContext *context) = 0;

    virtual std::any visitQuantumBlock(qasmParser::QuantumBlockContext *context) = 0;

    virtual std::any visitQuantumLoop(qasmParser::QuantumLoopContext *context) = 0;

    virtual std::any visitQuantumLoopBlock(qasmParser::QuantumLoopBlockContext *context) = 0;

    virtual std::any visitQuantumStatement(qasmParser::QuantumStatementContext *context) = 0;

    virtual std::any visitQuantumInstruction(qasmParser::QuantumInstructionContext *context) = 0;

    virtual std::any visitQuantumPhase(qasmParser::QuantumPhaseContext *context) = 0;

    virtual std::any visitQuantumReset(qasmParser::QuantumResetContext *context) = 0;

    virtual std::any visitQuantumMeasurement(qasmParser::QuantumMeasurementContext *context) = 0;

    virtual std::any visitQuantumMeasurementAssignment(qasmParser::QuantumMeasurementAssignmentContext *context) = 0;

    virtual std::any visitQuantumBarrier(qasmParser::QuantumBarrierContext *context) = 0;

    virtual std::any visitQuantumGateModifier(qasmParser::QuantumGateModifierContext *context) = 0;

    virtual std::any visitPowModifier(qasmParser::PowModifierContext *context) = 0;

    virtual std::any visitCtrlModifier(qasmParser::CtrlModifierContext *context) = 0;

    virtual std::any visitQuantumGateCall(qasmParser::QuantumGateCallContext *context) = 0;

    virtual std::any visitUnaryOperator(qasmParser::UnaryOperatorContext *context) = 0;

    virtual std::any visitComparisonOperator(qasmParser::ComparisonOperatorContext *context) = 0;

    virtual std::any visitEqualityOperator(qasmParser::EqualityOperatorContext *context) = 0;

    virtual std::any visitLogicalOperator(qasmParser::LogicalOperatorContext *context) = 0;

    virtual std::any visitExpressionStatement(qasmParser::ExpressionStatementContext *context) = 0;

    virtual std::any visitExpression(qasmParser::ExpressionContext *context) = 0;

    virtual std::any visitLogicalAndExpression(qasmParser::LogicalAndExpressionContext *context) = 0;

    virtual std::any visitBitOrExpression(qasmParser::BitOrExpressionContext *context) = 0;

    virtual std::any visitXOrExpression(qasmParser::XOrExpressionContext *context) = 0;

    virtual std::any visitBitAndExpression(qasmParser::BitAndExpressionContext *context) = 0;

    virtual std::any visitEqualityExpression(qasmParser::EqualityExpressionContext *context) = 0;

    virtual std::any visitComparisonExpression(qasmParser::ComparisonExpressionContext *context) = 0;

    virtual std::any visitBitShiftExpression(qasmParser::BitShiftExpressionContext *context) = 0;

    virtual std::any visitAdditiveExpression(qasmParser::AdditiveExpressionContext *context) = 0;

    virtual std::any visitMultiplicativeExpression(qasmParser::MultiplicativeExpressionContext *context) = 0;

    virtual std::any visitUnaryExpression(qasmParser::UnaryExpressionContext *context) = 0;

    virtual std::any visitPowerExpression(qasmParser::PowerExpressionContext *context) = 0;

    virtual std::any visitIndexOperator(qasmParser::IndexOperatorContext *context) = 0;

    virtual std::any visitIndexExpression(qasmParser::IndexExpressionContext *context) = 0;

    virtual std::any visitIndexedIdentifier(qasmParser::IndexedIdentifierContext *context) = 0;

    virtual std::any visitExpressionTerminator(qasmParser::ExpressionTerminatorContext *context) = 0;

    virtual std::any visitBooleanLiteral(qasmParser::BooleanLiteralContext *context) = 0;

    virtual std::any visitBuiltInCall(qasmParser::BuiltInCallContext *context) = 0;

    virtual std::any visitBuiltInMath(qasmParser::BuiltInMathContext *context) = 0;

    virtual std::any visitCastOperator(qasmParser::CastOperatorContext *context) = 0;

    virtual std::any visitExpressionList(qasmParser::ExpressionListContext *context) = 0;

    virtual std::any visitEqualsExpression(qasmParser::EqualsExpressionContext *context) = 0;

    virtual std::any visitAssignmentOperator(qasmParser::AssignmentOperatorContext *context) = 0;

    virtual std::any visitDiscreteSet(qasmParser::DiscreteSetContext *context) = 0;

    virtual std::any visitSetDeclaration(qasmParser::SetDeclarationContext *context) = 0;

    virtual std::any visitProgramBlock(qasmParser::ProgramBlockContext *context) = 0;

    virtual std::any visitBranchingStatement(qasmParser::BranchingStatementContext *context) = 0;

    virtual std::any visitLoopSignature(qasmParser::LoopSignatureContext *context) = 0;

    virtual std::any visitLoopStatement(qasmParser::LoopStatementContext *context) = 0;

    virtual std::any visitEndStatement(qasmParser::EndStatementContext *context) = 0;

    virtual std::any visitReturnStatement(qasmParser::ReturnStatementContext *context) = 0;

    virtual std::any visitControlDirective(qasmParser::ControlDirectiveContext *context) = 0;

    virtual std::any visitExternDeclaration(qasmParser::ExternDeclarationContext *context) = 0;

    virtual std::any visitExternOrSubroutineCall(qasmParser::ExternOrSubroutineCallContext *context) = 0;

    virtual std::any visitSubroutineDefinition(qasmParser::SubroutineDefinitionContext *context) = 0;

    virtual std::any visitSubroutineBlock(qasmParser::SubroutineBlockContext *context) = 0;

    virtual std::any visitPragma(qasmParser::PragmaContext *context) = 0;

    virtual std::any visitTimingType(qasmParser::TimingTypeContext *context) = 0;

    virtual std::any visitTimingBox(qasmParser::TimingBoxContext *context) = 0;

    virtual std::any visitTimingIdentifier(qasmParser::TimingIdentifierContext *context) = 0;

    virtual std::any visitTimingInstructionName(qasmParser::TimingInstructionNameContext *context) = 0;

    virtual std::any visitTimingInstruction(qasmParser::TimingInstructionContext *context) = 0;

    virtual std::any visitTimingStatement(qasmParser::TimingStatementContext *context) = 0;

    virtual std::any visitCalibration(qasmParser::CalibrationContext *context) = 0;

    virtual std::any visitCalibrationGrammarDeclaration(qasmParser::CalibrationGrammarDeclarationContext *context) = 0;

    virtual std::any visitCalibrationDefinition(qasmParser::CalibrationDefinitionContext *context) = 0;

    virtual std::any visitCalibrationGrammar(qasmParser::CalibrationGrammarContext *context) = 0;

    virtual std::any visitCalibrationArgumentList(qasmParser::CalibrationArgumentListContext *context) = 0;


};

}  // namespace mlir
