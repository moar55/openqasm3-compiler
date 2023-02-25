#ifndef QUANTUMMLIR_QUANTUM_PASSES
#define QUANTUMMLIR_QUANTUM_PASSES

include "mlir/Pass/PassBase.td"

def ConvertToGenGate: Pass<"quantum-convert-to-gen-gate", "ModuleOp"> {
    let summary = "Convert inst to gen gate";
    let constructor = "mlir::quantum::createConvertToGenGatePass()";
    let description = [{
    }];
}

def ConvertInst: Pass<"quantum-convert-inst", "ModuleOp"> {
    let summary = "Convert inst to rest quantum insts";
    let constructor = "mlir::quantum::createConvertInstPass()";
    let description = [{
    }];
}


def ForwardDeclareQuantumAllocs: Pass<"foward-declare-qallocs", "ModuleOp"> {
    let summary = "forward declare quantum allocations";
    let constructor = "mlir::quantum::forwardDeclareQuantumAllocsPass()";
    let description = [{

    }];
}


def QuantumSimulator: Pass<"quantum-simulator", "ModuleOp"> {
 let summary = "";
 let constructor = "mlir::quantum::createQuantumSimulator()";
 let description = [{}];
}

def LowerToLLVM: Pass<"lower-to-llvm", "ModuleOp"> {
    let summary = "lower dialects to llvm MLIR dialect";
    let constructor = "mlir::quantum::lowerToLLVMPass()";
    let description = [{

    }];
}

#endif // QUANTUMMLIR_QUANTUM_PASSES