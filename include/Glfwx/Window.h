#pragma once

#if !defined(GLFWX_WINDOW_H)
#define GLFWX_WINDOW_H

#include <GLFW/glfw3.h>
#include "Glfwx/Enumerations.h"
#include <string>
#include <stdexcept>
#include <vector>


namespace Glfwx
{
enum class Hint;

//! Wrapper for GLFW window.
class Window
{
public:

    //! Constructor.
    Window(int width, int height, std::string const & name, void * monitor = nullptr, void * share = nullptr)
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


    //! Destructor.
    virtual ~Window()
    {
        if (window_)
            glfwDestroyWindow(window_);
    }

    //! Creates the window.
    int create()
    {
        window_ = glfwCreateWindow(width_, height_, name_.c_str(), monitor_, share_);
        return 0;
    }

    //! Returns the value of the specified attribute.
    int getAttribute(int attr) const
    {
        return 0;
    }

    //! Returns the width and height of the window.
    void size(int & width, int & height) const
    {
    }

    //! Returns the width and height of the window's frame buffer.
    void frameBufferSize(int & width, int & height) const
    {
    }

    //! Sets the window's icon.
    void setIcon()
    {
    }
    //! Processes window activity until the window is closed.
    void run()
    {
        while (!glfwWindowShouldClose(window_))
        {
            glfwPollEvents();
        }
    }

    //! Provides some window initialization context.
    static void hint(Hint id, int value)
    {
        glfwWindowHint((int)id, value);
    }

#if defined(GLFW_INCLUDE_VULKAN)
    VkSurfaceKHR createSurface(VkInstance instance, VkAllocationCallbacks * allocator) const
    {
        VkSurfaceKHR surface;
        if (glfwCreateWindowSurface(instance, window_, allocator, &surface) != VK_SUCCESS)
        {
            throw std::runtime_error("glfwCreateWindowSurface failed.");
        }
        return surface;
    }
#endif // defined(GLFW_INCLUDE_VULKAN)

private:
    int width_;
    int height_;
    std::string name_;
    GLFWmonitor * monitor_;
    GLFWwindow * share_;
    GLFWwindow * window_;
};
} // namespace Glfwx

#endif // !defined(GLFWX_WINDOW_H)
