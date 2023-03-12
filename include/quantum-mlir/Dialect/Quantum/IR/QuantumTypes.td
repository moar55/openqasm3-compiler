#ifndef QUANTUM_TYPES
#define QUANTUM_TYPES

include "mlir/IR/BuiltinTypes.td"

def QubitType : OpaqueType<"quantum", "Qubit", "opaque qubit type">;
def ResultType : OpaqueType<"quantum", "Result", "opaque result type">;
def QubitArrayType : OpaqueType<"quantum", "QubitArray", "opaque array type">;

#endif // QUANTUM_TYPES