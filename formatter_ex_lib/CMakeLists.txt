cmake_minimum_required(VERSION 3.4)
project(formatter_ex_lib)

set(CMAKE_CXX_STANDERD 11)
set(CMAKE_CXX_STANDERD_REQUIRED ON)
add_library(formatter_ex_lib STATIC formatter_ex.cpp)

target_include_directories(formatter_ex_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(formatter_ex_lib PUBLIC formatter_lib)
