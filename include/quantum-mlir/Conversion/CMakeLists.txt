set(LLVM_TARGET_DEFINITIONS Passes.td)
mlir_tablegen(Passes.h.inc -gen-pass-decls)
add_public_tablegen_target(QuantumMLIRQuantumPassIncGen)

set(LLVM_TARGET_DEFINITIONS Optimize.td)
include_directories(../Dialect/Quantum/IR)
mlir_tablegen(Optimize.h.inc -gen-rewriters)
add_public_tablegen_target(QuantumMLIRQOptimizeIncGen)


add_mlir_doc(Passes Quantum QuantumMLIRQuantumTransforms ../Dialect/Quantum/Transforms -gen-pass-doc)