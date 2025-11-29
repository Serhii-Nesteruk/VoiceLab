#pragma once

#include <functional>

#include "UiAction.h"

class UiActionBus
{
public:
    using Callback = std::function<void(UiAction)>;

    int subscribe(Callback callback);
    void unsubscribe(int id);
    void post(UiAction action);
private:
    std::unordered_map<int, Callback> _listeners;
    int _nextId = 1;
};