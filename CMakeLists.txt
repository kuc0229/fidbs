cmake_minimum_required(VERSION 3.9)
project(fidbs)

set(CMAKE_CXX_STANDARD 11)

add_executable(fidbs include/fidbs/cTable.h src/cTable.cpp test/main.cpp)