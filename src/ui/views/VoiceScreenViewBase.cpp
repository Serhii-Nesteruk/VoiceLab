#include "VoiceScreenViewBase.h"

void VoiceScreenViewBase::render()
{
    {
        ImGuiWindowFlags flags =
            ImGuiWindowFlags_NoResize |
            ImGuiWindowFlags_NoMove   |
            ImGuiWindowFlags_NoCollapse;

        ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->WorkPos);
        ImGui::SetNextWindowSize(viewport->WorkSize);

        ImGui::Begin(windowTitle(), nullptr, flags);

        ImGui::Dummy(ImVec2(0.0f, 40.0f));

        float regionWidth = ImGui::GetContentRegionAvail().x;

        UiComponentsBuilder::topLeftButton(
            "< Powrót",
            [this](){ _actionBus.post(UiAction::OpenMainView); }
        );

        // Title
        {
            const char* title = mainTitle();
            ImVec2 titleSize = ImGui::CalcTextSize(title);
            ImGui::SetCursorPosX((regionWidth - titleSize.x) * 0.5f);
            ImGui::Text("%s", title);
        }

        // Subtitle
        {
            std::string subtitleStr = subtitle();
            const char* subtitleText = subtitleStr.c_str();
            ImVec2 subtitleSize = ImGui::CalcTextSize(subtitleText);
            ImGui::SetCursorPosX((regionWidth - subtitleSize.x) * 0.5f);
            ImGui::TextDisabled("%s", subtitleText);
        }

        ImGui::Dummy(ImVec2(0.0f, 30.0f));

        // Primary button
        const auto primaryBtnLabel = primaryButtonLabel();
        if (primaryBtnLabel && primaryBtnLabel[0] != '\0')
        {
            UiComponentsBuilder::centeredButton(
                primaryButtonLabel(),
                [this]() { onPrimaryButton(); }
            );
        }

        ImGui::Dummy(ImVec2(0.0f, 15.0f));

        // Secondary button
        const auto secondaryBtnLabel = secondaryButtonLabel();
        if (secondaryBtnLabel && secondaryBtnLabel[0] != '\0')
        {
            UiComponentsBuilder::centeredButton(
                secondaryButtonLabel(),
                [this]() { onSecondaryButton(); }
            );
        }

        ImGui::Dummy(ImVec2(0.0f, 30.0f));

        const auto thirdBtnLabel = thirdButtonLabel();
        if (thirdBtnLabel && thirdBtnLabel[0] != '\0')
        {
            UiComponentsBuilder::centeredButton(
               thirdButtonLabel(),
               [this]() { onThirdButton(); }
           );
        }

        ImGui::End();
    }

}
