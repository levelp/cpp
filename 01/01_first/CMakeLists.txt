cmake_minimum_required(VERSION 3.1)
project(01_first)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    helloworld.c
    helloworld.cpp
    main.cpp)

add_executable(01_first ${SOURCE_FILES})