file(GLOB SRC *.cpp generated/*.cpp visitor_handlers/*.cpp)
add_library(generator ${SRC})