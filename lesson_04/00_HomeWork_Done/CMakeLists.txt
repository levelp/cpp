cmake_minimum_required(VERSION 3.1)
project(00_HomeWork_Done)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.cpp
    task.cpp)

add_executable(00_HomeWork_Done ${SOURCE_FILES})