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

    ImGui::Dummy(ImVec2(0.0f, 120.0f));

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
        "Weryfikacja",
        [this]() {
             _actionBus.post(UiAction::OpenVerificationView);
        }
    );

    ImGui::Dummy(ImVec2(0.0f, 15.0f));

    UiComponentsBuilder::centeredButton(
        "Rejestracja użytkownika (enrolment)",
        [this]() {
            _actionBus.post(UiAction::OpenEnrolmentView);
        }
    );

    ImGui::End();
}
