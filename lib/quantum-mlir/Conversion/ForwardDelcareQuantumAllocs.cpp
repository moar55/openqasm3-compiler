#include <iostream>
#include <mlir/Transforms/DialectConversion.h>
#include <quantum-mlir/Dialect/Quantum/IR/QuantumOps.h>
#include "mlir/Conversion/ArithToLLVM/ArithToLLVM.h"
#include "mlir/Conversion/FuncToLLVM/ConvertFuncToLLVM.h"
#include "mlir/Conversion/FuncToLLVM/ConvertFuncToLLVMPass.h"
#include "mlir/Conversion/VectorToLLVM/ConvertVectorToLLVM.h"
#include "mlir/Conversion/LLVMCommon/ConversionTarget.h"
#include "mlir/Conversion/LLVMCommon/TypeConverter.h"
#include "mlir/Conversion/MemRefToLLVM/MemRefToLLVM.h"
#include "mlir/Conversion/SCFToControlFlow/SCFToControlFlow.h"
#include "mlir/Dialect/Arith/IR/Arith.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/Dialect/LLVMIR/LLVMDialect.h"
#include "mlir/Pass/Pass.h"
#include "quantum-mlir/Conversion/Passes.h"
#include "PassImp.h"


#include "mlir/Transforms/Passes.h"

#include "mlir/IR/Dominance.h"

#include "string"

#include "stack"

using namespace mlir;


class ForwardDeclareQuantumAllocs
        : public quantum::ForwardDeclareQuantumAllocsBase<ForwardDeclareQuantumAllocs> {
public:
    void runOnOperation() override {
      //TODO: get alll qalloc ops
      //set insertion point to first op
      //insert them there
      //erase these ops

      auto domInfo = &getAnalysisManager().getAnalysis<DominanceInfo>();
      Operation *moduleOp = getOperation();
      auto &moduleOpRegion = moduleOp->getRegion(0); // get root region
      auto &moduleOpBlock = moduleOpRegion.front();
      auto &funcOp = moduleOpBlock.front();
      auto &funcOpBlock = funcOp.getRegion(0).front();
      std::vector<Operation*> allocs;
      Operation* firstOp = nullptr;
      for (auto &op: funcOpBlock) {
        auto name = op.getName().getStringRef().str();
        if (name != "quantum.qalloc") {
          firstOp = &op;
          break;
        }
      }

    std::vector<Operation *>  remOperations;
    bool moved = false;
    if (firstOp) {
      for (auto &op: funcOpBlock) {
        auto name = op.getName().getStringRef().str();
        if (name == "quantum.qalloc") {
          if (moved) {
            op.moveAfter(firstOp);

          } else {
            op.moveBefore(firstOp);
            moved = true;
          }

          for (auto user: op.getUsers()) {
            auto operand = user->getOperand(1).getDefiningOp();
            remOperations.push_back(operand);
            remOperations.push_back(user);
          }

          firstOp = &op;
        }
      }
    }

    for (auto op: remOperations) {
      op->moveAfter(firstOp);
      firstOp = op;
    }


  };
};

std::unique_ptr<OperationPass<ModuleOp>>
mlir::quantum::createForwardDeclareQuantumAllocsPass() {
  return std::make_unique<ForwardDeclareQuantumAllocs>();
}