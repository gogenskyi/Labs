cmake_minimum_required(VERSION 4.3)
project(Labss)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Lab0)
include_directories(Lab1)
include_directories(Lab3)

add_executable(Labss
        Lab0/CMakeLists.txt
        Lab0/main.cpp
        Lab1/CMakeLists.txt
        Lab1/main.cpp
        Lab3/CMakeLists.txt
        Lab3/main.cpp)
