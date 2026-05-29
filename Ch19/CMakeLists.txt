cmake_minimum_required(VERSION 3.16)

project(Ch19SensorLibrary)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main
        main.cpp
        src/AP3216CSensor.cpp
        src/MockTempSensor.cpp
)

target_include_directories(main PRIVATE include)
