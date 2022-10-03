set(LLVM_TARGET_DEFINITIONS QuantumTypes.td)
mlir_tablegen(QuantumTypes.h.inc -gen-typedef-decls)
mlir_tablegen(QuantumTypes.cpp.inc -gen-typedef-defs)
add_public_tablegen_target(MLIRQuantumTypesIncGen)

add_mlir_dialect(QuantumOps quantum)
add_mlir_doc(QuantumDialect -gen-dialect-doc QuantumDialect Quantum/)
add_mlir_doc(QuantumOps -gen-op-doc QuantumOps Quantum/)