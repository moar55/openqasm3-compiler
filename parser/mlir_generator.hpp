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

#include "Quantum/IR/QuantumOps.h"
#include "mlir/IR/Attributes.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/BuiltinOps.h"
#include "mlir/IR/BuiltinTypes.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/IR/Verifier.h"

class visitor;

class MLIRGenerator{
protected:
    mlir::MLIRContext& context;
    mlir::ModuleOp m_module;
    mlir::OpBuilder builder;
    std::vector<std::string> function_names;
    std::string file_name = "main";
    bool add_entry_point = true;
    bool add_custom_return = false;

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
//      m_module.getOps<>()
    }

    void initialize_mlirgen(const std::string entry_function_name);
    void mlirgen(const std::string &src) ;

    mlir::ModuleOp get_module() {
      return m_module;
    }

    mlir::OpBuilder get_builder() {
      return builder;
    }

    std::vector<std::string> seen_function_names() { return function_names; }
    void finalize_mlirgen();
};