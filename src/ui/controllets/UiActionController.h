#pragma once
#include <string>

#include "AppState.h"
#include "UiActionBus.h"
#include "UiSubscriptionPool.h"

class UiActionController {
public:
    explicit UiActionController(UiActionBus& actionBus, UiSubscriptionPool& subPool);

private:
    void handleAction(UiAction action);

    UiActionBus& _actionBus;
    UiSubscriptionPool& _subPool;
};
