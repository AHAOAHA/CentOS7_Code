project(HELLO)
set(CMAKE_VERBOSE_MAKEFILE on)
set(SRC_LIST main.c)

message(STATUS "this is Binary dir" ${HELLO_BINARY_DIR})
message(STATUS "this is Source dir" ${HELLO_SOURCE_DIR})
add_executable(hello ${SRC_LIST})
