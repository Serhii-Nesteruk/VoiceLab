#pragma once

#include "GLFW/glfw3.h"
#include <string>

class GlfwWindow
{
public:
    GlfwWindow(int width, int height, const std::string& title);
    ~GlfwWindow();

    [[nodiscard]] inline GLFWwindow* getWindow() const { return _window; }

    [[nodiscard]] bool shouldClose() const;

    void pollEvents();
    void swapBuffers();
    void getFramebufferSize(int& width, int& height) const;

private:
    inline static void errorCallback(int error, const char* description)
    {
        std::fprintf(stderr, "GLFW Error %d: %s\n", error, description);
    }

    GLFWwindow* _window = nullptr;
};