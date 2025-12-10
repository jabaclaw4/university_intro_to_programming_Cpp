cmake_minimum_required(VERSION 3.28)
project(university_intro_to_programming_pp)

set(CMAKE_CXX_STANDARD 17)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_executable(university_intro_to_programming_pp main.cpp
src/point.cpp
src/vector.cpp)
