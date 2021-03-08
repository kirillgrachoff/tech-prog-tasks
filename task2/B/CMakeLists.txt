cmake_minimum_required(VERSION 3.10)

project(GreeterProject)

set(SOURCE_LIB lib.cpp)
add_library(Greeter SHARED ${SOURCE_LIB})
