//
// Created by ahriu on 2026/5/23.
//
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <ostream>
#include <vector>

#include "MockTempSensor.h"
#include "AP3216Csensor.h"
#include "ISensor.h"

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::vector<ISensor*> sensors;

    // 用基类指针保存不同派生类对象，循环调用时触发多态。
    sensors.push_back(new AP3216C());
    sensors.push_back(new MockTempSensor());

    std::cout << "\nStart reading sensors:" << std::endl;

    for (ISensor* sensor : sensors)
    {
        std::cout << "\n[" << sensor->name() << "]" << std::endl;
        sensor->read();
    }

    std::cout << "\nDelete sensors:" << std::endl;
    for (ISensor* sensor : sensors)
    {
        // Ch06 保留手动 delete，Ch08 会改成 unique_ptr。
        delete sensor;
    }
    sensors.clear();

    return 0;
}
