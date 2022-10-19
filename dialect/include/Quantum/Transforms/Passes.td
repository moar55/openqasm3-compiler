#ifndef QUANTUMMLIR_QUANTUM_PASSES
#define QUANTUMMLIR_QUANTUM_PASSES

include "mlir/Pass/PassBase.td"

def ConvertInst: Pass<"quantum-convert-inst", "ModuleOp"> {
    let summary = "Convert inst to rest quantum insts";
    let constructor = "mlir::quantum::createConvertInstPass()";
    let description = [{
    }];
}

#endif // QUANTUMMLIR_QUANTUM_PASSES