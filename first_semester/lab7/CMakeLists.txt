cmake_minimum_required(VERSION 3.20)
project(lab7)

set(CMAKE_CXX_STANDARD 17)
include_directories(inc)
add_executable(lab7 main.cpp
        src/Write.cpp
        src/Read.cpp
        src/Rabota_nad_mass.cpp)
