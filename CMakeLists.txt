cmake_minimum_required(VERSION 3.17)
project(scte35-parser)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)

set(TARGET scte35-parser)

add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(test)
