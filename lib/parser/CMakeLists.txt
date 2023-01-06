file(GLOB SRC *.cpp generated/*.cpp visitor_handlers/*.cpp utils/*.cpp)
add_library(generator ${SRC} visitor_handlers/function_handler.cpp)
target_precompile_headers(generator
        PUBLIC generated/qasmVisitor.h
        PUBLIC visitor_handlers/expression_handler.h)