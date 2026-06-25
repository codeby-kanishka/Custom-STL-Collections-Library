cmake_minimum_required(VERSION 3.10)

project(CustomSTL)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# header files location
include_directories(
    include/dynamicarray
    include/linkedlist
    include/hashmap
)


# testing executable
add_executable(
    CustomSTLTest

    tests/testdynamicarray.cpp
    tests/testlinkedlist.cpp
)