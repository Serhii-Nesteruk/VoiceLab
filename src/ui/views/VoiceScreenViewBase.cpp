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
        UiComponentsBuilder::centeredButton(
            primaryButtonLabel(),
            [this]() { onPrimaryButton(); }
        );

        ImGui::Dummy(ImVec2(0.0f, 15.0f));

        // Secondary button
        UiComponentsBuilder::centeredButton(
            secondaryButtonLabel(),
            [this]() { onSecondaryButton(); }
        );

        ImGui::Dummy(ImVec2(0.0f, 30.0f));

        UiComponentsBuilder::centeredButton(
           thirdButtonLabel(),
           [this]() { onThirdButton(); }
       );

        ImGui::Dummy(ImVec2(0.0f, 30.0f));

        // Hint
        {
            const char* hintText = hint();
            ImVec2 hintSize = ImGui::CalcTextSize(hintText);
            ImGui::SetCursorPosX((regionWidth - hintSize.x) * 0.5f);
            ImGui::TextDisabled("%s", hintText);
        }

        ImGui::Dummy(ImVec2(0.0f, 20.0f));

        ImGui::End();
    }

}
