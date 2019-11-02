cmake_minimum_required(VERSION 3.0.0)
project(test)

# 设置boost库路径
set(BOOST_INCLUDE "/home/boost/include")
set(BOOST_LIB "/home/boost/lib")

# 设置头文件的路径
include_directories(${BOOST_INCLUDE})
# 设置链接库的路径
link_directories(${${BOOST_LIB}})
link_libraries(shared_thread)

# 生成静态库
add_executable(TEST test.cpp)
