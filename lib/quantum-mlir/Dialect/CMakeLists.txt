add_subdirectory(Quantum)
add_subdirectory(RestrictedQuantum)
add_mlir_library(QUANTUM_DIALECTS
        Dialects.cpp
        LINK_COMPONENTS
        Core

        LINK_LIBS PUBLIC
        MLIRRestrictedQuantum
        MLIRQuantum

)