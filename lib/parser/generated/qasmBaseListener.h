
// Generated from qasm.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "qasmListener.h"


namespace mlir {

/**
 * This class provides an empty implementation of qasmListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  qasmBaseListener : public qasmListener {
public:

  virtual void enterProgram(qasmParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(qasmParser::ProgramContext * /*ctx*/) override { }

  virtual void enterHeader(qasmParser::HeaderContext * /*ctx*/) override { }
  virtual void exitHeader(qasmParser::HeaderContext * /*ctx*/) override { }

  virtual void enterVersion(qasmParser::VersionContext * /*ctx*/) override { }
  virtual void exitVersion(qasmParser::VersionContext * /*ctx*/) override { }

  virtual void enterInclude(qasmParser::IncludeContext * /*ctx*/) override { }
  virtual void exitInclude(qasmParser::IncludeContext * /*ctx*/) override { }

  virtual void enterIoIdentifier(qasmParser::IoIdentifierContext * /*ctx*/) override { }
  virtual void exitIoIdentifier(qasmParser::IoIdentifierContext * /*ctx*/) override { }

  virtual void enterIo(qasmParser::IoContext * /*ctx*/) override { }
  virtual void exitIo(qasmParser::IoContext * /*ctx*/) override { }

  virtual void enterGlobalStatement(qasmParser::GlobalStatementContext * /*ctx*/) override { }
  virtual void exitGlobalStatement(qasmParser::GlobalStatementContext * /*ctx*/) override { }

  virtual void enterStatement(qasmParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(qasmParser::StatementContext * /*ctx*/) override { }

  virtual void enterQuantumDeclarationStatement(qasmParser::QuantumDeclarationStatementContext * /*ctx*/) override { }
  virtual void exitQuantumDeclarationStatement(qasmParser::QuantumDeclarationStatementContext * /*ctx*/) override { }

  virtual void enterClassicalDeclarationStatement(qasmParser::ClassicalDeclarationStatementContext * /*ctx*/) override { }
  virtual void exitClassicalDeclarationStatement(qasmParser::ClassicalDeclarationStatementContext * /*ctx*/) override { }

  virtual void enterClassicalAssignment(qasmParser::ClassicalAssignmentContext * /*ctx*/) override { }
  virtual void exitClassicalAssignment(qasmParser::ClassicalAssignmentContext * /*ctx*/) override { }

  virtual void enterAssignmentStatement(qasmParser::AssignmentStatementContext * /*ctx*/) override { }
  virtual void exitAssignmentStatement(qasmParser::AssignmentStatementContext * /*ctx*/) override { }

  virtual void enterReturnSignature(qasmParser::ReturnSignatureContext * /*ctx*/) override { }
  virtual void exitReturnSignature(qasmParser::ReturnSignatureContext * /*ctx*/) override { }

  virtual void enterDesignator(qasmParser::DesignatorContext * /*ctx*/) override { }
  virtual void exitDesignator(qasmParser::DesignatorContext * /*ctx*/) override { }

  virtual void enterIdentifierList(qasmParser::IdentifierListContext * /*ctx*/) override { }
  virtual void exitIdentifierList(qasmParser::IdentifierListContext * /*ctx*/) override { }

  virtual void enterQuantumDeclaration(qasmParser::QuantumDeclarationContext * /*ctx*/) override { }
  virtual void exitQuantumDeclaration(qasmParser::QuantumDeclarationContext * /*ctx*/) override { }

  virtual void enterQuantumArgument(qasmParser::QuantumArgumentContext * /*ctx*/) override { }
  virtual void exitQuantumArgument(qasmParser::QuantumArgumentContext * /*ctx*/) override { }

  virtual void enterQuantumArgumentList(qasmParser::QuantumArgumentListContext * /*ctx*/) override { }
  virtual void exitQuantumArgumentList(qasmParser::QuantumArgumentListContext * /*ctx*/) override { }

  virtual void enterBitType(qasmParser::BitTypeContext * /*ctx*/) override { }
  virtual void exitBitType(qasmParser::BitTypeContext * /*ctx*/) override { }

  virtual void enterSingleDesignatorType(qasmParser::SingleDesignatorTypeContext * /*ctx*/) override { }
  virtual void exitSingleDesignatorType(qasmParser::SingleDesignatorTypeContext * /*ctx*/) override { }

  virtual void enterNoDesignatorType(qasmParser::NoDesignatorTypeContext * /*ctx*/) override { }
  virtual void exitNoDesignatorType(qasmParser::NoDesignatorTypeContext * /*ctx*/) override { }

  virtual void enterNonArrayType(qasmParser::NonArrayTypeContext * /*ctx*/) override { }
  virtual void exitNonArrayType(qasmParser::NonArrayTypeContext * /*ctx*/) override { }

  virtual void enterArrayType(qasmParser::ArrayTypeContext * /*ctx*/) override { }
  virtual void exitArrayType(qasmParser::ArrayTypeContext * /*ctx*/) override { }

  virtual void enterArrayReferenceTypeDimensionSpecifier(qasmParser::ArrayReferenceTypeDimensionSpecifierContext * /*ctx*/) override { }
  virtual void exitArrayReferenceTypeDimensionSpecifier(qasmParser::ArrayReferenceTypeDimensionSpecifierContext * /*ctx*/) override { }

  virtual void enterArrayReferenceType(qasmParser::ArrayReferenceTypeContext * /*ctx*/) override { }
  virtual void exitArrayReferenceType(qasmParser::ArrayReferenceTypeContext * /*ctx*/) override { }

  virtual void enterClassicalType(qasmParser::ClassicalTypeContext * /*ctx*/) override { }
  virtual void exitClassicalType(qasmParser::ClassicalTypeContext * /*ctx*/) override { }

  virtual void enterNumericType(qasmParser::NumericTypeContext * /*ctx*/) override { }
  virtual void exitNumericType(qasmParser::NumericTypeContext * /*ctx*/) override { }

  virtual void enterConstantDeclaration(qasmParser::ConstantDeclarationContext * /*ctx*/) override { }
  virtual void exitConstantDeclaration(qasmParser::ConstantDeclarationContext * /*ctx*/) override { }

  virtual void enterSingleDesignatorDeclaration(qasmParser::SingleDesignatorDeclarationContext * /*ctx*/) override { }
  virtual void exitSingleDesignatorDeclaration(qasmParser::SingleDesignatorDeclarationContext * /*ctx*/) override { }

  virtual void enterNoDesignatorDeclaration(qasmParser::NoDesignatorDeclarationContext * /*ctx*/) override { }
  virtual void exitNoDesignatorDeclaration(qasmParser::NoDesignatorDeclarationContext * /*ctx*/) override { }

  virtual void enterBitDeclaration(qasmParser::BitDeclarationContext * /*ctx*/) override { }
  virtual void exitBitDeclaration(qasmParser::BitDeclarationContext * /*ctx*/) override { }

  virtual void enterComplexDeclaration(qasmParser::ComplexDeclarationContext * /*ctx*/) override { }
  virtual void exitComplexDeclaration(qasmParser::ComplexDeclarationContext * /*ctx*/) override { }

  virtual void enterArrayInitializer(qasmParser::ArrayInitializerContext * /*ctx*/) override { }
  virtual void exitArrayInitializer(qasmParser::ArrayInitializerContext * /*ctx*/) override { }

  virtual void enterArrayDeclaration(qasmParser::ArrayDeclarationContext * /*ctx*/) override { }
  virtual void exitArrayDeclaration(qasmParser::ArrayDeclarationContext * /*ctx*/) override { }

  virtual void enterClassicalDeclaration(qasmParser::ClassicalDeclarationContext * /*ctx*/) override { }
  virtual void exitClassicalDeclaration(qasmParser::ClassicalDeclarationContext * /*ctx*/) override { }

  virtual void enterClassicalTypeList(qasmParser::ClassicalTypeListContext * /*ctx*/) override { }
  virtual void exitClassicalTypeList(qasmParser::ClassicalTypeListContext * /*ctx*/) override { }

  virtual void enterClassicalArgument(qasmParser::ClassicalArgumentContext * /*ctx*/) override { }
  virtual void exitClassicalArgument(qasmParser::ClassicalArgumentContext * /*ctx*/) override { }

  virtual void enterClassicalArgumentList(qasmParser::ClassicalArgumentListContext * /*ctx*/) override { }
  virtual void exitClassicalArgumentList(qasmParser::ClassicalArgumentListContext * /*ctx*/) override { }

  virtual void enterAnyTypeArgument(qasmParser::AnyTypeArgumentContext * /*ctx*/) override { }
  virtual void exitAnyTypeArgument(qasmParser::AnyTypeArgumentContext * /*ctx*/) override { }

  virtual void enterAnyTypeArgumentList(qasmParser::AnyTypeArgumentListContext * /*ctx*/) override { }
  virtual void exitAnyTypeArgumentList(qasmParser::AnyTypeArgumentListContext * /*ctx*/) override { }

  virtual void enterAliasStatement(qasmParser::AliasStatementContext * /*ctx*/) override { }
  virtual void exitAliasStatement(qasmParser::AliasStatementContext * /*ctx*/) override { }

  virtual void enterAliasInitializer(qasmParser::AliasInitializerContext * /*ctx*/) override { }
  virtual void exitAliasInitializer(qasmParser::AliasInitializerContext * /*ctx*/) override { }

  virtual void enterRangeDefinition(qasmParser::RangeDefinitionContext * /*ctx*/) override { }
  virtual void exitRangeDefinition(qasmParser::RangeDefinitionContext * /*ctx*/) override { }

  virtual void enterQuantumGateDefinition(qasmParser::QuantumGateDefinitionContext * /*ctx*/) override { }
  virtual void exitQuantumGateDefinition(qasmParser::QuantumGateDefinitionContext * /*ctx*/) override { }

  virtual void enterQuantumGateSignature(qasmParser::QuantumGateSignatureContext * /*ctx*/) override { }
  virtual void exitQuantumGateSignature(qasmParser::QuantumGateSignatureContext * /*ctx*/) override { }

  virtual void enterQuantumGateName(qasmParser::QuantumGateNameContext * /*ctx*/) override { }
  virtual void exitQuantumGateName(qasmParser::QuantumGateNameContext * /*ctx*/) override { }

  virtual void enterQuantumBlock(qasmParser::QuantumBlockContext * /*ctx*/) override { }
  virtual void exitQuantumBlock(qasmParser::QuantumBlockContext * /*ctx*/) override { }

  virtual void enterQuantumLoop(qasmParser::QuantumLoopContext * /*ctx*/) override { }
  virtual void exitQuantumLoop(qasmParser::QuantumLoopContext * /*ctx*/) override { }

  virtual void enterQuantumLoopBlock(qasmParser::QuantumLoopBlockContext * /*ctx*/) override { }
  virtual void exitQuantumLoopBlock(qasmParser::QuantumLoopBlockContext * /*ctx*/) override { }

  virtual void enterQuantumStatement(qasmParser::QuantumStatementContext * /*ctx*/) override { }
  virtual void exitQuantumStatement(qasmParser::QuantumStatementContext * /*ctx*/) override { }

  virtual void enterQuantumInstruction(qasmParser::QuantumInstructionContext * /*ctx*/) override { }
  virtual void exitQuantumInstruction(qasmParser::QuantumInstructionContext * /*ctx*/) override { }

  virtual void enterQuantumPhase(qasmParser::QuantumPhaseContext * /*ctx*/) override { }
  virtual void exitQuantumPhase(qasmParser::QuantumPhaseContext * /*ctx*/) override { }

  virtual void enterQuantumReset(qasmParser::QuantumResetContext * /*ctx*/) override { }
  virtual void exitQuantumReset(qasmParser::QuantumResetContext * /*ctx*/) override { }

  virtual void enterQuantumMeasurement(qasmParser::QuantumMeasurementContext * /*ctx*/) override { }
  virtual void exitQuantumMeasurement(qasmParser::QuantumMeasurementContext * /*ctx*/) override { }

  virtual void enterQuantumMeasurementAssignment(qasmParser::QuantumMeasurementAssignmentContext * /*ctx*/) override { }
  virtual void exitQuantumMeasurementAssignment(qasmParser::QuantumMeasurementAssignmentContext * /*ctx*/) override { }

  virtual void enterQuantumBarrier(qasmParser::QuantumBarrierContext * /*ctx*/) override { }
  virtual void exitQuantumBarrier(qasmParser::QuantumBarrierContext * /*ctx*/) override { }

  virtual void enterQuantumGateModifier(qasmParser::QuantumGateModifierContext * /*ctx*/) override { }
  virtual void exitQuantumGateModifier(qasmParser::QuantumGateModifierContext * /*ctx*/) override { }

  virtual void enterPowModifier(qasmParser::PowModifierContext * /*ctx*/) override { }
  virtual void exitPowModifier(qasmParser::PowModifierContext * /*ctx*/) override { }

  virtual void enterCtrlModifier(qasmParser::CtrlModifierContext * /*ctx*/) override { }
  virtual void exitCtrlModifier(qasmParser::CtrlModifierContext * /*ctx*/) override { }

  virtual void enterQuantumGateCall(qasmParser::QuantumGateCallContext * /*ctx*/) override { }
  virtual void exitQuantumGateCall(qasmParser::QuantumGateCallContext * /*ctx*/) override { }

  virtual void enterUnaryOperator(qasmParser::UnaryOperatorContext * /*ctx*/) override { }
  virtual void exitUnaryOperator(qasmParser::UnaryOperatorContext * /*ctx*/) override { }

  virtual void enterComparisonOperator(qasmParser::ComparisonOperatorContext * /*ctx*/) override { }
  virtual void exitComparisonOperator(qasmParser::ComparisonOperatorContext * /*ctx*/) override { }

  virtual void enterEqualityOperator(qasmParser::EqualityOperatorContext * /*ctx*/) override { }
  virtual void exitEqualityOperator(qasmParser::EqualityOperatorContext * /*ctx*/) override { }

  virtual void enterLogicalOperator(qasmParser::LogicalOperatorContext * /*ctx*/) override { }
  virtual void exitLogicalOperator(qasmParser::LogicalOperatorContext * /*ctx*/) override { }

  virtual void enterExpressionStatement(qasmParser::ExpressionStatementContext * /*ctx*/) override { }
  virtual void exitExpressionStatement(qasmParser::ExpressionStatementContext * /*ctx*/) override { }

  virtual void enterExpression(qasmParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(qasmParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterLogicalAndExpression(qasmParser::LogicalAndExpressionContext * /*ctx*/) override { }
  virtual void exitLogicalAndExpression(qasmParser::LogicalAndExpressionContext * /*ctx*/) override { }

  virtual void enterBitOrExpression(qasmParser::BitOrExpressionContext * /*ctx*/) override { }
  virtual void exitBitOrExpression(qasmParser::BitOrExpressionContext * /*ctx*/) override { }

  virtual void enterXOrExpression(qasmParser::XOrExpressionContext * /*ctx*/) override { }
  virtual void exitXOrExpression(qasmParser::XOrExpressionContext * /*ctx*/) override { }

  virtual void enterBitAndExpression(qasmParser::BitAndExpressionContext * /*ctx*/) override { }
  virtual void exitBitAndExpression(qasmParser::BitAndExpressionContext * /*ctx*/) override { }

  virtual void enterEqualityExpression(qasmParser::EqualityExpressionContext * /*ctx*/) override { }
  virtual void exitEqualityExpression(qasmParser::EqualityExpressionContext * /*ctx*/) override { }

  virtual void enterComparisonExpression(qasmParser::ComparisonExpressionContext * /*ctx*/) override { }
  virtual void exitComparisonExpression(qasmParser::ComparisonExpressionContext * /*ctx*/) override { }

  virtual void enterBitShiftExpression(qasmParser::BitShiftExpressionContext * /*ctx*/) override { }
  virtual void exitBitShiftExpression(qasmParser::BitShiftExpressionContext * /*ctx*/) override { }

  virtual void enterAdditiveExpression(qasmParser::AdditiveExpressionContext * /*ctx*/) override { }
  virtual void exitAdditiveExpression(qasmParser::AdditiveExpressionContext * /*ctx*/) override { }

  virtual void enterMultiplicativeExpression(qasmParser::MultiplicativeExpressionContext * /*ctx*/) override { }
  virtual void exitMultiplicativeExpression(qasmParser::MultiplicativeExpressionContext * /*ctx*/) override { }

  virtual void enterUnaryExpression(qasmParser::UnaryExpressionContext * /*ctx*/) override { }
  virtual void exitUnaryExpression(qasmParser::UnaryExpressionContext * /*ctx*/) override { }

  virtual void enterPowerExpression(qasmParser::PowerExpressionContext * /*ctx*/) override { }
  virtual void exitPowerExpression(qasmParser::PowerExpressionContext * /*ctx*/) override { }

  virtual void enterIndexOperator(qasmParser::IndexOperatorContext * /*ctx*/) override { }
  virtual void exitIndexOperator(qasmParser::IndexOperatorContext * /*ctx*/) override { }

  virtual void enterIndexExpression(qasmParser::IndexExpressionContext * /*ctx*/) override { }
  virtual void exitIndexExpression(qasmParser::IndexExpressionContext * /*ctx*/) override { }

  virtual void enterIndexedIdentifier(qasmParser::IndexedIdentifierContext * /*ctx*/) override { }
  virtual void exitIndexedIdentifier(qasmParser::IndexedIdentifierContext * /*ctx*/) override { }

  virtual void enterExpressionTerminator(qasmParser::ExpressionTerminatorContext * /*ctx*/) override { }
  virtual void exitExpressionTerminator(qasmParser::ExpressionTerminatorContext * /*ctx*/) override { }

  virtual void enterBooleanLiteral(qasmParser::BooleanLiteralContext * /*ctx*/) override { }
  virtual void exitBooleanLiteral(qasmParser::BooleanLiteralContext * /*ctx*/) override { }

  virtual void enterBuiltInCall(qasmParser::BuiltInCallContext * /*ctx*/) override { }
  virtual void exitBuiltInCall(qasmParser::BuiltInCallContext * /*ctx*/) override { }

  virtual void enterBuiltInMath(qasmParser::BuiltInMathContext * /*ctx*/) override { }
  virtual void exitBuiltInMath(qasmParser::BuiltInMathContext * /*ctx*/) override { }

  virtual void enterCastOperator(qasmParser::CastOperatorContext * /*ctx*/) override { }
  virtual void exitCastOperator(qasmParser::CastOperatorContext * /*ctx*/) override { }

  virtual void enterExpressionList(qasmParser::ExpressionListContext * /*ctx*/) override { }
  virtual void exitExpressionList(qasmParser::ExpressionListContext * /*ctx*/) override { }

  virtual void enterEqualsExpression(qasmParser::EqualsExpressionContext * /*ctx*/) override { }
  virtual void exitEqualsExpression(qasmParser::EqualsExpressionContext * /*ctx*/) override { }

  virtual void enterAssignmentOperator(qasmParser::AssignmentOperatorContext * /*ctx*/) override { }
  virtual void exitAssignmentOperator(qasmParser::AssignmentOperatorContext * /*ctx*/) override { }

  virtual void enterDiscreteSet(qasmParser::DiscreteSetContext * /*ctx*/) override { }
  virtual void exitDiscreteSet(qasmParser::DiscreteSetContext * /*ctx*/) override { }

  virtual void enterSetDeclaration(qasmParser::SetDeclarationContext * /*ctx*/) override { }
  virtual void exitSetDeclaration(qasmParser::SetDeclarationContext * /*ctx*/) override { }

  virtual void enterProgramBlock(qasmParser::ProgramBlockContext * /*ctx*/) override { }
  virtual void exitProgramBlock(qasmParser::ProgramBlockContext * /*ctx*/) override { }

  virtual void enterBranchingStatement(qasmParser::BranchingStatementContext * /*ctx*/) override { }
  virtual void exitBranchingStatement(qasmParser::BranchingStatementContext * /*ctx*/) override { }

  virtual void enterLoopSignature(qasmParser::LoopSignatureContext * /*ctx*/) override { }
  virtual void exitLoopSignature(qasmParser::LoopSignatureContext * /*ctx*/) override { }

  virtual void enterLoopStatement(qasmParser::LoopStatementContext * /*ctx*/) override { }
  virtual void exitLoopStatement(qasmParser::LoopStatementContext * /*ctx*/) override { }

  virtual void enterEndStatement(qasmParser::EndStatementContext * /*ctx*/) override { }
  virtual void exitEndStatement(qasmParser::EndStatementContext * /*ctx*/) override { }

  virtual void enterReturnStatement(qasmParser::ReturnStatementContext * /*ctx*/) override { }
  virtual void exitReturnStatement(qasmParser::ReturnStatementContext * /*ctx*/) override { }

  virtual void enterControlDirective(qasmParser::ControlDirectiveContext * /*ctx*/) override { }
  virtual void exitControlDirective(qasmParser::ControlDirectiveContext * /*ctx*/) override { }

  virtual void enterExternDeclaration(qasmParser::ExternDeclarationContext * /*ctx*/) override { }
  virtual void exitExternDeclaration(qasmParser::ExternDeclarationContext * /*ctx*/) override { }

  virtual void enterExternOrSubroutineCall(qasmParser::ExternOrSubroutineCallContext * /*ctx*/) override { }
  virtual void exitExternOrSubroutineCall(qasmParser::ExternOrSubroutineCallContext * /*ctx*/) override { }

  virtual void enterSubroutineDefinition(qasmParser::SubroutineDefinitionContext * /*ctx*/) override { }
  virtual void exitSubroutineDefinition(qasmParser::SubroutineDefinitionContext * /*ctx*/) override { }

  virtual void enterSubroutineBlock(qasmParser::SubroutineBlockContext * /*ctx*/) override { }
  virtual void exitSubroutineBlock(qasmParser::SubroutineBlockContext * /*ctx*/) override { }

  virtual void enterScope(qasmParser::ScopeContext * /*ctx*/) override { }
  virtual void exitScope(qasmParser::ScopeContext * /*ctx*/) override { }

  virtual void enterPragma(qasmParser::PragmaContext * /*ctx*/) override { }
  virtual void exitPragma(qasmParser::PragmaContext * /*ctx*/) override { }

  virtual void enterStatementOrScope(qasmParser::StatementOrScopeContext * /*ctx*/) override { }
  virtual void exitStatementOrScope(qasmParser::StatementOrScopeContext * /*ctx*/) override { }

  virtual void enterTimingType(qasmParser::TimingTypeContext * /*ctx*/) override { }
  virtual void exitTimingType(qasmParser::TimingTypeContext * /*ctx*/) override { }

  virtual void enterTimingBox(qasmParser::TimingBoxContext * /*ctx*/) override { }
  virtual void exitTimingBox(qasmParser::TimingBoxContext * /*ctx*/) override { }

  virtual void enterTimingIdentifier(qasmParser::TimingIdentifierContext * /*ctx*/) override { }
  virtual void exitTimingIdentifier(qasmParser::TimingIdentifierContext * /*ctx*/) override { }

  virtual void enterTimingInstructionName(qasmParser::TimingInstructionNameContext * /*ctx*/) override { }
  virtual void exitTimingInstructionName(qasmParser::TimingInstructionNameContext * /*ctx*/) override { }

  virtual void enterTimingInstruction(qasmParser::TimingInstructionContext * /*ctx*/) override { }
  virtual void exitTimingInstruction(qasmParser::TimingInstructionContext * /*ctx*/) override { }

  virtual void enterTimingStatement(qasmParser::TimingStatementContext * /*ctx*/) override { }
  virtual void exitTimingStatement(qasmParser::TimingStatementContext * /*ctx*/) override { }

  virtual void enterCalibration(qasmParser::CalibrationContext * /*ctx*/) override { }
  virtual void exitCalibration(qasmParser::CalibrationContext * /*ctx*/) override { }

  virtual void enterCalibrationGrammarDeclaration(qasmParser::CalibrationGrammarDeclarationContext * /*ctx*/) override { }
  virtual void exitCalibrationGrammarDeclaration(qasmParser::CalibrationGrammarDeclarationContext * /*ctx*/) override { }

  virtual void enterCalibrationDefinition(qasmParser::CalibrationDefinitionContext * /*ctx*/) override { }
  virtual void exitCalibrationDefinition(qasmParser::CalibrationDefinitionContext * /*ctx*/) override { }

  virtual void enterCalibrationGrammar(qasmParser::CalibrationGrammarContext * /*ctx*/) override { }
  virtual void exitCalibrationGrammar(qasmParser::CalibrationGrammarContext * /*ctx*/) override { }

  virtual void enterCalibrationArgumentList(qasmParser::CalibrationArgumentListContext * /*ctx*/) override { }
  virtual void exitCalibrationArgumentList(qasmParser::CalibrationArgumentListContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace mlir
