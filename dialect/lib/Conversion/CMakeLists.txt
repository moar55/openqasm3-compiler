add_mlir_library(RestQuantumMLIRConversionPass
        LowerToRestQuantum.cpp

        DEPENDS
        QuantumMLIRQuantumPassIncGen

        LINK_COMPONENTS
        Core

        LINK_LIBS PUBLIC
        ${linked_libs}
        #${torch_mlir_conversion_libs}
        )