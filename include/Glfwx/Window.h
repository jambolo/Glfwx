#pragma once

#if !defined(GLFWX_WINDOW_H)
#define GLFWX_WINDOW_H

#include "Glfwx/Enumerations.h"
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <string>
#include <vector>

namespace Glfwx
{
enum class Hint;

//! Wrapper for GLFW window.
class Window
{
public:

    //! Constructor.
    //!
    //! @param  width
    //! @param  height
    //! @param  name
    //! @param  monitor
    //! @param  share
    //!
    //! @sa hint()

    Window(int width, int height, char const * title, GLFWmonitor * monitor = nullptr, GLFWwindow * share = nullptr)
    {
        if (width <= 0 || height <= 0)
            throw std::invalid_argument("Window::Window: width <= 0 || height <= 0");
        window_ = glfwCreateWindow(width, height, title, monitor, share);
    }

    //! Destructor.
    //!
    //! @sa     glfwDestroyWindow
    virtual ~Window()
    {
        glfwDestroyWindow(window_);
    }

    //! Sets the title.
    //!
    //! @param  title   New title
    //!
    //! @sa     glfwSetWindowTitle
    void setTitle(char const * title)
    {
        glfwSetWindowTitle(window_, title);
    }

    //! Sets the window's icon.
    //!
    //! @param  images  icon images (default: reset to default)
    //!
    //! @sa     glfwSetWindowIcon
    //! @sa     GLFWimage
    void setIcon(std::vector<GLFWimage> images = std::vector<GLFWimage>())
    {
        glfwSetWindowIcon(window_, (int)images.size(), images.data());
    }

    //! Sets the window's position.
    //!
    //! @param  x   Horizontal position
    //! @param  y   Vertical position
    //!
    //! @sa     glfwSetWindowPos
    void setPosition(int x, int y)
    {
        glfwSetWindowPos(window_, x, y);
    }

    //! Returns the window's position.
    //!
    //! @param  [out]   x   Horizontal position
    //! @param  [out]   y   Vertical position
    //!
    //! @sa     glfwGetWindowPos
    void position(int & x, int & y) const
    {
        glfwGetWindowPos(window_, &x, &y);
    }

    //! Sets the size of the window.
    void setSize(int width, int height)
    {
        glfwSetWindowSize(window_, width, height);
    }

    //! Returns the width and height of the window.
    void size(int & width, int & height) const
    {
        glfwGetWindowSize(window_, &width, &height);
    }

    //! Limits the size of the window.
    //!
    //! @param  minWidth
    //! @param  minHeight
    //! @param  maxWidth
    //! @param  maxHeight
    //!
    //! @sa     glfwSetWindowSizeLimits
    void setSizeLimits(int minWidth = -1, int minHeight = -1, int maxWidth = -1, int maxHeight = -1)
    {
        glfwSetWindowSizeLimits(window_, minWidth, minHeight, maxWidth, maxHeight);
    }

    //! Sets the window's aspect ratio.
    void setAspectRatio(int n, int d)
    {
        glfwSetWindowAspectRatio(window_, n, d);
    }

    //! Returns the width and height of the window's framebuffer.
    void framebufferSize(int & width, int & height) const
    {
        glfwGetFramebufferSize(window_, &width, &height);
    }

    //! Returns the locations of the edges of the window's frame
    void frame(int & left, int & top, int & right, int & bottom) const
    {
        glfwGetWindowFrameSize(window_, &left, &top, &right, &bottom);
    }

    //! Reduces the window to an icon.
    void iconify()
    {
        glfwIconifyWindow(window_);
    }

    //! Displays the window normally.
    void restore()
    {
        glfwRestoreWindow(window_);
    }

    //! Fits the window to the size of the screen.
    void maximize()
    {
        glfwMaximizeWindow(window_);
    }

    //! Shows or hides the window.
    void show(bool shown = true)
    {
        if (shown)
            glfwShowWindow(window_);
        else
            glfwHideWindow(window_);
    }

    //! Sets the focus to the window.
    void focus()
    {
        glfwFocusWindow(window_);
    }

    //! Returns the window's monitor.
    GLFWmonitor * monitor() const
    {
        return glfwGetWindowMonitor(window_);
    }

    //! Sets the window's monitor parameters.
    void setMonitor(GLFWmonitor * monitor, int x, int y, int width, int height, int refreshRate)
    {
        glfwSetWindowMonitor(window_, monitor, x, y, width, height, refreshRate);
    }

    //! Returns the value of the specified attribute.
    int getAttribute(int attr) const
    {
        return 0;
    }

    //! Saves a context for the window.
    void setContext(void * context)
    {
        glfwSetWindowUserPointer(window_, context);
    }

    //! Returns the previously set context, or nullptr.
    void * context() const
    {
        return glfwGetWindowUserPointer(window_);
    }

    //! Sets the function to be called when the window's position changes size.
    //!
    //! @param  callback    Callback function
    //!
    //! @return     previous callback or nullptr
    GLFWwindowposfun setWindowPosCallback(GLFWwindowposfun cb)
    {
        return glfwSetWindowPosCallback(window_, cb);
    }

    //! Sets the function to be called when the window changes size.
    //!
    //! @param  callback    Callback function
    //!
    //! @return     previous callback or nullptr
    GLFWwindowsizefun setWindowSizeCallback(GLFWwindowsizefun cb)
    {
        return glfwSetWindowSizeCallback(window_, cb);
    }

    //! Sets the function to be called when the is about to close.
    //!
    //! @param  callback    Callback function
    //!
    //! @return     previous callback or nullptr
    GLFWwindowclosefun setWindowCloseCallback(GLFWwindowclosefun cb)
    {
        return glfwSetWindowCloseCallback(window_, cb);
    }

    //! Sets the function to be called when the window needs to be refreshed.
    //!
    //! @param  callback    Callback function
    //!
    //! @return     previous callback or nullptr
    GLFWwindowrefreshfun setWindowRefreshCallback(GLFWwindowrefreshfun cb)
    {
        return glfwSetWindowRefreshCallback(window_, cb);
    }

    //! Sets the function to be called when the window gains focus.
    //!
    //! @param  callback    Callback function
    //!
    //! @return     previous callback or nullptr
    GLFWwindowfocusfun setWindowFocusCallback(GLFWwindowfocusfun cb)
    {
        return glfwSetWindowFocusCallback(window_, cb);
    }

    //! Sets the function to be called when the window is iconified.
    //!
    //! @param  callback    Callback function
    //!
    //! @return     previous callback or nullptr
    GLFWwindowiconifyfun setWindowIconifyCallback(GLFWwindowiconifyfun cb)
    {
        return glfwSetWindowIconifyCallback(window_, cb);
    }

    //! Sets the function to be called when the window's framebuffer changes size.
    //!
    //! @param  callback    Callback function
    //!
    //! @return     previous callback or nullptr
    GLFWframebuffersizefun setFramebufferSizeCallback(GLFWframebuffersizefun cb)
    {
        return glfwSetFramebufferSizeCallback(window_, cb);
    }

    //! Processes window activity.
    //!
    //! @return    The close value
    //!
    //! @sa     glfwPollEvents
    //! @sa     glfwWindowShouldClose
    int processEvents()
    {
        glfwPollEvents();
        return glfwWindowShouldClose(window_);
    }

#if defined(GLFW_INCLUDE_VULKAN)
    //! Creates a device-specific Vulkan surface.
    //!
    //! @param  instance    Vulkan instance
    //! @param  allocator   Vulkan allocator
    //!
    //! @return     Vulkan surface
    //!
    //! @sa     glfwCreateWindowSurface
    VkSurfaceKHR createSurface(VkInstance instance, VkAllocationCallbacks * allocator) const
    {
        VkSurfaceKHR surface;
        if (glfwCreateWindowSurface(instance, window_, allocator, &surface) != VK_SUCCESS)
            throw std::runtime_error("glfwCreateWindowSurface failed.");
        return surface;
    }
#endif  // defined(GLFW_INCLUDE_VULKAN)

    //! Resets all window hints back to default values.
    //!
    //! @sa glfwDefaultWindowHints
    static void resetHints()
    {
        glfwDefaultWindowHints();
    }

    //! Provides some window initialization context.
    //! @param  id      Hint ID
    //! @param  value   Value
    //!
    //! @sa glfwWindowHint
    static void hint(Hint id, int value)
    {
        glfwWindowHint((int)id, value);
    }

private:

    GLFWwindow * window_ = nullptr;
};
} // namespace Glfwx

#endif // !defined(GLFWX_WINDOW_H)
