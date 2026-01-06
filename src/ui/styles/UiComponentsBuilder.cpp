#include "UiComponentsBuilder.h"

void UiComponentsBuilder::defaultButton(const char* label, const std::function<void()>& onClick)
{
    if (ImGui::Button(label))
    {
        if (onClick) onClick();
    }
}

void UiComponentsBuilder::defaultButton(const char* label, const ImVec2& size, const std::function<void()>& onClick)
{
    if (ImGui::Button(label, size))
    {
        if (onClick) onClick();
    }
}

void UiComponentsBuilder::centeredButton(const char* label, const std::function<void()>& onClick)
{
    float regionWidth = ImGui::GetContentRegionAvail().x;
    ImVec2 textSize   = ImGui::CalcTextSize(label);
    float  buttonWidth = textSize.x + ImGui::GetStyle().FramePadding.x * 2.0f;

    ImGui::SetCursorPosX((regionWidth - buttonWidth) * 0.5f);

    if (ImGui::Button(label)) {
        if (onClick) onClick();
    }
}

void UiComponentsBuilder::topLeftButton(const char* label, const std::function<void()>& onClick,
    const ImVec2& offset /* = ImVec(10, 150)*/)
{
    ImGui::SetCursorPos(offset);

    defaultButton(label, onClick);
}
