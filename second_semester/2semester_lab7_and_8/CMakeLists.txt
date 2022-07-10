cmake_minimum_required(VERSION 3.20)
project(2semester_lab7_and_8)

set(CMAKE_CXX_STANDARD 14)
include_directories("inc/")
include_directories("src/")
add_executable(2semester_lab7_and_8 main.cpp inc/matrix.h)
