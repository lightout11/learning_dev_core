cmake_minimum_required(VERSION 3.16)

project(section_20_challenge_2)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB src
    "./source/*.h"
    "./source/*.hh"
    "./source/*.cpp"
    "./source/*.hpp"
    "./source/*.cxx"
    "./source/*.hxx"
)

add_executable(main ${src})