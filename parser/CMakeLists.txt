file(GLOB SRC *.cpp generated/*.cpp visitor_handlers/*.cpp utils/*.cpp)
add_library(generator ${SRC})