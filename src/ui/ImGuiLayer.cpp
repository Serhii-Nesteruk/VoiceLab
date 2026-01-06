#include "ImGuiLayer.h"

#include <filesystem>
#include <iostream>

#include "styles/UiTheme.h"

ImGuiLayer::ImGuiLayer(GlfwWindow& window)
    :_window(window)
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;

    ImFontConfig fontConfig;
    fontConfig.OversampleH = fontConfig.OversampleV = 2;

    // TODO: hardcoded font path - move to config / assets manager
    io.Fonts->AddFontFromFileTTF(
        "../assets/fonts/DejaVuSans.ttf",
        18.f,
        &fontConfig,
        io.Fonts->GetGlyphRangesDefault()
    );

    UiTheme::applyDarkTheme();

    const char* glsl_version = "#version 330";
    ImGui_ImplGlfw_InitForOpenGL(_window.getWindow(), true);
    ImGui_ImplOpenGL3_Init(glsl_version);
}

ImGuiLayer::~ImGuiLayer()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void ImGuiLayer::beginFrame()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void ImGuiLayer::endFrame()
{
    ImGui::Render();

    int display_w, display_h;
    _window.getFramebufferSize(display_w, display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    _window.swapBuffers();
}

