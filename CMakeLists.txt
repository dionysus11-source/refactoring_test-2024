cmake_minimum_required(VERSION 3.8)

set(CMAKE_FIND_LIBRARY_SUFFIXES ".dll" ".dll.a" ".a" ".lib")
set(CMAKE_FIND_LIBRARY_PREFIXES "cyg" "lib")

set(PROJECT TddExample)

project(${PROJECT})

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src)
add_subdirectory(googletest-1.14.0)
