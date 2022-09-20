add_mlir_library(MLIRRestrictedQuantum
        RestrictedQuantumDialect.cpp
        RestrictedQuantumOps.cpp

        ADDITIONAL_HEADER_DIRS

        DEPENDS
        MLIRRestrictedQuantumOpsIncGen

        LINK_LIBS PUBLIC
        MLIRIR
        )