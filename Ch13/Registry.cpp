//
// Created by ahriu on 2026/5/27.
//

#include "Registry.h"

#include <iostream>

bool Registry::registerSensor(const std::string& name,
                              std::unique_ptr<ISensor> sensors)
{
    if (!sensors)
    {
        std::cout << "[ERROR] cannot find the sensor ptr :" << name << std::endl;
        return false;
    }

    auto it = sensors_.find(name);
    if (it != sensors_.end())
    {
        std::cout << "[ERROR] sensor already registered: " << name << std::endl;
        return false;
    }

    sensors_.insert(std::make_pair(name, std::move(sensors)));
    std::cout << "[INFO] Registered sensor: " << name << std::endl;

    return true;
}

bool Registry::read_name(const std::string& name)
{
    auto it = sensors_.find(name);
    if (it == sensors_.end())
    {
        std::cout << "[ERROR] cannot find the sensor: " << name << std::endl;
        return false;
    }

    const auto& sensor = it->second;
    std::cout << "[INFO] Read sensor: " << name
              << ", value = " << sensor->read() << std::endl;

    return true;
}

void Registry::list_all() const
{
    std::cout << "[INFO] Listing all sensors" << std::endl;

    for (auto& it : sensors_)
    {
        std::cout << "[INFO] Sensor name: " << it.first << std::endl;
    }
    std::cout << "[INFO] Sensors registered" << std::endl;
}
