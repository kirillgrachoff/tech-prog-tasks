project(B)

add_library(ClassLib SHARED lib.cpp)
target_include_directories(ClassLib PUBLIC ${PROJECT_SOURCE_DIR})

INSTALL(
    TARGETS ClassLib
    RUNTIME DESTINATION exe/bin
    LIBRARY DESTINATION exe/lib
)
