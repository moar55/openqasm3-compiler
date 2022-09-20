add_mlir_library(MLIRQuantum
        QuantumDialect.cpp
        QuantumOps.cpp

        ADDITIONAL_HEADER_DIRS

        DEPENDS
        MLIRQuantumOpsIncGen

        LINK_LIBS PUBLIC
        MLIRIR
        )