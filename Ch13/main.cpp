//
// Created by ahriu on 2026/5/27.
//
#include <iostream>
#include <ostream>

#include "Registry.h"

int main ()
{
    Registry sensors;

    sensors.registerSensor("light" , std::make_unique<LightSensor>());
    sensors.registerSensor("temp" , std::make_unique<TempSensor>());
    sensors.registerSensor("proximity" , std::make_unique<ProximitySensor>());

    std::cout << std::endl;

    sensors.list_all();

    std::cout << std::endl;

    sensors.read_name("light");
    std::cout << std::endl;
    sensors.read_name("temp");
    std::cout << std::endl;
    sensors.read_name("proximity");
    std::cout << std::endl;

    sensors.read_name("imu");

    return 0;
}