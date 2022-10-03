add_subdirectory(Quantum)
add_subdirectory(RestrictedQuantum)
add_subdirectory(Conversion)

add_mlir_library(hoba
        Init.cpp
        PassImp.h
        LINK_COMPONENTS
        Core

        LINK_LIBS PUBLIC
        MLIRQuantum
        MLIRRestrictedQuantum
        RestQuantumMLIRConversionPass
        )