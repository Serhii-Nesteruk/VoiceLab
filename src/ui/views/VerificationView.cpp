#include "VerificationView.h"

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

const char* VerificationView::subtitle() const 
{
    return "Speak into the microphone to verify your identity against the enrolled template.";
}

const char* VerificationView::primaryButtonLabel() const 
{
    return "Start verification";
}

void VerificationView::onPrimaryButton() 
{
    // _actionBus.post(UiAction::StartVerification);
}

const char* VerificationView::secondaryButtonLabel() const 
{
    return "Use test audio file";
}

void VerificationView::onSecondaryButton() 
{
    // _actionBus.post(UiAction::OpenVerificationFileDialog);
}

const char* VerificationView::hint() const 
{
    return
        "The verification stage compares the current voice embedding\n"
        "with the stored template and produces a similarity score / decision.";
}