//===- StandaloneDialect.cpp - Standalone dialect ---------------*- C++ -*-===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "mlir/IR/Builders.h"
#include "mlir/IR/OpImplementation.h"

#include "quantum-mlir/Dialect/Quantum/IR/QuantumOps.h"

using namespace mlir;
using namespace quantum;


//===----------------------------------------------------------------------===//
// Standalone dialect.
//===----------------------------------------------------------------------===//
#include "quantum-mlir/Dialect/Quantum/IR/QuantumOpsDialect.cpp.inc"

void QuantumDialect::initialize() {
  addOperations<
#define GET_OP_LIST
#include "quantum-mlir/Dialect/Quantum/IR/QuantumOps.cpp.inc"
  >();
}