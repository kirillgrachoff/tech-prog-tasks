cmake_minimum_required(VERSION 3.13)
project(TheBufferLib)
add_library(buffer SHARED buffer.cpp)
target_include_directories(buffer PUBLIC ${PROJECT_SOURCE_DIR}/../include)
