#include "EnrolmentView.h"

#include <filesystem>

#include "AppState.h"

EnrolmentView::EnrolmentView(UiActionBus& actionBus)
    : VoiceScreenViewBase(actionBus)
{
}

const char* EnrolmentView::windowTitle() const 
{
    return "Voice Lab - Enrolment";
}

const char* EnrolmentView::mainTitle() const 
{
    return "Create voice profile (enrolment)";
}

std::string EnrolmentView::subtitle() const
{
    return "Record or import reference speech samples to build a voice template.";
}

const char* EnrolmentView::primaryButtonLabel() const 
{
    return "Wybierz folder z wzorcami głosowymi użytkownika";
}

void EnrolmentView::onPrimaryButton() 
{
    AppState::currentFileDialogId = "EnrolmentUserReferenceFolder";
    AppState::currentFileDialogMode = FileDialog::Mode::Directory;
    _actionBus.post(UiAction::OpenFileDialog);
}

const char* EnrolmentView::secondaryButtonLabel() const 
{
    return nullptr;
}

void EnrolmentView::onSecondaryButton() 
{
}

const char* EnrolmentView::thirdButtonLabel() const
{
    return "Stwórz wzór wybranego użytkownika";
}

void EnrolmentView::onThirdButton()
{
    _actionBus.post(UiAction::StartSpeakerModelCreation);
}

std::string EnrolmentView::extractFileNameFromPath(const std::string& filePath)
{
    return std::filesystem::path(filePath).filename().string();
}
