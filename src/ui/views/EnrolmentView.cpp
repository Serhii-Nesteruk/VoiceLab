#include "EnrolmentView.h"
#include <imgui.h>

#include "styles/UiComponentsBuilder.h"

EnrolmentView::EnrolmentView(UiActionBus& actionBus)
    : _actionBus(actionBus)
{
}

void EnrolmentView::render()
{
    ImGuiWindowFlags flags =
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoMove   |
        ImGuiWindowFlags_NoCollapse;

    ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport->WorkPos);
    ImGui::SetNextWindowSize(viewport->WorkSize);

    ImGui::Begin("Voice Lab - Enrolment", nullptr, flags);

    ImGui::Dummy(ImVec2(0.0f, 40.0f));

    float regionWidth = ImGui::GetContentRegionAvail().x;

    const char* title = "Create voice profile (enrolment)";
    ImVec2 titleSize = ImGui::CalcTextSize(title);
    ImGui::SetCursorPosX((regionWidth - titleSize.x) * 0.5f);
    ImGui::Text("%s", title);

    const char* subtitle =
        "Record or import reference speech samples to build a voice template.";
    ImVec2 subtitleSize = ImGui::CalcTextSize(subtitle);
    ImGui::SetCursorPosX((regionWidth - subtitleSize.x) * 0.5f);
    ImGui::TextDisabled("%s", subtitle);

    ImGui::Dummy(ImVec2(0.0f, 30.0f));

    UiComponentsBuilder::centeredButton(
        "Record new samples",
        [this]() {
            // TODO:
            // _actionBus.post(UiAction::StartEnrolmentRecording);
        }
    );

    ImGui::Dummy(ImVec2(0.0f, 15.0f));

    UiComponentsBuilder::centeredButton(
        "Import audio files",
        [this]() {
            // TODO:
            // _actionBus.post(UiAction::OpenEnrolmentImport);
        }
    );

    ImGui::Dummy(ImVec2(0.0f, 30.0f));

    const char* hint =
        "During enrolment the system extracts embeddings (e.g., x-vectors)\n"
        "from several recordings and aggregates them into a stable voice template.";
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
