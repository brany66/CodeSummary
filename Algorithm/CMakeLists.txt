cmake_minimum_required(VERSION 3.3)
project(Algorithm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES leetcode-contest-1/LexicographicalNumbers.cpp)
add_executable(Algorithm ${SOURCE_FILES})