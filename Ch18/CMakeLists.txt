cmake_minimum_required(VERSION 3.16)

project(Ch18ConfigReader)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main
        main.cpp
        ConfigReader.cpp
)

configure_file(app.conf app.conf COPYONLY)
