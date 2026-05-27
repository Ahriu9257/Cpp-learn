//
// Created by ahriu on 2026/5/27.
//

#ifndef CH06SENSORS_REGISTRY_H
#define CH06SENSORS_REGISTRY_H

#pragma once
#include <memory>
#include <unordered_map>

#include "ISensor.h"
#include "MockSensors.h"

class Registry
{
public:
    bool registerSensor(const std::string& name, std::unique_ptr<ISensor> sensors);

    bool read_name(const std::string& name);

    void list_all() const;

private:
    std::unordered_map<std::string, std::unique_ptr<ISensor>> sensors_;
};


#endif //CH06SENSORS_REGISTRY_H
