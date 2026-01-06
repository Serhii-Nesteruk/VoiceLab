#pragma once

#include <functional>
#include "imgui.h"

namespace UiComponentsBuilder
{
    void defaultButton(const char* label, const std::function<void()>& onClick);
    void defaultButton(const char* label, const ImVec2& size, const std::function<void()>& onClick);
    void centeredButton(const char* label, const std::function<void()>& onClick);
    void topLeftButton(const char* label, const std::function<void()>& onClick, const ImVec2& offset = ImVec2(10, 150));
}
