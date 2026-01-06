#include "EnrolmentView.h"

#include <filesystem>

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
    return "Wybierz";
}

void EnrolmentView::onPrimaryButton() 
{
    // _actionBus.post(UiAction::StartEnrolmentRecording);
}

const char* EnrolmentView::secondaryButtonLabel() const 
{
    return "Import audio files";
}

void EnrolmentView::onSecondaryButton() 
{
    // _actionBus.post(UiAction::OpenEnrolmentImport);
}

const char* EnrolmentView::thirdButtonLabel() const
{
    return "";
}

void EnrolmentView::onThirdButton()
{
}

const char* EnrolmentView::hint() const 
{
    return
        "During enrolment the system extracts embeddings (e.g., x-vectors)\n"
        "from several recordings and aggregates them into a stable voice template.";
}

std::string EnrolmentView::extractFileNameFromPath(const std::string& filePath)
{
    return std::filesystem::path(filePath).filename().string();
}
