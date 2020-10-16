file(GLOB_RECURSE SOURCES "*.c")
file(GLOB_RECURSE SOURCES_CPP "*.cpp")
add_library(libScte35 ${SOURCES} ${SOURCES_CPP})
