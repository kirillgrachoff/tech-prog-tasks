cmake_minimum_required(VERSION 3.0)

if(${ARM_BUILD})
    # message(WARNING "the toolchain path is ${TOOLCHAIN}")
    set(CMAKE_FIND_ROOT_PATH ${TOOLCHAIN})
    set(CMAKE_CXX_COMPILER "${TOOLCHAIN}/aarch64-linux-gnu-g++")
    set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
    set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
    set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
endif()

project(SimpleLibrary)


if(${ARM_BUILD})
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib-arm)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib-arm)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin-arm)
else()
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
endif()
# message(WARNING "${CMAKE_RUNTIME_OUTPUT_DIRECTORY} ${CMAKE_LIBRARY_OUTPUT_DIRECTORY} ${PROJECT_SOURCE_DIR}")

include_directories(${PROJECT_SOURCE_DIR}/include)

set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

add_subdirectory(src)
add_executable(Main main.cpp)
add_executable(MainLib main_lib.cpp)

target_link_libraries(MainLib buffer)

install(TARGETS Main MainLib buffer
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)
