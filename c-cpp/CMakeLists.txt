cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "-Wall -fmodules-ts")

project(projecteuler)
include_directories(external/benchmark/include)

include(cmake/StripFilename.cmake)

add_subdirectory(c)
add_subdirectory(cpp)
add_subdirectory(benchmark)

add_subdirectory(external/googletest)
add_subdirectory(external/benchmark)
