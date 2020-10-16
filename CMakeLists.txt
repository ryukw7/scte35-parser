cmake_minimum_required(VERSION 3.17)
project(scte35-parser)

file(GLOB SOURCES "src/*.c")

add_executable(scte35-parser ${SOURCES})

add_subdirectory(test)
