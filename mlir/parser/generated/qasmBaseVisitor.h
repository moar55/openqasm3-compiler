
// Generated from qasm.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "qasmVisitor.h"


/**
 * This class provides an empty implementation of qasmVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  qasmBaseVisitor : public qasmVisitor {
public:

  virtual antlrcpp::Any visitProgram(qasmParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHeader(qasmParser::HeaderContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVersion(qasmParser::VersionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInclude(qasmParser::IncludeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIoIdentifier(qasmParser::IoIdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIo(qasmParser::IoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGlobalStatement(qasmParser::GlobalStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(qasmParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuantumDeclarationStatement(qasmParser::QuantumDeclarationStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassicalDeclarationStatement(qasmParser::ClassicalDeclarationStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassicalAssignment(qasmParser::ClassicalAssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignmentStatement(qasmParser::AssignmentStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturnSignature(qasmParser::ReturnSignatureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDesignator(qasmParser::DesignatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifierList(qasmParser::IdentifierListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuantumDeclaration(qasmParser::QuantumDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuantumArgument(qasmParser::QuantumArgumentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuantumArgumentList(qasmParser::QuantumArgumentListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitType(qasmParser::BitTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSingleDesignatorType(qasmParser::SingleDesignatorTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNoDesignatorType(qasmParser::NoDesignatorTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNonArrayType(qasmParser::NonArrayTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayType(qasmParser::ArrayTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayReferenceTypeDimensionSpecifier(qasmParser::ArrayReferenceTypeDimensionSpecifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayReferenceType(qasmParser::ArrayReferenceTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassicalType(qasmParser::ClassicalTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumericType(qasmParser::NumericTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstantDeclaration(qasmParser::ConstantDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSingleDesignatorDeclaration(qasmParser::SingleDesignatorDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNoDesignatorDeclaration(qasmParser::NoDesignatorDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitDeclaration(qasmParser::BitDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComplexDeclaration(qasmParser::ComplexDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayInitializer(qasmParser::ArrayInitializerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayDeclaration(qasmParser::ArrayDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassicalDeclaration(qasmParser::ClassicalDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassicalTypeList(qasmParser::ClassicalTypeListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassicalArgument(qasmParser::ClassicalArgumentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassicalArgumentList(qasmParser::ClassicalArgumentListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAnyTypeArgument(qasmParser::AnyTypeArgumentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAnyTypeArgumentList(qasmParser::AnyTypeArgumentListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAliasStatement(qasmParser::AliasStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAliasInitializer(qasmParser::AliasInitializerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRangeDefinition(qasmParser::RangeDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuantumGateDefinition(qasmParser::QuantumGateDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuantumGateSignature(qasmParser::QuantumGateSignatureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuantumGateName(qasmParser::QuantumGateNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuantumBlock(qasmParser::QuantumBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuantumLoop(qasmParser::QuantumLoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuantumLoopBlock(qasmParser::QuantumLoopBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuantumStatement(qasmParser::QuantumStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuantumInstruction(qasmParser::QuantumInstructionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuantumPhase(qasmParser::QuantumPhaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuantumReset(qasmParser::QuantumResetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuantumMeasurement(qasmParser::QuantumMeasurementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuantumMeasurementAssignment(qasmParser::QuantumMeasurementAssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuantumBarrier(qasmParser::QuantumBarrierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuantumGateModifier(qasmParser::QuantumGateModifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPowModifier(qasmParser::PowModifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCtrlModifier(qasmParser::CtrlModifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuantumGateCall(qasmParser::QuantumGateCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryOperator(qasmParser::UnaryOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComparisonOperator(qasmParser::ComparisonOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEqualityOperator(qasmParser::EqualityOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogicalOperator(qasmParser::LogicalOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpressionStatement(qasmParser::ExpressionStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression(qasmParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogicalAndExpression(qasmParser::LogicalAndExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitOrExpression(qasmParser::BitOrExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitXOrExpression(qasmParser::XOrExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitAndExpression(qasmParser::BitAndExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEqualityExpression(qasmParser::EqualityExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComparisonExpression(qasmParser::ComparisonExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitShiftExpression(qasmParser::BitShiftExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAdditiveExpression(qasmParser::AdditiveExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultiplicativeExpression(qasmParser::MultiplicativeExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryExpression(qasmParser::UnaryExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPowerExpression(qasmParser::PowerExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIndexOperator(qasmParser::IndexOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIndexExpression(qasmParser::IndexExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIndexedIdentifier(qasmParser::IndexedIdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpressionTerminator(qasmParser::ExpressionTerminatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBooleanLiteral(qasmParser::BooleanLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBuiltInCall(qasmParser::BuiltInCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBuiltInMath(qasmParser::BuiltInMathContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCastOperator(qasmParser::CastOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpressionList(qasmParser::ExpressionListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEqualsExpression(qasmParser::EqualsExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignmentOperator(qasmParser::AssignmentOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDiscreteSet(qasmParser::DiscreteSetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSetDeclaration(qasmParser::SetDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProgramBlock(qasmParser::ProgramBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBranchingStatement(qasmParser::BranchingStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLoopSignature(qasmParser::LoopSignatureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLoopStatement(qasmParser::LoopStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEndStatement(qasmParser::EndStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturnStatement(qasmParser::ReturnStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitControlDirective(qasmParser::ControlDirectiveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExternDeclaration(qasmParser::ExternDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExternOrSubroutineCall(qasmParser::ExternOrSubroutineCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubroutineDefinition(qasmParser::SubroutineDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubroutineBlock(qasmParser::SubroutineBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPragma(qasmParser::PragmaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTimingType(qasmParser::TimingTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTimingBox(qasmParser::TimingBoxContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTimingIdentifier(qasmParser::TimingIdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTimingInstructionName(qasmParser::TimingInstructionNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTimingInstruction(qasmParser::TimingInstructionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTimingStatement(qasmParser::TimingStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCalibration(qasmParser::CalibrationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCalibrationGrammarDeclaration(qasmParser::CalibrationGrammarDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCalibrationDefinition(qasmParser::CalibrationDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCalibrationGrammar(qasmParser::CalibrationGrammarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCalibrationArgumentList(qasmParser::CalibrationArgumentListContext *ctx) override {
    return visitChildren(ctx);
  }


};

