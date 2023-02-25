#ifndef QUANTUM_DIALECT
#define QUANTUM_DIALECT

include "mlir/IR/OpBase.td"
include "QuantumTypes.td"
include "mlir/Interfaces/SideEffectInterfaces.td"

//===----------------------------------------------------------------------===//
// Quantum dialect definition.
//===----------------------------------------------------------------------===//

def QuantumDialect : Dialect {
    let name = "quantum";
    let summary = "A MLIR dialect for quantum assembly languages.";
    let description = [{
        This dialect provides operations specific to quantum assembly languages.
    }];
    let cppNamespace = "::mlir::quantum";
    let hasCanonicalizer = 1;
}

//===----------------------------------------------------------------------===//
// Base standalone operation definition.
//===----------------------------------------------------------------------===//

class QuantumOp<string mnemonic, list<Trait> traits = []> :
        Op<QuantumDialect, mnemonic, traits>;


class SingleSimpleGate<string mnemonic> : QuantumOp<mnemonic> {
    let arguments = (ins QubitType:$qubit);
    let results = (outs QubitType:$result);
}


class RotationGate<string mnemonic> : QuantumOp<mnemonic, [NoMemoryEffect]> {
    let arguments = (ins QubitType:$qubit, F64:$angle);
    let results = (outs QubitType:$result);
}

#endif // QUANTUM_DIALECT