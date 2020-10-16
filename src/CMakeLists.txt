file(GLOB_RECURSE SOURCES "*.c")
file(GLOB_RECURSE SOURCES_CPP "*.cpp")
add_library(src ${SOURCES} ${SOURCES_CPP})

add_executable(${TARGET} main.c)
target_link_libraries(${TARGET} src lib)
