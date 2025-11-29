#pragma once
#include "IView.h"
#include "UiActionBus.h"

class VerificationView : public IView {
public:
    explicit VerificationView(UiActionBus& actionBus);

    void render() override;

private:
    UiActionBus& _actionBus;
};
