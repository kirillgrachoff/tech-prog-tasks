cmake_minimum_required(VERSION 3.10)

project(TP-Cmake-Task)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

# python generation
add_custom_command(
        OUTPUT ${PROJECT_SOURCE_DIR}/A/index.h
        COMMAND python3 ${PROJECT_SOURCE_DIR}/A/preparing.py ${PROJECT_SOURCE_DIR}/A/index.h
        DEPENDS ${PROJECT_SOURCE_DIR}/A/preparing.py
        COMMENT "Generating index.h"
)

add_custom_target(RunPreparing DEPENDS ${PROJECT_SOURCE_DIR}/A/index.h)

# subproject
add_subdirectory(B)

# main running
add_executable(C ${PROJECT_SOURCE_DIR}/C/main.cpp)
target_include_directories(C PUBLIC ${PROJECT_SOURCE_DIR})
add_dependencies(C RunPreparing)
target_link_libraries(C Greeter)

# main testing
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

add_executable(CTest ${PROJECT_SOURCE_DIR}/C/main_test.cpp)
target_include_directories(CTest PUBLIC ${GTEST_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR})
add_dependencies(CTest RunPreparing)
target_link_libraries(CTest ${GTEST_LIBRARIES} Threads::Threads Greeter)
