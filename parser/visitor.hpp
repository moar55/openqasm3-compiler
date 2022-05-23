#pragma once

#include <regex>
#include "mlir/IR/Builders.h"
#include "mlir/IR/BuiltinOps.h"
#include "mlir/Dialect/MemRef/IR/MemRef.h"
#include "generated/qasmBaseVisitor.h"
#include "utils/symbol_table.hpp"

using namespace mlir;
class visitor : public qasmBaseVisitor {
public:
    // Return the symbol table.
    ScopedSymbolTable* getScopedSymbolTable() { return &symbol_table; }

    // The constructor, instantiates commonly used opaque types
    visitor(mlir::OpBuilder b, mlir::ModuleOp m, std::string &fname);

    // Visit nodes corresponding to quantum variable and gate declarations.
    // see visitor_handlers/quantum_types_handler.cpp for implementation
    antlrcpp::Any visitQuantumGateDefinition(
            qasmParser::QuantumGateDefinitionContext *context) override;

    antlrcpp::Any visitQuantumDeclaration(
            qasmParser::QuantumDeclarationContext *context) override;

    // see visitor_handlers/quantum_instruction_handler.cpp
    antlrcpp::Any visitQuantumGateCall(
            qasmParser::QuantumGateCallContext *context) override;

    // see visitor_handlers/measurement_handler.cpp
    antlrcpp::Any visitQuantumMeasurement(
            qasmParser::QuantumMeasurementContext *context) override;

    antlrcpp::Any visitQuantumMeasurementAssignment(
            qasmParser::QuantumMeasurementAssignmentContext *context) override;

    // see visitor_handlers/classical_types_handler.cpp
    antlrcpp::Any visitSingleDesignatorDeclaration(
            qasmParser::SingleDesignatorDeclarationContext *context) override;

    antlrcpp::Any visitNoDesignatorDeclaration(
            qasmParser::NoDesignatorDeclarationContext *context) override;

    antlrcpp::Any visitBitDeclaration(
            qasmParser::BitDeclarationContext *context) override;

//        // QCOR_EXPECT_TRUE handler
//        antlrcpp::Any visitQcor_test_statement(
//                qasmParser::Qcor_test_statementContext *context) override;

    antlrcpp::Any visitPragma(qasmParser::PragmaContext *ctx) override {
      // Handle the #pragma { export; } directive
      // Mark the export bool flag so that the later sub-routine handler will pick it up.
      if (ctx->statement().size() == 1 && ctx->statement(0)->getText() == "export;") {
        // The handler needs to reset this flag after handling the sub-routine.
//            assert(!export_subroutine_as_callable);
//            export_subroutine_as_callable = true;
        return 0;
      } else {
        return visitChildren(ctx);
      }
    }

    // This function serves as a utility for creating a MemRef and
    // corresponding AllocOp of a given 1d shape.
    mlir::Value allocate_1d_memory(mlir::Location location, int64_t shape,
                                   mlir::Type type, mlir::OpBuilder builder) {
      llvm::ArrayRef<int64_t> shaperef(shape);

      auto mem_type = mlir::MemRefType::get(shaperef, type);
      mlir::Value allocation = builder.create<mlir::memref::AllocaOp>(location, mem_type);

      return allocation;
    }

    // This function serves as a utility for creating a MemRef and
    // corresponding AllocOp of a given 1d shape. It will also store
    // initial values to all elements of the 1d array.
    mlir::Value allocate_1d_memory_and_initialize(
            mlir::Location location, int64_t shape, mlir::Type type,
            std::vector<mlir::Value> initial_values,
            llvm::ArrayRef<mlir::Value> initial_indices) {
      if (shape != initial_indices.size()) {
//            printErrorMessage(
//                    "Cannot allocate and initialize memory, shape and number of initial "
//                    "value indices is incorrect");
//          }

        // Assert that the values to init the memref array
        // must be of the expected type.
        for (const auto &init_val: initial_values) {
          assert(init_val.getType() == type);
        }

        // Allocate
        auto allocation = allocate_1d_memory(location, shape, type, builder);
        // and initialize
        for (int i = 0; i < initial_values.size(); i++) {
          assert(initial_indices[i].getType().isa<mlir::IndexType>());
          builder.create<mlir::memref::StoreOp>(location, initial_values[i], allocation,
                                                initial_indices[i]);
        }
        return allocation;
      }
    }

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

    template<class NodeType>
    bool hasChildNodeOfType(antlr4::tree::ParseTree &in_node) {
      for (auto &child_node: in_node.children) {
        if (dynamic_cast<NodeType *>(child_node) ||
            hasChildNodeOfType<NodeType>(*child_node)) {
          return true;
        }
      }
      return false;
    }
};
