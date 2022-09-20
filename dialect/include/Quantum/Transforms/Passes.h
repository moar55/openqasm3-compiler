#pragma once
#include "mlir/IR/BuiltinOps.h"
#include "mlir/Pass/Pass.h"
namespace mlir {
    class ModuleOp;
    namespace quantum {
        std::unique_ptr<OperationPass<ModuleOp>> createConvertInstPass();
        void registerQuantumPasses();
    }
}



