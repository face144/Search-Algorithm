cmake_minimum_required(VERSION 3.20)
project(Search_Algorithm)

set(CMAKE_CXX_STANDARD 23)

add_executable(Search_Algorithm main.cpp Search.cpp Search.h Node.cpp Node.h Grid.cpp Grid.h)
