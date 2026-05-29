cmake_minimum_required(VERSION 3.16)

project(Ch24CInterop LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(mathlib STATIC
        mathlib.c
)

target_include_directories(mathlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(mathlib PRIVATE -Wall -Wextra)
target_link_libraries(mathlib PUBLIC m)

add_library(statistics STATIC
        Statistics.cpp
)

target_include_directories(statistics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(statistics PUBLIC mathlib)
target_compile_options(statistics PRIVATE -Wall -Wextra)

add_executable(ch24_test
        test.cpp
)

target_link_libraries(ch24_test PRIVATE statistics)
target_compile_options(ch24_test PRIVATE -Wall -Wextra)

enable_testing()
add_test(NAME ch24_test COMMAND ch24_test)
