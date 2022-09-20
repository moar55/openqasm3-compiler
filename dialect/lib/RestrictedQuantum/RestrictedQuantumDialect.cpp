//===- StandaloneDialect.cpp - Standalone dialect ---------------*- C++ -*-===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "mlir/IR/Builders.h"
#include "mlir/IR/OpImplementation.h"

#include "RestrictedQuantum/RestrictedQuantumOps.h"

using namespace mlir;
using namespace restquantum;


//===----------------------------------------------------------------------===//
// Standalone dialect.
//===----------------------------------------------------------------------===//
#include "RestrictedQuantum/RestrictedQuantumDialect.cpp.inc"

void RestrictedQuantumDialect::initialize() {
  addOperations<
#define GET_OP_LIST
#include "RestrictedQuantum/RestrictedQuantumOps.cpp.inc"
  >();
}