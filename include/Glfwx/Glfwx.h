#pragma once

#if !defined(GLFWX_GLFWX_H)
#define GLFWX_GLFWX_H

#include <Glfwx/enumerations.h>
#include <GLFW/glfw3.h>
#include <vector>

namespace Glfwx
{
//! Initializes GLFW.
//!
//! @return     false if the initialization failed
bool start()
{
    int rv = glfwInit();
    return rv != GLFW_FALSE;
}

//! Shuts down GLFW.
void finish()
{
    glfwTerminate();
}

//! Wrapper for GLFW window.
class Window
{
public:

    //! Constructor.
    Window(int width, int height, std::string const & name, void * monitor, void * share)
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

    //! Opens the window.
    int open()
    {
        window_ = glfwCreateWindow(width_, height_, name_.c_str(), monitor_, share_);
        return 0;
    }

    //! Returns the value of the specified attribute.
    int getAttribute(int attr) const;

    //! Returns the width and height of the window.
    void size(int & width, int & height) const;

    //! Returns the width and height of the window's frame buffer.
    void frameBufferSize(int & width, int & height) const;

    //! Sets the window's icon.
    void setIcon();

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

private:
    int width_;
    int height_;
    std::string name_;
    GLFWmonitor * monitor_;
    GLFWwindow * share_;
    GLFWwindow * window_;
};

std::vector<char const *> requiredInstanceExtensions()
{
    uint32_t        count = 0;
    char const **   extensions;

    extensions = glfwGetRequiredInstanceExtensions(&count);
    return std::vector<char const *>(&extensions[0], &extensions[count]);
}
} // namespace Glfwx

#endif // !defined(GLFWX_GLFWX_H)
