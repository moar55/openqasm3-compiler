#set(LLVM_ENABLE_RTTI ON)
add_llvm_executable(quantum-opt quantum-opt.cpp)
#add_llvm_executable(quantum-opt quantum-opt.cpp)
llvm_update_compile_flags(quantum-opt)

target_include_directories(quantum-opt
        PRIVATE
        ${ANTLR4_INCLUDE_DIRS}
        ../lib/parser
        ../lib/quantum-mlir
#        ../parser/generated
        )

get_property(dialect_libs GLOBAL PROPERTY MLIR_DIALECT_LIBS)
get_property(conversion_libs GLOBAL PROPERTY MLIR_CONVERSION_LIBS)

target_link_libraries(quantum-opt
        PRIVATE
        ${dialect_libs}
        ${conversion_libs}
        MLIRAnalysis
        MLIRMemRefDialect
        MLIRMathDialect
        MLIRIR
        MLIRLLVMCommonConversion
        MLIRLLVMToLLVMIRTranslation
        MLIRParser
        MLIRPass
        MLIRRewrite
        MLIRFuncTransforms
        MLIRSideEffectInterfaces
        MLIRTransforms

        MLIRCallInterfaces
        MLIRCastInterfaces
        MLIRExecutionEngine
        MLIRLLVMCommonConversion
        MLIRLLVMToLLVMIRTranslation
        MLIRPass
        MLIRSideEffectInterfaces
        MLIRTargetLLVMIRExport

        QUANTUM_MLIR
        generator
        )

target_compile_options(quantum-opt PRIVATE -fexceptions)



mlir_check_all_link_libraries(quantum-opt)

target_precompile_headers(quantum-opt PRIVATE ./headers.h)
