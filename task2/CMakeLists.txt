cmake_minimum_required(VERSION 3.10)
project(task-cmake)

#set(CMAKE_CXX_COMPILER /usr/bin/g++)
#set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_BUILD_TYPE DEBUG)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wduplicated-cond -Wduplicated-branches -Wshadow=compatible-local")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=undefined -fsanitize=address -g")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")

#add_executable(main main.cpp)
#add_precompile_headers(main PUBLIC <bits/stdc++.h>)
