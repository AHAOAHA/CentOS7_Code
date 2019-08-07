cmake_minimum_required(VERSION 3.10)
project(cmake-demo3)

#告诉编译器第三方库头文件所在的路径
include_directories(/home/ahaoozhang/dev_code/c++/cmake-demo/cmake-demo3/include)

#告诉编译器第三方库所在的路径
link_directories(/home/ahaoozhang/dev_code/c++/cmake-demo/cmake-demo3/lib)

message(STATUS "cmake project name: ${CMAKE_PROJECT_NAME}")

#生成可执行文件
add_executable(${CMAKE_PROJECT_NAME} main.cpp)

#告诉编译器要链接哪些库
target_link_libraries(${CMAKE_PROJECT_NAME} hello)
