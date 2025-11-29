#pragma once

#include "GlfwWindow.h"
#include "ImGuiLayer.h"
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

class ImGuiLayer
{
public:
    explicit ImGuiLayer(GlfwWindow& window);
    ~ImGuiLayer();

    void beginFrame();
    void endFrame();

private:
    GlfwWindow& _window;
};
