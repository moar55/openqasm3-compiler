add_mlir_library(MLIRQuantum
        QuantumDialect.cpp
        QuantumOps.cpp

        ADDITIONAL_HEADER_DIRS

        DEPENDS
        MLIRQuantumOpsIncGen
        MLIRQuantumTypesIncGen
        QuantumMLIRQOptimizeIncGen

        LINK_LIBS PUBLIC
        MLIRIR
        )