cmake_minimum_required(VERSION 3.4)
project(formatter_ex)

set(CMAKE_CXX_STANDERD 11)
set(CMAKE_CXX_STANDERD_REQUIRED ON)
add_library(formatter_ex STATIC formatter_ex.cpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include
