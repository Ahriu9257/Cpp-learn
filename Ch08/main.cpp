//
// Created by ahriu on 2026/5/23.
//
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>
#include <ostream>
#include <vector>

#include "MockTempSensor.h"
#include "AP3216Csensor.h"
#include "ISensor.h"

int main()
{
    std::vector<std::unique_ptr<ISensor>> sensors;

    sensors.push_back(std::make_unique<AP3216C>());
    sensors.push_back(std::make_unique<MockTempSensor>());

    for (const auto& sensor : sensors)
    {
        std::cout << sensor->name() << "read value = " << sensor->read() << std::endl;
    }

    std::cout << "programe is ending" << std::endl;

    return 0;
}