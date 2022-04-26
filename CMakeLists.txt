# minimum required CMAKE version
CMAKE_MINIMUM_REQUIRED(VERSION 3.7 FATAL_ERROR)

project(thesis)

if (POLICY CMP0114)
    cmake_policy(SET CMP0114 OLD)
endif()

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# compiler must be 11 or 14
set(CMAKE_CXX_STANDARD 11)

# required if linking to static library
add_definitions(-DANTLR4CPP_STATIC)

# using /MD flag for antlr4_runtime (for Visual C++ compilers only)
set(ANTLR4_WITH_STATIC_CRT OFF)
# add external build for antlrcpp
include(ExternalAntlr4Cpp.cmake)
# add antrl4cpp artifacts to project environment
include_directories(${ANTLR4_INCLUDE_DIRS})

# set variable pointing to the antlr tool that supports C++
# this is not required if the jar file can be found under PATH environment
#set(ANTLR_EXECUTABLE /home/moar/antlr-4.9.3-complete.jar)
# add macros to generate ANTLR Cpp code from grammar
#find_package(ANTLR REQUIRED)

# Call macro to add lexer and grammar to your build dependencies.
#antlr_target(SampleGrammarLexer TLexer.g4 LEXER
#        PACKAGE antlrcpptest)
#antlr_target(SampleGrammarParser TParser.g4 PARSER
#        PACKAGE antlrcpptest
#        DEPENDS_ANTLR SampleGrammarLexer
#        COMPILE_FLAGS -lib ${ANTLR_SampleGrammarLexer_OUTPUT_DIR})

# include generated files in project environment
include_directories(${ANTLR_SampleGrammarLexer_OUTPUT_DIR})
include_directories(${ANTLR_SampleGrammarParser_OUTPUT_DIR})

## Attempt to take these as command line arguments. IF that fails,
## lookup environment.
IF(NOT MLIR_INCLUDE_PATH)
    set (MLIR_INCLUDE_PATH /home/moar/llvm-project/build/include/llvm)
endif()

IF(NOT MLIR_LIBRARY_PATH)
    set (MLIR_LIBRARY_PATH /home/moar/llvm-project/build/lib)
endif()
include_directories(${MLIR_INCLUDE_PATH})
find_library(MLIRAnalysis MLIRAnalysis ${MLIR_LIBRARY_PATH})
find_library(MLIRIR MLIRIR ${MLIR_LIBRARY_PATH})
find_library(MLIRParser MLIRParser ${MLIR_LIBRARY_PATH})
find_library(MLIRSideEffects MLIRSideEffects ${MLIR_LIBRARY_PATH})
find_library(MLIRTransforms MLIRTransforms ${MLIR_LIBRARY_PATH})
find_library(LLVMCore LLVMCore ${MLIR_LIBRARY_PATH})
find_library(LLVMSupport LLVMSupport ${MLIR_LIBRARY_PATH})

## debugging to check if it's been set properly
message(MLIR_INCLUDE_PATH ${MLIR_INCLUDE_PATH})
message(MLIR_LIBRARY_PATH ${MLIR_LIBRARY_PATH})
message(MLIRAnalysis ${MLIRAnalysis})

# add generated grammar to demo binary target
add_executable(thesis main.cpp
        ${ANTLR_SampleGrammarLexer_CXX_OUTPUTS}
        ${ANTLR_SampleGrammarParser_CXX_OUTPUTS})

target_link_libraries(thesis antlr4_static
        ${MLIRAnalysis}
        ${MLIRIR}
        ${MLIRParser}
        ${MLIRTransforms}
        ${LLVMCore}
        ${LLVMSupport})