file(GLOB SRC *.cpp generated/*.cpp visitor_handlers/*.cpp utils/symbol_table.cpp)
add_library(generator ${SRC})