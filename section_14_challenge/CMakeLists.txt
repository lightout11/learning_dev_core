cmake_minimum_required(VERSION 3.22)

project(section_14_challenge)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB src
    "./source/*.h"
    "./source/*.cpp"
)

add_executable(main ${src})