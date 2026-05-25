//
// Created by ahriu on 2026/5/24.
//
#include <iostream>

#include "FileHandle.h"

void normal_case()
{
    std::cout << "normal_case begin" << std::endl;

    FileHandle file("log.txt","w");

    file.write("Hello RAII!\n");
    file.write("the file will be closed automatically\n");

    std::cout << "normal_case end" << std::endl;
}

void exception_case()
{
    std::cout << "exception_case begin" << std::endl;

    FileHandle file("exception_log.txt","w");

    file.write("Before exception\n");

    throw std::runtime_error("something bad happend!");

    file.write("After exception\n");
}

void open_failed_case()
{
    std::cout << "open_failed_case begin" << std::endl;

    FileHandle file("/notasdwd/test.txt","w");

    file.write("you shoule not see this \n");
}

int main()
{
    try
    {
        normal_case();
    } catch (std::exception& e)
    {
        std::cout << "normal_case error " << e.what() << std::endl;
    }

    try
    {
        exception_case();
    } catch (std::exception& e)
    {
        std::cout << "exception_case cought: " << e.what() << std::endl;
    }

    try
    {
        open_failed_case();
    } catch (std::exception& e)
    {
        std::cout << "open_failed_case cought: " << e.what() << std::endl;
    }

    return 0;
}