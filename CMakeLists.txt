cmake_minimum_required(VERSION 3.19)
project(LogicCalculator)

set(CMAKE_CXX_STANDARD 14)

add_executable(LogicCalculator
        src/main.cpp
        src/Functions.cpp src/Functions.h)
