//
// Created by ahriu on 2026/5/25.
//
#include <iostream>

#include "EventBus.h"

int main()
{
    EventBus eventBus;

    int count = 0;

    eventBus.subscribe([&count](int value)
    {
       count++;
        std::cout << "callback1 value = " << value
        << " count = " << count << std::endl;
    });

    eventBus.subscribe([](int value)
    {
        std::cout << "callback2 received " << value << std::endl;
    });

    eventBus.emit(42);
    eventBus.emit(100);

    std::cout << "final count = " << count << std::endl;

    return 0;
}