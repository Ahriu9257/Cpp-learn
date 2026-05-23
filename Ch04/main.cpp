//
// Created by ahriu on 2026/5/23.
//
#include "Sensor.h"

int main()
{
    Sensor sensor;

    sensor.set(123.45f, 100, 200);
    sensor.print();

    return 0;
}
