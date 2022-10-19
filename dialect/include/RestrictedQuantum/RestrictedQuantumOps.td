#ifndef Restricted_Quantum_OPS
#define Restricted_Quantum_OPS

include "RestrictedQuantumDialect.td"
include "Quantum/IR/QuantumTypes.td"

def RxOp : RestrictedQuantumOp<"rx", [AttrSizedOperandSegments]> {
    let arguments = (ins Variadic<QubitType>:$qubits, Variadic<F64>:$params);
    let results = (outs Variadic<AnyTypeOf<[ResultType, QubitType]>>:$result);
}

def RyOp : RestrictedQuantumOp<"ry", [AttrSizedOperandSegments]> {
    let arguments = (ins Variadic<QubitType>:$qubits, Variadic<F64>:$params);
    let results = (outs Variadic<AnyTypeOf<[ResultType, QubitType]>>:$result);
}

def RzOp : RestrictedQuantumOp<"rz", [AttrSizedOperandSegments]> {
    let arguments = (ins Variadic<QubitType>:$qubits, Variadic<F64>:$params);
    let results = (outs Variadic<AnyTypeOf<[ResultType, QubitType]>>:$result);
}
def Cx : RestrictedQuantumOp<"cx", [AttrSizedOperandSegments]> {
    let arguments = (ins Variadic<QubitType>:$qubits,Variadic<F64>:$params);
    let results = (outs Variadic<AnyTypeOf<[ResultType, QubitType]>>:$result);
}


#endif // Restricted_Quantum_OPS