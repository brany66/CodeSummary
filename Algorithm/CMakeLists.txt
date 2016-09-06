cmake_minimum_required(VERSION 3.3)
project(Algorithm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES JD/luckNumber.cpp BeautyOfProgramming/Chapter3/treeMaxLen.cpp)
add_executable(Algorithm ${SOURCE_FILES})