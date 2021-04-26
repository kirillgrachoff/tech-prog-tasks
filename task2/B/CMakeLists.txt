cmake_minimum_required(VERSION 3.10)

project(GreeterProject)

set(SOURCE_LIB ${PROJECT_SOURCE_DIR}/lib.cpp)

add_library(Greeter SHARED ${SOURCE_LIB})
target_include_directories(Greeter PUBLIC ${PROJECT_SOURCE_DIR})
