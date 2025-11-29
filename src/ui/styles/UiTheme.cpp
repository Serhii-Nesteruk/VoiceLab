#include "UiTheme.h"

#include "UiColors.h"
#include "imgui.h"

void UiTheme::applyDarkTheme()
{
    ImGuiStyle& style = ImGui::GetStyle();
    ImVec4* colors = style.Colors;

    style.WindowRounding              = 6.0f;
    style.FrameRounding               = 4.0f;
    style.ScrollbarRounding           = 6.0f;
    style.GrabRounding                = 4.0f;
    style.TabRounding                 = 4.0f;
    style.FramePadding                = ImVec2(18, 14);
    style.ItemSpacing                 = ImVec2(18, 16);
    style.WindowPadding               = ImVec2(20, 100);

    colors[ImGuiCol_WindowBg]         = UiColors::Background;
    colors[ImGuiCol_ChildBg]          = UiColors::Background;
    colors[ImGuiCol_PopupBg]          = UiColors::Background;

    colors[ImGuiCol_Text]             = UiColors::Text;
    colors[ImGuiCol_TextDisabled]     = UiColors::TextDisabled;

    colors[ImGuiCol_Button]           = UiColors::Button;
    colors[ImGuiCol_ButtonHovered]    = UiColors::ButtonHovered;
    colors[ImGuiCol_ButtonActive]     = UiColors::ButtonActive;

    colors[ImGuiCol_FrameBg]          = UiColors::FrameBg;
    colors[ImGuiCol_FrameBgHovered]   = UiColors::FrameBgHovered;
    colors[ImGuiCol_FrameBgActive]    = UiColors::FrameBgActive;

    colors[ImGuiCol_Header]           = UiColors::Header;
    colors[ImGuiCol_HeaderHovered]    = UiColors::HeaderHovered;
    colors[ImGuiCol_HeaderActive]     = UiColors::HeaderActive;

    colors[ImGuiCol_Separator]        = UiColors::FrameBgHovered;
    colors[ImGuiCol_SeparatorHovered] = UiColors::Accent;
    colors[ImGuiCol_SeparatorActive]  = UiColors::Accent;

    colors[ImGuiCol_SliderGrab]       = UiColors::Accent;
    colors[ImGuiCol_SliderGrabActive] = UiColors::Accent;
}