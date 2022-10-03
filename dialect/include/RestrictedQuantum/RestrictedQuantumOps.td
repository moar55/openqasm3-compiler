#ifndef Restricted_Quantum_OPS
#define Restricted_Quantum_OPS

include "RestrictedQuantumDialect.td"
include "Quantum/IR/QuantumTypes.td"

def QallocOp : RestrictedQuantumOp<"qalloc", []> {
    let arguments = (ins AnyI64Attr:$size, StrAttr:$name);
    let results =   (outs ArrayType:$qubits);
}

def ExtractQubitOp : RestrictedQuantumOp<"qextract", []> {
    let arguments = (ins ArrayType:$qreg, AnyInteger:$idx);
    let results = (outs QubitType:$qbit);
}

def GeneralArrayExtractOp : RestrictedQuantumOp<"array_extract", []> {
    let arguments = (ins ArrayType:$array, AnyInteger:$idx);
    let results = (outs AnyType:$element);
}

def InstOp : RestrictedQuantumOp<"inst", [AttrSizedOperandSegments]> {
    let arguments = (ins StrAttr:$name, Variadic<QubitType>:$qubits, Variadic<F64>:$params);
    let results = (outs Optional<ResultType>:$bit);
}

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