#pragma once

#include <imgui.h>

namespace UiColors
{
    inline const ImVec4 Background      = ImVec4(0.11f, 0.11f, 0.15f, 1.0f);
    inline const ImVec4 FrameBg         = ImVec4(0.20f, 0.20f, 0.25f, 1.0f);
    inline const ImVec4 FrameBgHovered  = ImVec4(0.30f, 0.30f, 0.35f, 1.0f);
    inline const ImVec4 FrameBgActive   = ImVec4(0.35f, 0.40f, 0.50f, 1.0f);

    inline const ImVec4 Button          = ImVec4(0.20f, 0.29f, 0.36f, 1.0f);
    inline const ImVec4 ButtonHovered   = ImVec4(0.27f, 0.40f, 0.50f, 1.0f);
    inline const ImVec4 ButtonActive    = ImVec4(0.20f, 0.45f, 0.60f, 1.0f);

    inline const ImVec4 Header          = ImVec4(0.25f, 0.25f, 0.30f, 1.0f);
    inline const ImVec4 HeaderHovered   = ImVec4(0.35f, 0.35f, 0.40f, 1.0f);
    inline const ImVec4 HeaderActive    = ImVec4(0.40f, 0.40f, 0.50f, 1.0f);

    inline const ImVec4 Text            = ImVec4(0.90f, 0.90f, 0.95f, 1.0f);
    inline const ImVec4 TextDisabled    = ImVec4(0.50f, 0.55f, 0.60f, 1.0f);

    inline const ImVec4 Accent          = ImVec4(0.70f, 0.90f, 1.00f, 1.0f);

    inline const ImVec4 Danger          = ImVec4(0.85f, 0.20f, 0.20f, 1.0f);
    inline const ImVec4 Success         = ImVec4(0.20f, 0.80f, 0.30f, 1.0f);
}
