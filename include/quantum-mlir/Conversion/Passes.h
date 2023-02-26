#pragma once
#include "mlir/IR/BuiltinOps.h"
#include "mlir/Pass/Pass.h"
#include "quantum-mlir/Conversion/Passes.h.inc"
namespace mlir {
    class ModuleOp;
    namespace quantum {
        std::unique_ptr<OperationPass<ModuleOp>> createConvertToGenGatePass(); // TODO: remove and make lowering not relying on GenGate
        std::unique_ptr<OperationPass<ModuleOp>> createConvertInstPass();
        std::unique_ptr<OperationPass<ModuleOp>> createForwardDeclareQuantumAllocsPass();
        std::unique_ptr<OperationPass<ModuleOp>> createQuantumSimulator();
        std::unique_ptr<OperationPass<ModuleOp>> createLowerToLLVMPass();

        [[maybe_unused]] void registerQuantumPasses();
    }
}



