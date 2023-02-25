#ifndef Quantum_OPS
#define Quantum_OPS

include "QuantumDialect.td"
include "mlir/Interfaces/SideEffectInterfaces.td"

def QallocOp : QuantumOp<"qalloc", []> {
    let arguments = (ins AnyI64Attr:$size, StrAttr:$name, AnyI32Attr:$offset);
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

def MzOp: QuantumOp<"mz"> {
    let arguments = (ins QubitType: $qubit);
    let results = (outs I1: $bit_result);
}

def GenGate : QuantumOp<"gen_gate", [AttrSizedOperandSegments]> {
    let arguments = (ins StrAttr:$name, Variadic<QubitType>:$qubits, Variadic<F64>:$params);
    let results = (outs Variadic<AnyTypeOf<[ResultType, QubitType]>>:$result);
}

//pauli matrices
def XOp: SingleSimpleGate<"XOp">;
def YOp: SingleSimpleGate<"YOp">;
def ZOp: SingleSimpleGate<"ZOp">;
def IOp: SingleSimpleGate<"IOp">;

def HOp: SingleSimpleGate<"HOp">; //hadamard gate

def SOp: SingleSimpleGate<"SOp">; //phase gate
def TOp: SingleSimpleGate<"TOp">;

def RxOp : RotationGate<"RxOp">;
def RyOp : RotationGate<"RyOp">;
def RzOp : RotationGate<"RzOp">;

def CXOp : QuantumOp<"CX", [NoMemoryEffect]> {
    let arguments = (ins QubitType: $qubit1, QubitType: $qubit2);
    let results = (outs QubitType: $control, QubitType: $sink);
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