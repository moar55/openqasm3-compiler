
// Generated from qasm.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "qasmParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by qasmParser.
 */
class  qasmListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(qasmParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(qasmParser::ProgramContext *ctx) = 0;

  virtual void enterHeader(qasmParser::HeaderContext *ctx) = 0;
  virtual void exitHeader(qasmParser::HeaderContext *ctx) = 0;

  virtual void enterVersion(qasmParser::VersionContext *ctx) = 0;
  virtual void exitVersion(qasmParser::VersionContext *ctx) = 0;

  virtual void enterInclude(qasmParser::IncludeContext *ctx) = 0;
  virtual void exitInclude(qasmParser::IncludeContext *ctx) = 0;

  virtual void enterIoIdentifier(qasmParser::IoIdentifierContext *ctx) = 0;
  virtual void exitIoIdentifier(qasmParser::IoIdentifierContext *ctx) = 0;

  virtual void enterIo(qasmParser::IoContext *ctx) = 0;
  virtual void exitIo(qasmParser::IoContext *ctx) = 0;

  virtual void enterGlobalStatement(qasmParser::GlobalStatementContext *ctx) = 0;
  virtual void exitGlobalStatement(qasmParser::GlobalStatementContext *ctx) = 0;

  virtual void enterStatement(qasmParser::StatementContext *ctx) = 0;
  virtual void exitStatement(qasmParser::StatementContext *ctx) = 0;

  virtual void enterQuantumDeclarationStatement(qasmParser::QuantumDeclarationStatementContext *ctx) = 0;
  virtual void exitQuantumDeclarationStatement(qasmParser::QuantumDeclarationStatementContext *ctx) = 0;

  virtual void enterClassicalDeclarationStatement(qasmParser::ClassicalDeclarationStatementContext *ctx) = 0;
  virtual void exitClassicalDeclarationStatement(qasmParser::ClassicalDeclarationStatementContext *ctx) = 0;

  virtual void enterClassicalAssignment(qasmParser::ClassicalAssignmentContext *ctx) = 0;
  virtual void exitClassicalAssignment(qasmParser::ClassicalAssignmentContext *ctx) = 0;

  virtual void enterAssignmentStatement(qasmParser::AssignmentStatementContext *ctx) = 0;
  virtual void exitAssignmentStatement(qasmParser::AssignmentStatementContext *ctx) = 0;

  virtual void enterReturnSignature(qasmParser::ReturnSignatureContext *ctx) = 0;
  virtual void exitReturnSignature(qasmParser::ReturnSignatureContext *ctx) = 0;

  virtual void enterDesignator(qasmParser::DesignatorContext *ctx) = 0;
  virtual void exitDesignator(qasmParser::DesignatorContext *ctx) = 0;

  virtual void enterIdentifierList(qasmParser::IdentifierListContext *ctx) = 0;
  virtual void exitIdentifierList(qasmParser::IdentifierListContext *ctx) = 0;

  virtual void enterQuantumDeclaration(qasmParser::QuantumDeclarationContext *ctx) = 0;
  virtual void exitQuantumDeclaration(qasmParser::QuantumDeclarationContext *ctx) = 0;

  virtual void enterQuantumArgument(qasmParser::QuantumArgumentContext *ctx) = 0;
  virtual void exitQuantumArgument(qasmParser::QuantumArgumentContext *ctx) = 0;

  virtual void enterQuantumArgumentList(qasmParser::QuantumArgumentListContext *ctx) = 0;
  virtual void exitQuantumArgumentList(qasmParser::QuantumArgumentListContext *ctx) = 0;

  virtual void enterBitType(qasmParser::BitTypeContext *ctx) = 0;
  virtual void exitBitType(qasmParser::BitTypeContext *ctx) = 0;

  virtual void enterSingleDesignatorType(qasmParser::SingleDesignatorTypeContext *ctx) = 0;
  virtual void exitSingleDesignatorType(qasmParser::SingleDesignatorTypeContext *ctx) = 0;

  virtual void enterNoDesignatorType(qasmParser::NoDesignatorTypeContext *ctx) = 0;
  virtual void exitNoDesignatorType(qasmParser::NoDesignatorTypeContext *ctx) = 0;

  virtual void enterNonArrayType(qasmParser::NonArrayTypeContext *ctx) = 0;
  virtual void exitNonArrayType(qasmParser::NonArrayTypeContext *ctx) = 0;

  virtual void enterArrayType(qasmParser::ArrayTypeContext *ctx) = 0;
  virtual void exitArrayType(qasmParser::ArrayTypeContext *ctx) = 0;

  virtual void enterArrayReferenceTypeDimensionSpecifier(qasmParser::ArrayReferenceTypeDimensionSpecifierContext *ctx) = 0;
  virtual void exitArrayReferenceTypeDimensionSpecifier(qasmParser::ArrayReferenceTypeDimensionSpecifierContext *ctx) = 0;

  virtual void enterArrayReferenceType(qasmParser::ArrayReferenceTypeContext *ctx) = 0;
  virtual void exitArrayReferenceType(qasmParser::ArrayReferenceTypeContext *ctx) = 0;

  virtual void enterClassicalType(qasmParser::ClassicalTypeContext *ctx) = 0;
  virtual void exitClassicalType(qasmParser::ClassicalTypeContext *ctx) = 0;

  virtual void enterNumericType(qasmParser::NumericTypeContext *ctx) = 0;
  virtual void exitNumericType(qasmParser::NumericTypeContext *ctx) = 0;

  virtual void enterConstantDeclaration(qasmParser::ConstantDeclarationContext *ctx) = 0;
  virtual void exitConstantDeclaration(qasmParser::ConstantDeclarationContext *ctx) = 0;

  virtual void enterSingleDesignatorDeclaration(qasmParser::SingleDesignatorDeclarationContext *ctx) = 0;
  virtual void exitSingleDesignatorDeclaration(qasmParser::SingleDesignatorDeclarationContext *ctx) = 0;

  virtual void enterNoDesignatorDeclaration(qasmParser::NoDesignatorDeclarationContext *ctx) = 0;
  virtual void exitNoDesignatorDeclaration(qasmParser::NoDesignatorDeclarationContext *ctx) = 0;

  virtual void enterBitDeclaration(qasmParser::BitDeclarationContext *ctx) = 0;
  virtual void exitBitDeclaration(qasmParser::BitDeclarationContext *ctx) = 0;

  virtual void enterComplexDeclaration(qasmParser::ComplexDeclarationContext *ctx) = 0;
  virtual void exitComplexDeclaration(qasmParser::ComplexDeclarationContext *ctx) = 0;

  virtual void enterArrayInitializer(qasmParser::ArrayInitializerContext *ctx) = 0;
  virtual void exitArrayInitializer(qasmParser::ArrayInitializerContext *ctx) = 0;

  virtual void enterArrayDeclaration(qasmParser::ArrayDeclarationContext *ctx) = 0;
  virtual void exitArrayDeclaration(qasmParser::ArrayDeclarationContext *ctx) = 0;

  virtual void enterClassicalDeclaration(qasmParser::ClassicalDeclarationContext *ctx) = 0;
  virtual void exitClassicalDeclaration(qasmParser::ClassicalDeclarationContext *ctx) = 0;

  virtual void enterClassicalTypeList(qasmParser::ClassicalTypeListContext *ctx) = 0;
  virtual void exitClassicalTypeList(qasmParser::ClassicalTypeListContext *ctx) = 0;

  virtual void enterClassicalArgument(qasmParser::ClassicalArgumentContext *ctx) = 0;
  virtual void exitClassicalArgument(qasmParser::ClassicalArgumentContext *ctx) = 0;

  virtual void enterClassicalArgumentList(qasmParser::ClassicalArgumentListContext *ctx) = 0;
  virtual void exitClassicalArgumentList(qasmParser::ClassicalArgumentListContext *ctx) = 0;

  virtual void enterAnyTypeArgument(qasmParser::AnyTypeArgumentContext *ctx) = 0;
  virtual void exitAnyTypeArgument(qasmParser::AnyTypeArgumentContext *ctx) = 0;

  virtual void enterAnyTypeArgumentList(qasmParser::AnyTypeArgumentListContext *ctx) = 0;
  virtual void exitAnyTypeArgumentList(qasmParser::AnyTypeArgumentListContext *ctx) = 0;

  virtual void enterAliasStatement(qasmParser::AliasStatementContext *ctx) = 0;
  virtual void exitAliasStatement(qasmParser::AliasStatementContext *ctx) = 0;

  virtual void enterAliasInitializer(qasmParser::AliasInitializerContext *ctx) = 0;
  virtual void exitAliasInitializer(qasmParser::AliasInitializerContext *ctx) = 0;

  virtual void enterRangeDefinition(qasmParser::RangeDefinitionContext *ctx) = 0;
  virtual void exitRangeDefinition(qasmParser::RangeDefinitionContext *ctx) = 0;

  virtual void enterQuantumGateDefinition(qasmParser::QuantumGateDefinitionContext *ctx) = 0;
  virtual void exitQuantumGateDefinition(qasmParser::QuantumGateDefinitionContext *ctx) = 0;

  virtual void enterQuantumGateSignature(qasmParser::QuantumGateSignatureContext *ctx) = 0;
  virtual void exitQuantumGateSignature(qasmParser::QuantumGateSignatureContext *ctx) = 0;

  virtual void enterQuantumGateName(qasmParser::QuantumGateNameContext *ctx) = 0;
  virtual void exitQuantumGateName(qasmParser::QuantumGateNameContext *ctx) = 0;

  virtual void enterQuantumBlock(qasmParser::QuantumBlockContext *ctx) = 0;
  virtual void exitQuantumBlock(qasmParser::QuantumBlockContext *ctx) = 0;

  virtual void enterQuantumLoop(qasmParser::QuantumLoopContext *ctx) = 0;
  virtual void exitQuantumLoop(qasmParser::QuantumLoopContext *ctx) = 0;

  virtual void enterQuantumLoopBlock(qasmParser::QuantumLoopBlockContext *ctx) = 0;
  virtual void exitQuantumLoopBlock(qasmParser::QuantumLoopBlockContext *ctx) = 0;

  virtual void enterQuantumStatement(qasmParser::QuantumStatementContext *ctx) = 0;
  virtual void exitQuantumStatement(qasmParser::QuantumStatementContext *ctx) = 0;

  virtual void enterQuantumInstruction(qasmParser::QuantumInstructionContext *ctx) = 0;
  virtual void exitQuantumInstruction(qasmParser::QuantumInstructionContext *ctx) = 0;

  virtual void enterQuantumPhase(qasmParser::QuantumPhaseContext *ctx) = 0;
  virtual void exitQuantumPhase(qasmParser::QuantumPhaseContext *ctx) = 0;

  virtual void enterQuantumReset(qasmParser::QuantumResetContext *ctx) = 0;
  virtual void exitQuantumReset(qasmParser::QuantumResetContext *ctx) = 0;

  virtual void enterQuantumMeasurement(qasmParser::QuantumMeasurementContext *ctx) = 0;
  virtual void exitQuantumMeasurement(qasmParser::QuantumMeasurementContext *ctx) = 0;

  virtual void enterQuantumMeasurementAssignment(qasmParser::QuantumMeasurementAssignmentContext *ctx) = 0;
  virtual void exitQuantumMeasurementAssignment(qasmParser::QuantumMeasurementAssignmentContext *ctx) = 0;

  virtual void enterQuantumBarrier(qasmParser::QuantumBarrierContext *ctx) = 0;
  virtual void exitQuantumBarrier(qasmParser::QuantumBarrierContext *ctx) = 0;

  virtual void enterQuantumGateModifier(qasmParser::QuantumGateModifierContext *ctx) = 0;
  virtual void exitQuantumGateModifier(qasmParser::QuantumGateModifierContext *ctx) = 0;

  virtual void enterPowModifier(qasmParser::PowModifierContext *ctx) = 0;
  virtual void exitPowModifier(qasmParser::PowModifierContext *ctx) = 0;

  virtual void enterCtrlModifier(qasmParser::CtrlModifierContext *ctx) = 0;
  virtual void exitCtrlModifier(qasmParser::CtrlModifierContext *ctx) = 0;

  virtual void enterQuantumGateCall(qasmParser::QuantumGateCallContext *ctx) = 0;
  virtual void exitQuantumGateCall(qasmParser::QuantumGateCallContext *ctx) = 0;

  virtual void enterUnaryOperator(qasmParser::UnaryOperatorContext *ctx) = 0;
  virtual void exitUnaryOperator(qasmParser::UnaryOperatorContext *ctx) = 0;

  virtual void enterComparisonOperator(qasmParser::ComparisonOperatorContext *ctx) = 0;
  virtual void exitComparisonOperator(qasmParser::ComparisonOperatorContext *ctx) = 0;

  virtual void enterEqualityOperator(qasmParser::EqualityOperatorContext *ctx) = 0;
  virtual void exitEqualityOperator(qasmParser::EqualityOperatorContext *ctx) = 0;

  virtual void enterLogicalOperator(qasmParser::LogicalOperatorContext *ctx) = 0;
  virtual void exitLogicalOperator(qasmParser::LogicalOperatorContext *ctx) = 0;

  virtual void enterExpressionStatement(qasmParser::ExpressionStatementContext *ctx) = 0;
  virtual void exitExpressionStatement(qasmParser::ExpressionStatementContext *ctx) = 0;

  virtual void enterExpression(qasmParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(qasmParser::ExpressionContext *ctx) = 0;

  virtual void enterLogicalAndExpression(qasmParser::LogicalAndExpressionContext *ctx) = 0;
  virtual void exitLogicalAndExpression(qasmParser::LogicalAndExpressionContext *ctx) = 0;

  virtual void enterBitOrExpression(qasmParser::BitOrExpressionContext *ctx) = 0;
  virtual void exitBitOrExpression(qasmParser::BitOrExpressionContext *ctx) = 0;

  virtual void enterXOrExpression(qasmParser::XOrExpressionContext *ctx) = 0;
  virtual void exitXOrExpression(qasmParser::XOrExpressionContext *ctx) = 0;

  virtual void enterBitAndExpression(qasmParser::BitAndExpressionContext *ctx) = 0;
  virtual void exitBitAndExpression(qasmParser::BitAndExpressionContext *ctx) = 0;

  virtual void enterEqualityExpression(qasmParser::EqualityExpressionContext *ctx) = 0;
  virtual void exitEqualityExpression(qasmParser::EqualityExpressionContext *ctx) = 0;

  virtual void enterComparisonExpression(qasmParser::ComparisonExpressionContext *ctx) = 0;
  virtual void exitComparisonExpression(qasmParser::ComparisonExpressionContext *ctx) = 0;

  virtual void enterBitShiftExpression(qasmParser::BitShiftExpressionContext *ctx) = 0;
  virtual void exitBitShiftExpression(qasmParser::BitShiftExpressionContext *ctx) = 0;

  virtual void enterAdditiveExpression(qasmParser::AdditiveExpressionContext *ctx) = 0;
  virtual void exitAdditiveExpression(qasmParser::AdditiveExpressionContext *ctx) = 0;

  virtual void enterMultiplicativeExpression(qasmParser::MultiplicativeExpressionContext *ctx) = 0;
  virtual void exitMultiplicativeExpression(qasmParser::MultiplicativeExpressionContext *ctx) = 0;

  virtual void enterUnaryExpression(qasmParser::UnaryExpressionContext *ctx) = 0;
  virtual void exitUnaryExpression(qasmParser::UnaryExpressionContext *ctx) = 0;

  virtual void enterPowerExpression(qasmParser::PowerExpressionContext *ctx) = 0;
  virtual void exitPowerExpression(qasmParser::PowerExpressionContext *ctx) = 0;

  virtual void enterIndexOperator(qasmParser::IndexOperatorContext *ctx) = 0;
  virtual void exitIndexOperator(qasmParser::IndexOperatorContext *ctx) = 0;

  virtual void enterIndexExpression(qasmParser::IndexExpressionContext *ctx) = 0;
  virtual void exitIndexExpression(qasmParser::IndexExpressionContext *ctx) = 0;

  virtual void enterIndexedIdentifier(qasmParser::IndexedIdentifierContext *ctx) = 0;
  virtual void exitIndexedIdentifier(qasmParser::IndexedIdentifierContext *ctx) = 0;

  virtual void enterExpressionTerminator(qasmParser::ExpressionTerminatorContext *ctx) = 0;
  virtual void exitExpressionTerminator(qasmParser::ExpressionTerminatorContext *ctx) = 0;

  virtual void enterBooleanLiteral(qasmParser::BooleanLiteralContext *ctx) = 0;
  virtual void exitBooleanLiteral(qasmParser::BooleanLiteralContext *ctx) = 0;

  virtual void enterBuiltInCall(qasmParser::BuiltInCallContext *ctx) = 0;
  virtual void exitBuiltInCall(qasmParser::BuiltInCallContext *ctx) = 0;

  virtual void enterBuiltInMath(qasmParser::BuiltInMathContext *ctx) = 0;
  virtual void exitBuiltInMath(qasmParser::BuiltInMathContext *ctx) = 0;

  virtual void enterCastOperator(qasmParser::CastOperatorContext *ctx) = 0;
  virtual void exitCastOperator(qasmParser::CastOperatorContext *ctx) = 0;

  virtual void enterExpressionList(qasmParser::ExpressionListContext *ctx) = 0;
  virtual void exitExpressionList(qasmParser::ExpressionListContext *ctx) = 0;

  virtual void enterEqualsExpression(qasmParser::EqualsExpressionContext *ctx) = 0;
  virtual void exitEqualsExpression(qasmParser::EqualsExpressionContext *ctx) = 0;

  virtual void enterAssignmentOperator(qasmParser::AssignmentOperatorContext *ctx) = 0;
  virtual void exitAssignmentOperator(qasmParser::AssignmentOperatorContext *ctx) = 0;

  virtual void enterDiscreteSet(qasmParser::DiscreteSetContext *ctx) = 0;
  virtual void exitDiscreteSet(qasmParser::DiscreteSetContext *ctx) = 0;

  virtual void enterSetDeclaration(qasmParser::SetDeclarationContext *ctx) = 0;
  virtual void exitSetDeclaration(qasmParser::SetDeclarationContext *ctx) = 0;

  virtual void enterProgramBlock(qasmParser::ProgramBlockContext *ctx) = 0;
  virtual void exitProgramBlock(qasmParser::ProgramBlockContext *ctx) = 0;

  virtual void enterBranchingStatement(qasmParser::BranchingStatementContext *ctx) = 0;
  virtual void exitBranchingStatement(qasmParser::BranchingStatementContext *ctx) = 0;

  virtual void enterLoopSignature(qasmParser::LoopSignatureContext *ctx) = 0;
  virtual void exitLoopSignature(qasmParser::LoopSignatureContext *ctx) = 0;

  virtual void enterLoopStatement(qasmParser::LoopStatementContext *ctx) = 0;
  virtual void exitLoopStatement(qasmParser::LoopStatementContext *ctx) = 0;

  virtual void enterEndStatement(qasmParser::EndStatementContext *ctx) = 0;
  virtual void exitEndStatement(qasmParser::EndStatementContext *ctx) = 0;

  virtual void enterReturnStatement(qasmParser::ReturnStatementContext *ctx) = 0;
  virtual void exitReturnStatement(qasmParser::ReturnStatementContext *ctx) = 0;

  virtual void enterControlDirective(qasmParser::ControlDirectiveContext *ctx) = 0;
  virtual void exitControlDirective(qasmParser::ControlDirectiveContext *ctx) = 0;

  virtual void enterExternDeclaration(qasmParser::ExternDeclarationContext *ctx) = 0;
  virtual void exitExternDeclaration(qasmParser::ExternDeclarationContext *ctx) = 0;

  virtual void enterExternOrSubroutineCall(qasmParser::ExternOrSubroutineCallContext *ctx) = 0;
  virtual void exitExternOrSubroutineCall(qasmParser::ExternOrSubroutineCallContext *ctx) = 0;

  virtual void enterSubroutineDefinition(qasmParser::SubroutineDefinitionContext *ctx) = 0;
  virtual void exitSubroutineDefinition(qasmParser::SubroutineDefinitionContext *ctx) = 0;

  virtual void enterSubroutineBlock(qasmParser::SubroutineBlockContext *ctx) = 0;
  virtual void exitSubroutineBlock(qasmParser::SubroutineBlockContext *ctx) = 0;

  virtual void enterPragma(qasmParser::PragmaContext *ctx) = 0;
  virtual void exitPragma(qasmParser::PragmaContext *ctx) = 0;

  virtual void enterTimingType(qasmParser::TimingTypeContext *ctx) = 0;
  virtual void exitTimingType(qasmParser::TimingTypeContext *ctx) = 0;

  virtual void enterTimingBox(qasmParser::TimingBoxContext *ctx) = 0;
  virtual void exitTimingBox(qasmParser::TimingBoxContext *ctx) = 0;

  virtual void enterTimingIdentifier(qasmParser::TimingIdentifierContext *ctx) = 0;
  virtual void exitTimingIdentifier(qasmParser::TimingIdentifierContext *ctx) = 0;

  virtual void enterTimingInstructionName(qasmParser::TimingInstructionNameContext *ctx) = 0;
  virtual void exitTimingInstructionName(qasmParser::TimingInstructionNameContext *ctx) = 0;

  virtual void enterTimingInstruction(qasmParser::TimingInstructionContext *ctx) = 0;
  virtual void exitTimingInstruction(qasmParser::TimingInstructionContext *ctx) = 0;

  virtual void enterTimingStatement(qasmParser::TimingStatementContext *ctx) = 0;
  virtual void exitTimingStatement(qasmParser::TimingStatementContext *ctx) = 0;

  virtual void enterCalibration(qasmParser::CalibrationContext *ctx) = 0;
  virtual void exitCalibration(qasmParser::CalibrationContext *ctx) = 0;

  virtual void enterCalibrationGrammarDeclaration(qasmParser::CalibrationGrammarDeclarationContext *ctx) = 0;
  virtual void exitCalibrationGrammarDeclaration(qasmParser::CalibrationGrammarDeclarationContext *ctx) = 0;

  virtual void enterCalibrationDefinition(qasmParser::CalibrationDefinitionContext *ctx) = 0;
  virtual void exitCalibrationDefinition(qasmParser::CalibrationDefinitionContext *ctx) = 0;

  virtual void enterCalibrationGrammar(qasmParser::CalibrationGrammarContext *ctx) = 0;
  virtual void exitCalibrationGrammar(qasmParser::CalibrationGrammarContext *ctx) = 0;

  virtual void enterCalibrationArgumentList(qasmParser::CalibrationArgumentListContext *ctx) = 0;
  virtual void exitCalibrationArgumentList(qasmParser::CalibrationArgumentListContext *ctx) = 0;


};

