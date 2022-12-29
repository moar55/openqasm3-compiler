#include "mlir/Pass/PassManager.h"
#include "mlir/Transforms/Passes.h"
#include "mlir/IR/OperationSupport.h"

#include <iostream>
#include <mlir_generator.hpp>
#include <fstream>

#include "Quantum/IR/QuantumDialect.h"
#include <RestrictedQuantum/RestrictedQuantumDialect.h>
#include "mlir/Dialect/MemRef/IR/MemRef.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/Dialect/SCF/IR/SCF.h"
#include "mlir/Dialect/Arith/IR/Arith.h"
#include "mlir/Dialect/Vector/IR/VectorOps.h"
#include "Quantum/Transforms/Passes.h"