//
// Created by ahriu on 2026/5/25.
//
#include "EventBus.h"

void EventBus::subscribe(std::function<void(int)>callback)
{
    callbacks_.push_back(callback);
}

void EventBus::emit(int value)
{
    for (auto& callback : callbacks_)
    {
        callback(value);
    }
}
