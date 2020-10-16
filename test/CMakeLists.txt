cmake_minimum_required(VERSION 3.17)

if (${CMAKE_BUILD_TYPE} MATCHES Debug)
    set(CMAKE_CXX_STANDARD 17)

    set(TARGET scte35-parser-test)
    file(GLOB_RECURSE SOURCES "*.cpp")

    include_directories(libs)

    add_executable(${TARGET} main.cpp ${SOURCES})
endIf ()
