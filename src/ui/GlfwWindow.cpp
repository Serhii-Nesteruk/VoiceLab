#include "GlfwWindow.h"

#include <stdexcept>

GlfwWindow::GlfwWindow(int width, int height, const std::string& title)
{
    glfwSetErrorCallback(errorCallback);

    if (!glfwInit())
    {
        throw std::runtime_error("Failed to initialize GLFW3");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    _window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
        if (!_window)
    {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }

    glfwMakeContextCurrent(_window);
    glfwSwapInterval(1);
}

GlfwWindow::~GlfwWindow()
{
    if (_window)
    {
        glfwDestroyWindow(_window);
    }
    glfwTerminate();
}

bool GlfwWindow::shouldClose() const
{
    return glfwWindowShouldClose(_window);
}

void GlfwWindow::pollEvents()
{
    glfwPollEvents();
}

void GlfwWindow::swapBuffers()
{
    glfwSwapBuffers(_window);
}

void GlfwWindow::getFramebufferSize(int& width, int& height) const
{
    return glfwGetFramebufferSize(_window, &width, &height);
}


