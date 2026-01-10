#include "GlfwWindow.h"
#include "ImGuiLayer.h"
#include "VoiceLabApp.h"

int main()
{
    try
    {
        GlfwWindow window(1480, 920, "Voice Lab");
        ImGuiLayer imgui(window);
        VoiceLabApp app(window);

        while (!app.shouldClose())
        {
            window.pollEvents();

            imgui.beginFrame();

            app.render();

            imgui.endFrame();
        }
    }
    catch (const std::exception& ex)
    {
        std::fprintf(stderr, "Fatal error: %s\n", ex.what());
        return 1;
    }

    return 0;
}
