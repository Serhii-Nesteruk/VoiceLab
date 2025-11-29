#pragma once

#include "IView.h"
#include "controllets/UiActionController.h"

class MainWindowView : public IView {
public:
    explicit MainWindowView(UiActionBus& actionBus);

    void render() override;

private:
    void renderStartScreen();

    UiActionBus& _actionBus;
};
