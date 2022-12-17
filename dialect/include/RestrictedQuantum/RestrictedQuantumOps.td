#ifndef Restricted_Quantum_OPS
#define Restricted_Quantum_OPS

include "RestrictedQuantumDialect.td"
include "Quantum/IR/QuantumTypes.td"

def Rx90Op : RestrictedQuantumOp<"rx90"> {
    let arguments = (ins QubitType:$qubit);
    let results = (outs QubitType:$result);
}

def Rx180Op : RestrictedQuantumOp<"rx180"> {
    let arguments = (ins QubitType:$qubit);
    let results = (outs QubitType:$result);
}

def Ry90Op : RestrictedQuantumOp<"ry90"> {
    let arguments = (ins QubitType:$qubit);
    let results = (outs QubitType:$result);
}

def Ry180Op : RestrictedQuantumOp<"ry180"> {
    let arguments = (ins QubitType:$qubit);
    let results = (outs QubitType:$result);
}


def RzOp : RestrictedQuantumOp<"rz"> {
    let arguments = (ins QubitType:$qubit, F64:$angle);
    let results = (outs QubitType:$result);
}

def SqrtX: RestrictedQuantumOp<"sqrtx"> {
    let arguments = (ins QubitType: $qubit);
    let results = (outs QubitType:$result);
}

def CX : RestrictedQuantumOp<"cx"> {
    let arguments = (ins QubitType: $qubit1, QubitType: $qubit2);
    let results = (outs QubitType: $control, QubitType: $sink);
}

// U = Rz Ry(theta) Rz

#endif // Restricted_Quantum_OPS