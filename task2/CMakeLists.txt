cmake_minimum_required(VERSION 3.10)

project(TP-Cmake-Task)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

# python generation
add_custom_command(
        OUTPUT ${CMAKE_SOURCE_DIR}/A/index.h
        COMMAND python3 ${PROJECT_SOURCE_DIR}/A/preparing.py ${CMAKE_SOURCE_DIR}/A/index.h
        DEPENDS ${PROJECT_SOURCE_DIR}/A/preparing.py
        COMMENT "Generating index.h"
)

add_custom_target(RunPreparing DEPENDS ${PROJECT_SOURCE_DIR}/A/index.h)

# subproject
add_subdirectory(B)

# main running
include_directories(${PROJECT_SOURCE_DIR})
add_executable(main ${PROJECT_SOURCE_DIR}/C/main.cpp)
add_dependencies(main RunPreparing)
target_link_libraries(main Greeter)

# main testing
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(CTest ${PROJECT_SOURCE_DIR}/C/main_test.cpp)
add_dependencies(CTest RunPreparing)
target_link_libraries(CTest ${GTEST_LIBRARIES} pthread Greeter)
