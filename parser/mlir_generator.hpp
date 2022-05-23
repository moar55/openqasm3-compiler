/*******************************************************************************
 * Copyright (c) 2018-, UT-Battelle, LLC.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the BSD 3-Clause License
 * which accompanies this distribution.
 *
 * Contributors:
 *   Alexander J. McCaskey - initial API and implementation
 *   Thien Nguyen - implementation
 *******************************************************************************/
#pragma once

#include "Quantum/QuantumOps.h"
#include "mlir/IR/Attributes.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/BuiltinOps.h"
#include "mlir/IR/BuiltinTypes.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/IR/Verifier.h"
#include "mlir_generator.hpp"

class visitor;

class MLIRGenerator{
protected:
    mlir::MLIRContext& context;
    mlir::ModuleOp m_module;
    mlir::OpBuilder builder;
    mlir::Block* main_entry_block;
    std::vector<std::string> function_names;

    std::string file_name = "main";
    bool add_entry_point = true;
    bool add_custom_return = false;
    mlir::Type return_type;
    mlir::Type qubit_type;
    mlir::Type array_type;
    mlir::Type result_type;

    std::map<std::string, mlir::Value> global_symbol_table;
    bool add_main = true;
    std::shared_ptr<visitor> my_visitor;

public:
    MLIRGenerator(mlir::MLIRContext& ctx) : context(ctx), builder(&ctx) {
      m_module = mlir::ModuleOp::create(builder.getUnknownLoc());
    }
    MLIRGenerator(mlir::OpBuilder b, mlir::MLIRContext& ctx)
            : context(ctx), builder(b) {
      m_module = mlir::ModuleOp::create(builder.getUnknownLoc());
    }

    void initialize_mlirgen(const std::string func_name,
                            std::vector<mlir::Type> arg_types,
                            std::vector<std::string> arg_var_names,
                            std::vector<std::string> var_attributes,
                            mlir::Type return_type);
    void initialize_mlirgen(
            bool add_entry_point = true, const std::string file_name = "",
            std::map<std::string, std::string> extra_quantum_args = {}) ;
    void mlirgen(const std::string &src) ;
//    mlir::OwningOpRef get_module() {
//      return mlir::OwningModuleRef(mlir::OwningOpRef<mlir::ModuleOp>(m_module));
//    }

    std::vector<std::string> seen_function_names() { return function_names; }
    void finalize_mlirgen();
};