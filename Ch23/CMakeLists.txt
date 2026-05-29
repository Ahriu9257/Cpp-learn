cmake_minimum_required(VERSION 3.16)

project(Ch23ThreadPool)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(thread_pool_test
        ThreadPool.cpp
        thread_pool_test.cpp
)

target_compile_options(thread_pool_test PRIVATE -Wall -Wextra -pthread)
target_link_libraries(thread_pool_test PRIVATE pthread)
