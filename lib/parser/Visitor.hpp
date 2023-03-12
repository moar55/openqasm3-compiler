#pragma once

#include "antlr4-runtime.h"

#include <regex>
#include "mlir/IR/Builders.h"
#include "mlir/IR/BuiltinOps.h"
#include "mlir/Dialect/MemRef/IR/MemRef.h"
#include "generated/qasmBaseVisitor.h"
#include "utils/symbol_table.hpp"

using namespace mlir;

class Visitor : public qasmBaseVisitor {
public:
    template <typename OpTy, typename... Args>
    OpTy createOp(Args... args) {
      OpTy value = builder.create<OpTy>(args...);
      return value;
    }
    // Return the symbol table.
    ScopedSymbolTable *getScopedSymbolTable() { return &symbol_table; }

    int offset = 0;

    // The constructor, instantiates commonly used opaque types
     Visitor(mlir::OpBuilder b, mlir::ModuleOp m, std::string &fname);

    ~Visitor();

    // Visit nodes corresponding to quantum variable and gate declarations.
    // see visitor_handlers/quantum_types_handler.cpp for implementation
    std::any visitQuantumGateDefinition(
            qasmParser::QuantumGateDefinitionContext *context) override;

    std::any visitQuantumDeclaration(
            qasmParser::QuantumDeclarationContext *context) override;

    // see visitor_handlers/quantum_instruction_handler.cpp
    std::any visitQuantumGateCall(
            qasmParser::QuantumGateCallContext *context) override;

    // see visitor_handlers/measurement_handler.cpp
    std::any visitQuantumMeasurement(
            qasmParser::QuantumMeasurementContext *context) override;

    std::any visitQuantumMeasurementAssignment(
            qasmParser::QuantumMeasurementAssignmentContext *context) override;

    // see visitor_handlers/classical_types_handler.cpp
    std::any visitSingleDesignatorDeclaration(
            qasmParser::SingleDesignatorDeclarationContext *context) override;

    std::any visitBitDeclaration(
            qasmParser::BitDeclarationContext *context) override;

//        // QCOR_EXPECT_TRUE handler
//        std::any visitQcor_test_statement(
//                qasmParser::Qcor_test_statementContext *context) override;

//    std::any visitPragma(qasmParser::PragmaContext *ctx) override {
//      // Handle the #pragma { export; } directive
//      // Mark the export bool flag so that the later sub-routine handler will pick it up.
//      if (ctx->statement().size() == 1 && ctx->statement(0)->getText() == "export;") {
//        // The handler needs to reset this flag after handling the sub-routine.
////            assert(!export_subroutine_as_callable);
////            export_subroutine_as_callable = true;
//        return 0;
//      } else {
//        return visitChildren(ctx);
//      }
//    }

    std::any visitProgram(qasmParser::ProgramContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitHeader(qasmParser::HeaderContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitVersion(qasmParser::VersionContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitInclude(qasmParser::IncludeContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitIoIdentifier(qasmParser::IoIdentifierContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitIo(qasmParser::IoContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitGlobalStatement(qasmParser::GlobalStatementContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitStatement(qasmParser::StatementContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitQuantumDeclarationStatement(qasmParser::QuantumDeclarationStatementContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitClassicalDeclarationStatement(qasmParser::ClassicalDeclarationStatementContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitClassicalAssignment(qasmParser::ClassicalAssignmentContext *ctx) override;

    std::any visitAssignmentStatement(qasmParser::AssignmentStatementContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitReturnSignature(qasmParser::ReturnSignatureContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitDesignator(qasmParser::DesignatorContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitIdentifierList(qasmParser::IdentifierListContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitQuantumArgument(qasmParser::QuantumArgumentContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitQuantumArgumentList(qasmParser::QuantumArgumentListContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitBitType(qasmParser::BitTypeContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitSingleDesignatorType(qasmParser::SingleDesignatorTypeContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitNoDesignatorType(qasmParser::NoDesignatorTypeContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitNonArrayType(qasmParser::NonArrayTypeContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitArrayType(qasmParser::ArrayTypeContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any
    visitArrayReferenceTypeDimensionSpecifier(qasmParser::ArrayReferenceTypeDimensionSpecifierContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitArrayReferenceType(qasmParser::ArrayReferenceTypeContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitClassicalType(qasmParser::ClassicalTypeContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitNumericType(qasmParser::NumericTypeContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitConstantDeclaration(qasmParser::ConstantDeclarationContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitComplexDeclaration(qasmParser::ComplexDeclarationContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitArrayInitializer(qasmParser::ArrayInitializerContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitArrayDeclaration(qasmParser::ArrayDeclarationContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitClassicalDeclaration(qasmParser::ClassicalDeclarationContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitClassicalTypeList(qasmParser::ClassicalTypeListContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitClassicalArgument(qasmParser::ClassicalArgumentContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitClassicalArgumentList(qasmParser::ClassicalArgumentListContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitAnyTypeArgument(qasmParser::AnyTypeArgumentContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitAnyTypeArgumentList(qasmParser::AnyTypeArgumentListContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitAliasStatement(qasmParser::AliasStatementContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitAliasInitializer(qasmParser::AliasInitializerContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitRangeDefinition(qasmParser::RangeDefinitionContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitQuantumGateSignature(qasmParser::QuantumGateSignatureContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitQuantumGateName(qasmParser::QuantumGateNameContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitQuantumBlock(qasmParser::QuantumBlockContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitQuantumLoop(qasmParser::QuantumLoopContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitQuantumLoopBlock(qasmParser::QuantumLoopBlockContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitQuantumStatement(qasmParser::QuantumStatementContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitQuantumInstruction(qasmParser::QuantumInstructionContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitQuantumPhase(qasmParser::QuantumPhaseContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitQuantumReset(qasmParser::QuantumResetContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitQuantumBarrier(qasmParser::QuantumBarrierContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitQuantumGateModifier(qasmParser::QuantumGateModifierContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitPowModifier(qasmParser::PowModifierContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitCtrlModifier(qasmParser::CtrlModifierContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitUnaryOperator(qasmParser::UnaryOperatorContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitComparisonOperator(qasmParser::ComparisonOperatorContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitEqualityOperator(qasmParser::EqualityOperatorContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitLogicalOperator(qasmParser::LogicalOperatorContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitExpressionStatement(qasmParser::ExpressionStatementContext *ctx) override {
      return visitChildren(ctx);
    }

//    std::any visitLogicalAndExpression(qasmParser::LogicalAndExpressionContext *ctx) override;
//
//    std::any visitBitOrExpression(qasmParser::BitOrExpressionContext *ctx) override;
//
//    std::any visitXOrExpression(qasmParser::XOrExpressionContext *ctx) override;
//
//    std::any visitBitAndExpression(qasmParser::BitAndExpressionContext *ctx) override;
//
//    std::any visitEqualityExpression(qasmParser::EqualityExpressionContext *ctx) override;
//
//    std::any visitComparisonExpression(qasmParser::ComparisonExpressionContext *ctx) override;
//
//    std::any visitBitShiftExpression(qasmParser::BitShiftExpressionContext *ctx) override;
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
//
    std::any visitBooleanLiteral(qasmParser::BooleanLiteralContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitBuiltInCall(qasmParser::BuiltInCallContext *ctx) override;

    std::any visitBuiltInMath(qasmParser::BuiltInMathContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitCastOperator(qasmParser::CastOperatorContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitExpressionList(qasmParser::ExpressionListContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitEqualsExpression(qasmParser::EqualsExpressionContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitAssignmentOperator(qasmParser::AssignmentOperatorContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitDiscreteSet(qasmParser::DiscreteSetContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitSetDeclaration(qasmParser::SetDeclarationContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitProgramBlock(qasmParser::ProgramBlockContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitBranchingStatement(qasmParser::BranchingStatementContext *ctx) override;

    std::any visitLoopSignature(qasmParser::LoopSignatureContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitLoopStatement(qasmParser::LoopStatementContext *ctx) override;

    std::any visitEndStatement(qasmParser::EndStatementContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitReturnStatement(qasmParser::ReturnStatementContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitControlDirective(qasmParser::ControlDirectiveContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitExternDeclaration(qasmParser::ExternDeclarationContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitExternOrSubroutineCall(qasmParser::ExternOrSubroutineCallContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitSubroutineDefinition(qasmParser::SubroutineDefinitionContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitSubroutineBlock(qasmParser::SubroutineBlockContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitTimingType(qasmParser::TimingTypeContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitTimingBox(qasmParser::TimingBoxContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitTimingIdentifier(qasmParser::TimingIdentifierContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitTimingInstructionName(qasmParser::TimingInstructionNameContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitTimingInstruction(qasmParser::TimingInstructionContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitTimingStatement(qasmParser::TimingStatementContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitCalibration(qasmParser::CalibrationContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitCalibrationGrammarDeclaration(qasmParser::CalibrationGrammarDeclarationContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitCalibrationDefinition(qasmParser::CalibrationDefinitionContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitCalibrationGrammar(qasmParser::CalibrationGrammarContext *ctx) override {
      return visitChildren(ctx);
    }

    std::any visitCalibrationArgumentList(qasmParser::CalibrationArgumentListContext *ctx) override {
      return visitChildren(ctx);
    }

    void gen_yield_of_symbols(const std::set<std::string> yield_symbols);
    mlir::Type get_symbol_type(const std::string &var_name);
    void traverse_and_populate_symbols_list(antlr4::ParserRuleContext *context, ScopedSymbolTable &symbol_table, std::set<std::string> &yield_symbols);



//
//    // This function serves as a utility for creating a MemRef and
//    // corresponding AllocOp of a given 1d shape.
//    mlir::Value allocate_1d_memory(mlir::Location location, int64_t shape,
//                                   mlir::Type type, mlir::OpBuilder builder) {
//      llvm::ArrayRef<int64_t> shaperef(shape);
//
//      auto mem_type = mlir::MemRefType::get(shaperef, type);
//      mlir::Value allocation = builder.create<mlir::memref::AllocaOp>(location, mem_type);
//
//      return allocation;
//    }

    // This function serves as a utility for creating a MemRef and
    // corresponding AllocOp of a given 1d shape. It will also store
    // initial values to all elements of the 1d array.
//    mlir::Value allocate_1d_memory_and_initialize(
//            mlir::Location location, int64_t shape, mlir::Type type,
//            std::vector<mlir::Value> initial_values,
//            llvm::ArrayRef<mlir::Value> initial_indices) {
//      if (shape != initial_indices.size()) {
////            printErrorMessage(
////                    "Cannot allocate and initialize memory, shape and number of initial "
////                    "value indices is incorrect");
////          }
//
//        // Assert that the values to init the memref array
//        // must be of the expected type.
//        for (const auto &init_val: initial_values) {
//          assert(init_val.getType() == type);
//        }
//
//        // Allocate
//        auto allocation = allocate_1d_memory(location, shape, type, builder);
//        // and initialize
//        for (int i = 0; i < initial_values.size(); i++) {
//          assert(initial_indices[i].getType().isa<mlir::IndexType>());
//          builder.create<mlir::memref::StoreOp>(location, initial_values[i], allocation,
//                                                initial_indices[i]);
//        }
//        return allocation;
//      }
//    }

protected:
    // Reference to the MLIR OpBuilder and ModuleOp
    // this MLIRGen task
    mlir::OpBuilder builder;
    // The symbol table, keeps track of current scope
    ScopedSymbolTable symbol_table;
    mlir::ModuleOp m_module;
    std::string file_name = "";


    bool enable_nisq_ifelse = false;

    // Reference to MLIR Quantum Opaque Types
    mlir::Type qubit_type;
    mlir::Type array_type;
    mlir::Type result_type;

//    template<class NodeType>
//    bool hasChildNodeOfType(antlr4::tree::ParseTree &in_node) {
//      for (auto &child_node: in_node.children) {
//        if (dynamic_cast<NodeType *>(child_node) ||
//            hasChildNodeOfType<NodeType>(*child_node)) {
//          return true;
//        }
//      }
//      return false;
//    }
};
