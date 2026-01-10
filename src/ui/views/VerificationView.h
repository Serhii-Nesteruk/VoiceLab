#pragma once

#include <string>

#include "VoiceScreenViewBase.h"

#include "UiActionBus.h"

class VerificationView final : public VoiceScreenViewBase {
public:
    explicit VerificationView(UiActionBus& actionBus);

    [[nodiscard]] const char* windowTitle() const override;
    [[nodiscard]] const char* mainTitle() const override;
    [[nodiscard]] std::string subtitle() const override;
    [[nodiscard]] const char* primaryButtonLabel() const override;
    void onPrimaryButton() override;
    [[nodiscard]] const char* secondaryButtonLabel() const override;
    void onSecondaryButton() override;
    [[nodiscard]] const char* thirdButtonLabel() const override;
    void onThirdButton() override;

private:
    [[nodiscard]] static std::string extractFileNameFromPath(const std::string& filePath);
};
