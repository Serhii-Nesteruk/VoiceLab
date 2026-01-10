#include "VerificationView.h"

#include <filesystem>
#include <iostream>
#include <string>

#include "AppState.h"
#include "FileDialog.h"

VerificationView::VerificationView(UiActionBus& actionBus)
    : VoiceScreenViewBase(actionBus)
{
}

const char* VerificationView::windowTitle() const 
{
    return "Voice Lab - Verification";
}

const char* VerificationView::mainTitle() const 
{
    return "Sign in with voice (verification)";
}

std::string VerificationView::subtitle() const
{
    std::string modelSpeakerPath = FileDialog::getSelectedFileByDialogId("ChooseModelSpeaker");
    std::string speakerToVerifyPath = FileDialog::getSelectedFileByDialogId("ChooseSpeakerToVerify");

    const std::string modelSpeakerName =
           modelSpeakerPath.empty() ? "" : extractFileNameFromPath(modelSpeakerPath);

    const std::string speakerToVerifyName =
        speakerToVerifyPath.empty() ? "" : extractFileNameFromPath(speakerToVerifyPath);

    std::cout << speakerToVerifyName << std::endl;
    std::cout << modelSpeakerName << std::endl;

    return "Wybrany uzytkownik wzorcowy: " + modelSpeakerName + " "
           "Wybrany uzytkownik do weryfikacji: " + speakerToVerifyName;
}

const char* VerificationView::primaryButtonLabel() const
{
    return "Wybierz użytkownika wzorcowego";
}

void VerificationView::onPrimaryButton() 
{
    AppState::currentFileDialogId = "ChooseModelSpeaker";
    AppState::currentFileDialogMode = FileDialog::Mode::File;
    _actionBus.post(UiAction::OpenFileDialog);
}

const char* VerificationView::secondaryButtonLabel() const 
{
    return "Wybierz użytkownika do weryfikacji";
}

void VerificationView::onSecondaryButton() 
{
    AppState::currentFileDialogId = "ChooseSpeakerToVerify";
    AppState::currentFileDialogMode = FileDialog::Mode::File;
    _actionBus.post(UiAction::OpenFileDialog);
}

const char* VerificationView::thirdButtonLabel() const
{
    return "Weryfikuj";
}

void VerificationView::onThirdButton()
{
    _actionBus.post(UiAction::StartSpeakerVerification);
}
std::string VerificationView::extractFileNameFromPath(const std::string& filePath)
{
    return std::filesystem::path(filePath).filename().string();
}
