#include "Glfwx/Window.h"

#include "Glfwx/Enumerations.h"

#include <GLFW/glfw3.h>

#include <stdexcept>
#include <string>
#include <vector>

namespace Glfwx
{

Window::Window(int width, int height, std::string const & name, void * monitor /*= nullptr*/, void * share /*= nullptr*/)
        : width_(width)
        , height_(height)
        , name_(name)
        , monitor_(static_cast<GLFWmonitor *>(monitor))
        , share_(static_cast<GLFWwindow *>(share))
        , window_(nullptr)
    {
        if (width <= 0 || height <= 0)
            throw std::invalid_argument("width <= 0 || height <= 0");
    }

Window::~Window()
    {
        if (window_)
            glfwDestroyWindow(window_);
    }

    int Window::open()
    {
        window_ = glfwCreateWindow(width_, height_, name_.c_str(), monitor_, share_);
        return 0;
    }

    int Window::getAttribute(int attr) const
    {
        return 0;
    }

    void Window::size(int & width, int & height) const
    {

    }

    void Window::frameBufferSize(int & width, int & height) const
    {

    }

    void Window::setIcon()
    {

    }

    void Window::run()
    {
        while (!glfwWindowShouldClose(window_))
        {
            glfwPollEvents();
        }
    }

    void Window::hint(Hint id, int value)
    {
        glfwWindowHint((int)id, value);
    }
} // namespace Glfwx
