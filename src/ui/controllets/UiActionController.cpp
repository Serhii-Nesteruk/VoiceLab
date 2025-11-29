#include "UiActionController.h"

#include <iostream>
#include <bits/ostream.tcc>

UiActionController::UiActionController(UiActionBus& actionBus, UiSubscriptionPool& subPool)
    : _actionBus(actionBus), _subPool(subPool)
{
    int subId = _actionBus.subscribe([this](UiAction action)
    {
        handleAction(action);
    });

    _subPool.add(subId);
}

void UiActionController::handleAction(UiAction action)
{
    switch (action)
    {
    case UiAction::OpenEnrolmentView:
        AppState::currentView = ViewId::Enrolment;
        std::cout << "Enrl view" << std::endl;
        break;
    case UiAction::OpenVerificationView:
        AppState::currentView = ViewId::Verification;
        break;
    case UiAction::OpenMainView:
        AppState::currentView = ViewId::Main;
        break;
    case UiAction::ExitApplication:
        AppState::isRunning = false;
        break;
    }
}
