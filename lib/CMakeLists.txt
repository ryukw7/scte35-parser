file(GLOB_RECURSE SOURCES "*.c")
file(GLOB_RECURSE SOURCES_CPP "*.cpp")
add_library(lib ${SOURCES} ${SOURCES_CPP})
