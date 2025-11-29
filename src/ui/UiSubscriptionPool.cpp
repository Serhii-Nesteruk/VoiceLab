#include "UiSubscriptionPool.h"

UiSubscriptionPool::UiSubscriptionPool(UiActionBus& actionBus)
    : _actionBus(actionBus)
{
}

UiSubscriptionPool::~UiSubscriptionPool()
{
    for (int id : _ids)
    {
        _actionBus.unsubscribe(id);
    }
}

void UiSubscriptionPool::add(int subId)
{
    _ids.push_back(subId);
}
