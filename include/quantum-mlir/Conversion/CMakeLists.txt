set(LLVM_TARGET_DEFINITIONS Passes.td)
mlir_tablegen(Passes.h.inc -gen-pass-decls)
add_public_tablegen_target(QuantumMLIRQuantumPassIncGen)

add_mlir_doc(Passes Quantum QuantumMLIRQuantumTransforms ../Dialect/Quantum/Transforms -gen-pass-doc)