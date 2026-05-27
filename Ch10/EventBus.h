//
// Created by ahriu on 2026/5/25.
//

#ifndef CH06SENSORS_EVENTBUS_H
#define CH06SENSORS_EVENTBUS_H

#pragma once
#include <functional>
#include <vector>

class EventBus
{
public:
    void subscribe(std::function<void(int)>callback);
    void emit(int value);

private:
    std::vector<std::function<void(int)>> callbacks_;
};

#endif //CH06SENSORS_EVENTBUS_H
