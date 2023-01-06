add_subdirectory(Conversion)
add_subdirectory(Dialect)
add_mlir_library(QUANTUM_MLIR
        quantum-mlir.cpp
        LINK_COMPONENTS
        Core

        LINK_LIBS PUBLIC
        QUANTUM_DIALECTS
        ConversionPasses
        )