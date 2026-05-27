//
// Created by ahriu on 2026/5/27.
//
#include <iostream>
#include <ostream>

#include "History.h"

int main()
{
    History history(5);

    for (int i = 1; i <= 10; i++)
    {
        float value = static_cast<float>(i * 10);

        history.push(value);
        history.print();

        std::cout << "average = " << history.average() << std::endl
        << "size = " << history.size() << std::endl
        << "capacity = " << history.capacity() << std::endl;

        std::cout << " ------------------- " << std::endl;
    }
    return 0;
}