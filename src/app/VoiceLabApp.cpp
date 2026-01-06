#include "VoiceLabApp.h"
#include "GlfwWindow.h"
#include "views/FileDialog.h"

VoiceLabApp::VoiceLabApp(GlfwWindow& window)
    : _window(window),
      _actionBus(),
      _subPool(_actionBus),
      _controller(_actionBus, _subPool),
      _mainView(_actionBus),
      _enrolmentView(_actionBus),
      _verificationView(_actionBus)
{
}

void VoiceLabApp::render()
{
    switch (AppState::currentView)
    {
    case ViewId::Main:
        _mainView.render();
        break;
    case ViewId::Enrolment:
        _enrolmentView.render();
        break;
    case ViewId::Verification:
        _verificationView.render();
        break;
    }

    FileDialog::renderFileDialog(AppState::currentFileDialogId);
}

bool VoiceLabApp::shouldClose() const
{
    return !AppState::isRunning || _window.shouldClose();
}
