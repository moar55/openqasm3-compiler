#set(LLVM_ENABLE_RTTI ON)
add_llvm_executable(quantum-opt quantum-opt.cpp)
#add_llvm_executable(quantum-opt quantum-opt.cpp)
llvm_update_compile_flags(quantum-opt)

target_include_directories(quantum-opt
        PRIVATE
        ${ANTLR4_INCLUDE_DIRS}
        ../parser
        ../dialect/lib
#        ../parser/generated
        )

target_link_libraries(quantum-opt
        PRIVATE
        MLIRAnalysis
        MLIRMemRef
        MLIRIR
        MLIRArithmetic
        MLIRParser
        MLIRPass
        MLIRRewrite
        MLIRFuncTransforms
        MLIRSideEffectInterfaces
        MLIRTransforms
        hoba
        generator
        )

target_compile_options(quantum-opt PRIVATE -fexceptions)
mlir_check_all_link_libraries(quantum-opt)