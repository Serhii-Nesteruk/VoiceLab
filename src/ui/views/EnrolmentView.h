#pragma once
#include "IView.h"

class UiActionBus;

class EnrolmentView : public IView {
public:
    explicit EnrolmentView(UiActionBus& actionBus);
    void render() override;

private:
    UiActionBus& _actionBus;
};
