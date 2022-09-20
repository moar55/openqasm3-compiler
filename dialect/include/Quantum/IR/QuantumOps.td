#ifndef Quantum_OPS
#define Quantum_OPS

include "QuantumDialect.td"

def QubitType : OpaqueType<"quantum", "Qubit", "opaque qubit type">;
def ResultType : OpaqueType<"quantum", "Result", "opaque result type">;
def ArrayType : OpaqueType<"quantum", "Array", "opaque array type">;

def QallocOp : QuantumOp<"qalloc", []> {
    let arguments = (ins AnyI64Attr:$size, StrAttr:$name);
    let results = (outs ArrayType:$qubits);
}

def ExtractQubitOp : QuantumOp<"qextract", []> {
    let arguments = (ins ArrayType:$qreg, AnyInteger:$idx);
    let results = (outs QubitType:$qbit);
}

def GeneralArrayExtractOp : QuantumOp<"array_extract", []> {
    let arguments = (ins ArrayType:$array, AnyInteger:$idx);
    let results = (outs AnyType:$element);
}

def InstOp : QuantumOp<"inst", [AttrSizedOperandSegments]> {
    let arguments = (ins StrAttr:$name, Variadic<QubitType>:$qubits, Variadic<F64>:$params);
    let results = (outs Optional<ResultType>:$bit);
}

def ValueSemanticsInstOp : QuantumOp<"value_inst", [AttrSizedOperandSegments]> {
    let arguments = (ins StrAttr:$name, Variadic<QubitType>:$qubits, Variadic<F64>:$params);
    let results = (outs Variadic<AnyTypeOf<[ResultType, QubitType]>>:$result);
}

def DeallocOp : QuantumOp<"dealloc", []> {
    let arguments = (ins ArrayType:$qubits);
    let results = (outs);
}

def IntegerCastOp : QuantumOp<"integerCast", []> {
    let arguments = (ins AnyInteger:$input);
    let results = (outs AnyInteger:$output);
}


def ResultCastOp : QuantumOp<"resultCast", []> {
    let arguments = (ins ResultType:$measure_result);
    let results = (outs I1:$bit_result);
}


#endif // Quantum_OPS