cmake_minimum_required(VERSION 3.16)

project(Ch22CMakeLibrary)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(mylib STATIC
        src/AP3216CSensor.cpp
        src/MockTempSensor.cpp
)

target_include_directories(mylib PUBLIC include)
target_compile_options(mylib PRIVATE -Wall -Wextra)

add_executable(app
        app/main.cpp
)

target_link_libraries(app PRIVATE mylib)
target_compile_options(app PRIVATE -Wall -Wextra)
