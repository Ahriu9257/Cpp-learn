//
// Created by ahriu on 2026/5/25.
//
#include <iostream>
#include <memory>
#include <ostream>
#include <vector>

#include "ISensor.h"
#include "AP3216C.h"
#include "MockTempSensor.h"

std::string prefix_from_type(ISensorType type)
{
    switch (type)
    {
    case ISensorType::Light:
        return "[Light]";

    case ISensorType::Temp:
        return "[Temp]";

    case ISensorType::Proximity:
        return "[Proximity]";
    }

    return "unknow type";
}

int main()
{
    std::vector<std::unique_ptr<ISensor>> sensors;

    sensors.push_back(std::make_unique<AP3216C>());
    sensors.push_back(std::make_unique<MockTempSensor>());

    for (auto& sensor : sensors)
    {
        const auto prefix = prefix_from_type(sensor->sensorType());
        const auto value = sensor->read();

        std::cout << prefix << sensor->name() << "value = " << value << std::endl;
    }

    return 0;
}