#include "MainWindowView.h"
#include <imgui.h>

#include "UiAction.h"
#include "styles/UiComponentsBuilder.h"

MainWindowView::MainWindowView(UiActionBus& actionBus)
    : _actionBus(actionBus)
{
}

void MainWindowView::render()
{
    renderStartScreen();
}

void MainWindowView::renderStartScreen()
{
    ImGuiWindowFlags flags =
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoMove   |
        ImGuiWindowFlags_NoCollapse;

    ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport->WorkPos);
    ImGui::SetNextWindowSize(viewport->WorkSize);

    ImGui::Begin("Voice Lab", nullptr, flags);

    ImGui::Dummy(ImVec2(0.0f, 40.0f));

    float regionWidth = ImGui::GetContentRegionAvail().x;

    const char* title = "Voice Verification Lab";
    ImVec2 titleSize = ImGui::CalcTextSize(title);
    ImGui::SetCursorPosX((regionWidth - titleSize.x) * 0.5f);
    ImGui::Text("%s", title);

    const char* subtitle = "Choose an action to continue";
    ImVec2 subtitleSize = ImGui::CalcTextSize(subtitle);
    ImGui::SetCursorPosX((regionWidth - subtitleSize.x) * 0.5f);
    ImGui::TextDisabled("%s", subtitle);

    ImGui::Dummy(ImVec2(0.0f, 30.0f));

    UiComponentsBuilder::centeredButton(
        "Sign in with voice (verification)",
        [this]() {
             _actionBus.post(UiAction::OpenVerificationView);
        }
    );

    ImGui::Dummy(ImVec2(0.0f, 15.0f));

    UiComponentsBuilder::centeredButton(
        "Create voice profile (enrolment)",
        [this]() {
            _actionBus.post(UiAction::OpenEnrolmentView);
        }
    );

    ImGui::Dummy(ImVec2(0.0f, 30.0f));

    const char* hint =
        "The enrolment stage creates a reference voice template.\n"
        "The verification stage compares the current voice against that template.";
    ImVec2 hintSize = ImGui::CalcTextSize(hint);
    ImGui::SetCursorPosX((regionWidth - hintSize.x) * 0.5f);
    ImGui::TextDisabled("%s", hint);

    ImGui::End();
}
