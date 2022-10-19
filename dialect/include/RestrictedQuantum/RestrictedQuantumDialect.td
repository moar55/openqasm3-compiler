#ifndef RESTRICTED_QUANTUM_DIALECT
#define RESTRICTED_QUANTUM_DIALECT

include "mlir/IR/OpBase.td"

//===----------------------------------------------------------------------===//
// Restricted quantum dialect definition.
//===----------------------------------------------------------------------===//

def RestrictedQuantumDialect : Dialect {
    let name = "restquantum";
    let summary = "A restricted MLIR dialect for quantum assembly languages.";
    let description = [{
        This dialect provides operations specific to quantum assembly languages.
    }];
    let cppNamespace = "::mlir::restquantum";
}

//===----------------------------------------------------------------------===//
// Base standalone operation definition.
//===----------------------------------------------------------------------===//

class RestrictedQuantumOp<string mnemonic, list<Trait> traits = []> :
        Op<RestrictedQuantumDialect, mnemonic, traits>;

#endif // RESTRICTED_QUANTUM_DIALECT