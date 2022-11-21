#include "mlir/Pass/PassManager.h"
#include <iostream>
#include <mlir_generator.hpp>
#include <fstream>

#include "Quantum/IR/QuantumDialect.h"
#include <RestrictedQuantum/RestrictedQuantumDialect.h>
#include "mlir/Dialect/MemRef/IR/MemRef.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/Dialect/Arithmetic/IR/Arithmetic.h"
#include "Quantum/Transforms/Passes.h"