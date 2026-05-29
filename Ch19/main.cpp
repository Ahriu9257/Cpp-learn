#include "mylib/sensor/AP3216CSensor.h"
#include "mylib/sensor/MockTempSensor.h"
#include "mylib/sensor/ISensor.h"
#include "mylib/sensor/SensorType.h"

#include <iostream>
#include <memory>
#include <string>
#include <vector>

namespace
{

std::string prefix_from_type(mylib::sensor::SensorType type)
{
    switch (type)
    {
    case mylib::sensor::SensorType::Light:
        return "[Light]";
    case mylib::sensor::SensorType::Temp:
        return "[Temp]";
    case mylib::sensor::SensorType::Proximity:
        return "[Proximity]";
    }

    return "[Unknown]";
}

} // namespace

int main()
{
    using mylib::sensor::MockTempSensor;
    using mylib::sensor::AP3216CSensor;
    using mylib::sensor::ISensor;

    std::vector<std::unique_ptr<ISensor>> sensors;
    sensors.push_back(std::make_unique<AP3216CSensor>(123.3));
    sensors.push_back(std::make_unique<MockTempSensor>(36.5));

    for (const auto& sensor : sensors)
    {
        std::cout << prefix_from_type(sensor->type())
                  << " " << sensor->name()
                  << " value = " << sensor->read()
                  << std::endl;
    }

    return 0;
}
