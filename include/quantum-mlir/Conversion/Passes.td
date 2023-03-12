#ifndef QUANTUMMLIR_QUANTUM_PASSES
#define QUANTUMMLIR_QUANTUM_PASSES

include "mlir/Pass/PassBase.td"

def ConvertToGenGate: Pass<"quantum-convert-to-gen-gate", "ModuleOp"> {
    let summary = "Convert inst to gen gate";
    let constructor = "mlir::quantum::createConvertToGenGatePass()";
    let description = [{
    }];
}

def LowerToRestQuantum: Pass<"lower-to-restquantum", "ModuleOp"> {
    let summary = "Lower quantum dialect instructions to restricted quantum dialect instructions";
    let constructor = "mlir::quantum::createLowerToRestQuantumPass()";
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