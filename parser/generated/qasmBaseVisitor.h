
// Generated from qasm.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "qasmVisitor.h"


namespace mlir {

/**
 * This class provides an empty implementation of qasmVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  qasmBaseVisitor : public qasmVisitor {
public:

  virtual std::any visitProgram(qasmParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitHeader(qasmParser::HeaderContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVersion(qasmParser::VersionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInclude(qasmParser::IncludeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIoIdentifier(qasmParser::IoIdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIo(qasmParser::IoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGlobalStatement(qasmParser::GlobalStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(qasmParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQuantumDeclarationStatement(qasmParser::QuantumDeclarationStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassicalDeclarationStatement(qasmParser::ClassicalDeclarationStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassicalAssignment(qasmParser::ClassicalAssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignmentStatement(qasmParser::AssignmentStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnSignature(qasmParser::ReturnSignatureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDesignator(qasmParser::DesignatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdentifierList(qasmParser::IdentifierListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQuantumDeclaration(qasmParser::QuantumDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQuantumArgument(qasmParser::QuantumArgumentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQuantumArgumentList(qasmParser::QuantumArgumentListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitType(qasmParser::BitTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSingleDesignatorType(qasmParser::SingleDesignatorTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNoDesignatorType(qasmParser::NoDesignatorTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNonArrayType(qasmParser::NonArrayTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayType(qasmParser::ArrayTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayReferenceTypeDimensionSpecifier(qasmParser::ArrayReferenceTypeDimensionSpecifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayReferenceType(qasmParser::ArrayReferenceTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassicalType(qasmParser::ClassicalTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumericType(qasmParser::NumericTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstantDeclaration(qasmParser::ConstantDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSingleDesignatorDeclaration(qasmParser::SingleDesignatorDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNoDesignatorDeclaration(qasmParser::NoDesignatorDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitDeclaration(qasmParser::BitDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComplexDeclaration(qasmParser::ComplexDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayInitializer(qasmParser::ArrayInitializerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayDeclaration(qasmParser::ArrayDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassicalDeclaration(qasmParser::ClassicalDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassicalTypeList(qasmParser::ClassicalTypeListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassicalArgument(qasmParser::ClassicalArgumentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassicalArgumentList(qasmParser::ClassicalArgumentListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAnyTypeArgument(qasmParser::AnyTypeArgumentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAnyTypeArgumentList(qasmParser::AnyTypeArgumentListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAliasStatement(qasmParser::AliasStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAliasInitializer(qasmParser::AliasInitializerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRangeDefinition(qasmParser::RangeDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQuantumGateDefinition(qasmParser::QuantumGateDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQuantumGateSignature(qasmParser::QuantumGateSignatureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQuantumGateName(qasmParser::QuantumGateNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQuantumBlock(qasmParser::QuantumBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQuantumLoop(qasmParser::QuantumLoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQuantumLoopBlock(qasmParser::QuantumLoopBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQuantumStatement(qasmParser::QuantumStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQuantumInstruction(qasmParser::QuantumInstructionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQuantumPhase(qasmParser::QuantumPhaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQuantumReset(qasmParser::QuantumResetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQuantumMeasurement(qasmParser::QuantumMeasurementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQuantumMeasurementAssignment(qasmParser::QuantumMeasurementAssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQuantumBarrier(qasmParser::QuantumBarrierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQuantumGateModifier(qasmParser::QuantumGateModifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPowModifier(qasmParser::PowModifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCtrlModifier(qasmParser::CtrlModifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQuantumGateCall(qasmParser::QuantumGateCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryOperator(qasmParser::UnaryOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComparisonOperator(qasmParser::ComparisonOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEqualityOperator(qasmParser::EqualityOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogicalOperator(qasmParser::LogicalOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionStatement(qasmParser::ExpressionStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression(qasmParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogicalAndExpression(qasmParser::LogicalAndExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitOrExpression(qasmParser::BitOrExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitXOrExpression(qasmParser::XOrExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitAndExpression(qasmParser::BitAndExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEqualityExpression(qasmParser::EqualityExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComparisonExpression(qasmParser::ComparisonExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitShiftExpression(qasmParser::BitShiftExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAdditiveExpression(qasmParser::AdditiveExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMultiplicativeExpression(qasmParser::MultiplicativeExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryExpression(qasmParser::UnaryExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPowerExpression(qasmParser::PowerExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIndexOperator(qasmParser::IndexOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIndexExpression(qasmParser::IndexExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIndexedIdentifier(qasmParser::IndexedIdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionTerminator(qasmParser::ExpressionTerminatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBooleanLiteral(qasmParser::BooleanLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBuiltInCall(qasmParser::BuiltInCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBuiltInMath(qasmParser::BuiltInMathContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCastOperator(qasmParser::CastOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionList(qasmParser::ExpressionListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEqualsExpression(qasmParser::EqualsExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignmentOperator(qasmParser::AssignmentOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiscreteSet(qasmParser::DiscreteSetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSetDeclaration(qasmParser::SetDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProgramBlock(qasmParser::ProgramBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBranchingStatement(qasmParser::BranchingStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLoopSignature(qasmParser::LoopSignatureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLoopStatement(qasmParser::LoopStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEndStatement(qasmParser::EndStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnStatement(qasmParser::ReturnStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitControlDirective(qasmParser::ControlDirectiveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExternDeclaration(qasmParser::ExternDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExternOrSubroutineCall(qasmParser::ExternOrSubroutineCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubroutineDefinition(qasmParser::SubroutineDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubroutineBlock(qasmParser::SubroutineBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPragma(qasmParser::PragmaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTimingType(qasmParser::TimingTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTimingBox(qasmParser::TimingBoxContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTimingIdentifier(qasmParser::TimingIdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTimingInstructionName(qasmParser::TimingInstructionNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTimingInstruction(qasmParser::TimingInstructionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTimingStatement(qasmParser::TimingStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCalibration(qasmParser::CalibrationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCalibrationGrammarDeclaration(qasmParser::CalibrationGrammarDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCalibrationDefinition(qasmParser::CalibrationDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCalibrationGrammar(qasmParser::CalibrationGrammarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCalibrationArgumentList(qasmParser::CalibrationArgumentListContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace mlir
