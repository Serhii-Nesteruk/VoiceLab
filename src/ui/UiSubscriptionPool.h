#pragma once

#include "UiActionBus.h"

class UiSubscriptionPool
{
public:
    explicit UiSubscriptionPool(UiActionBus& actionBus);
    ~UiSubscriptionPool();

    void add(int subId);

private:
    UiActionBus& _actionBus;
    std::vector<int> _ids;
};