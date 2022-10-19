add_mlir_library(RestQuantumMLIRConversionPass
        LowerToRestQuantum.cpp

        DEPENDS
        QuantumMLIRQuantumPassIncGen

        LINK_COMPONENTS
        Core
        LINK_LIBS PUBLIC
        MLIRIR
        MLIRPass
        MLIRTransforms
        )