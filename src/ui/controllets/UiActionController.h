#pragma once
#include <string>

#include "AppState.h"
#include "UiActionBus.h"
#include "UiSubscriptionPool.h"

class UiActionController {
public:
    explicit UiActionController(UiActionBus& actionBus, UiSubscriptionPool& subPool);

    void renderFileDialog();
private:
    void handleAction(UiAction action);

    void requestOpenFileDialog();

    UiActionBus& _actionBus;
    UiSubscriptionPool& _subPool;

    std::string _selectedPath{};
    bool _openFileDialog = false;
};
