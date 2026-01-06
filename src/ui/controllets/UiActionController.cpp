#include "UiActionController.h"

#include <iostream>
#include <bits/ostream.tcc>

#include <ImGuiFileDialog.h>

#include "views/FileDialog.h"

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
    case UiAction::OpenFileDialog:
        if (AppState::currentFileDialogId.empty())
        {
            throw std::runtime_error("File dialog id not provided");
        }
        FileDialog::initFileDialog(AppState::currentFileDialogId);
        AppState::openFileDialog = true;
        break;
    }
}
