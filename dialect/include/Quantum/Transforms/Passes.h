#pragma once
#include "mlir/IR/BuiltinOps.h"
#include "mlir/Pass/Pass.h"
#include "Quantum/Transforms/Passes.h.inc"
namespace mlir {
    class ModuleOp;
    namespace quantum {
        std::unique_ptr<OperationPass<ModuleOp>> createConvertInstPass();

        [[maybe_unused]] void registerQuantumPasses();
    }
}



