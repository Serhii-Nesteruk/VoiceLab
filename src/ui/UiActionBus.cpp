#include "UiActionBus.h"

int UiActionBus::subscribe(Callback callback)
{
    int id = ++_nextId;
    _listeners.emplace(_nextId, callback);
    return id;
}

void UiActionBus::unsubscribe(int id)
{
    _listeners.erase(id);
}

void UiActionBus::post(UiAction action)
{
    for (auto l : _listeners)
    {
        l.second(action);
    }
}
