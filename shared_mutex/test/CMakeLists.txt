cmake_minimum_required(VERSION 3.0.0)
project(test)

link_directories("/home/ahaoozhang/dev_code/c++/shared_mutex/test")
link_libraries(rw_mutex)

add_compile_options(-std=c++11 -lpthread)

# 生成静态库
add_executable(test_1 test.cpp)


target_link_libraries(test rw_mutex pthread)