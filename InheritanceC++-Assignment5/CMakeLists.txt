cmake_minimum_required(VERSION 3.15)
project(Assignment5)

set(CMAKE_CXX_STANDARD 14)
set(GOOD 1)

if(GOOD)
    add_executable(Assignment5 TestGoodShapes.cpp ShapesGood.cpp)
else()
    add_executable(Assignment5 TestBadShapes.cpp ShapesBad.cpp)
endif()