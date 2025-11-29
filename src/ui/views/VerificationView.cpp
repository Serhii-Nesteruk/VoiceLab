#include "VerificationView.h"
#include <imgui.h>

#include "styles/UiComponentsBuilder.h"

VerificationView::VerificationView(UiActionBus& actionBus)
    : _actionBus(actionBus)
{
}

void VerificationView::render()
{
    ImGuiWindowFlags flags =
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoMove   |
        ImGuiWindowFlags_NoCollapse;

    ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport->WorkPos);
    ImGui::SetNextWindowSize(viewport->WorkSize);

    ImGui::Begin("Voice Lab - Verification", nullptr, flags);

    ImGui::Dummy(ImVec2(0.0f, 40.0f));

    float regionWidth = ImGui::GetContentRegionAvail().x;

    const char* title = "Sign in with voice (verification)";
    ImVec2 titleSize = ImGui::CalcTextSize(title);
    ImGui::SetCursorPosX((regionWidth - titleSize.x) * 0.5f);
    ImGui::Text("%s", title);

    const char* subtitle =
        "Speak into the microphone to verify your identity against the enrolled template.";
    ImVec2 subtitleSize = ImGui::CalcTextSize(subtitle);
    ImGui::SetCursorPosX((regionWidth - subtitleSize.x) * 0.5f);
    ImGui::TextDisabled("%s", subtitle);

    ImGui::Dummy(ImVec2(0.0f, 30.0f));

    UiComponentsBuilder::centeredButton(
        "Start verification",
        [this]() {
            // TODO:
            // _actionBus.post(UiAction::StartVerification);
        }
    );

    ImGui::Dummy(ImVec2(0.0f, 15.0f));

    UiComponentsBuilder::centeredButton(
        "Use test audio file",
        [this]() {
            // TODO:
            // _actionBus.post(UiAction::OpenVerificationFileDialog);
        }
    );

    ImGui::Dummy(ImVec2(0.0f, 30.0f));

    const char* hint =
        "The verification stage compares the current voice embedding\n"
        "with the stored template and produces a similarity score / decision.";
    ImVec2 hintSize = ImGui::CalcTextSize(hint);
    ImGui::SetCursorPosX((regionWidth - hintSize.x) * 0.5f);
    ImGui::TextDisabled("%s", hint);

    ImGui::Dummy(ImVec2(0.0f, 20.0f));

    // UiComponentsBuilder::centeredButton(
    //     "Back to start screen",
    //     [this]() {
    //         _actionBus.post(UiAction::OpenMainView);
    //     }
    // );

    ImGui::End();
}
