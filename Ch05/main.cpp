//
// Created by ahriu on 2026/5/23.
//
#include <iostream>
#include <ostream>

#include "Sensor.h"

int main()
{
    std::cout << "program start" << std::endl;
    {
        // 栈对象离开作用域时自动析构。
        std::cout << "\nCreate stack object" << std::endl;
        Sensor stack_sensor(123.5f, 100, 200);
        stack_sensor.print();

        // 堆对象需要手动 delete；后续章节会改成智能指针。
        std::cout << "\nCreate heap object" << std::endl;
        Sensor* heap_sensor = new Sensor(86.5f, 201, 301);
        heap_sensor->print();

        std::cout << "\nDelete heap object" << std::endl;
        delete heap_sensor;

        std::cout << "\nLeaving inner scope" << std::endl;
    }

    std::cout << "\nProgram end" << std::endl;

    return 0;
}
