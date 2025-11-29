#pragma once

#include "AppState.h"
#include "GlfwWindow.h"

#include "views/EnrolmentView.h"
#include "views/MainWindowView.h"
#include "views/VerificationView.h"

class VoiceLabApp
{
public:
    explicit VoiceLabApp(GlfwWindow& window);

    void render();

    [[nodiscard]] bool shouldClose() const;
private:
    MainWindowView _mainView;
    EnrolmentView _enrolmentView;
    VerificationView _verificationView;

    GlfwWindow& _window;

    UiActionBus _actionBus;
    UiSubscriptionPool _subPool;
    UiActionController _controller;
};
