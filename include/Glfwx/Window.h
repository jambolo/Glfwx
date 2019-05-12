#if !defined(GLFWX_WINDOW_H)
#define GLFWX_WINDOW_H

#pragma once

#include <Glfwx/Enumerations.h>
#include <GLFW/glfw3.h>
#include <Glfwx/Monitor.h>
#include <functional>
#include <stdexcept>
#include <string>
#include <vector>

namespace Glfwx
{
//! Wrapper for GLFW window.
//!
//! @sa     GLFWwindow
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

    Window(int width, int height, char const * title, Monitor * monitor = nullptr, GLFWwindow * share = nullptr)
    {
        if (width <= 0 || height <= 0)
            throw std::invalid_argument("Window::Window: width <= 0 || height <= 0");
        window_ = glfwCreateWindow(width, height, title, (monitor) ? (GLFWmonitor *)*monitor : nullptr, share);
        glfwSetWindowUserPointer(window_, this);
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
    Monitor monitor() const
    {
        return Monitor(glfwGetWindowMonitor(window_));
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
        context_ = context;
    }

    //! Returns the previously set context, or nullptr.
    void * context() const
    {
        return context_;
    }

    //! Sets the function to be called when the window's position changes size.
    //!
    //! @param  cb      Callback function
    void setPositionChangedCallback(std::function<void(Window *, int, int)> const & cb)
    {
        handlePositionChanged_ = cb;
        if (cb)
        {
            glfwSetWindowPosCallback(window_, onPositionChanged);
        }
        else
        {
            glfwSetWindowPosCallback(window_, nullptr);
        }
    }

    //! Sets the function to be called when the window changes size.
    //!
    //! @param  cb      Callback function
    void setWindowSizeChangedCallback(std::function<void(Window *, int, int)> const & cb)
    {
        handleWindowSizeChanged_ = cb;
        if (cb)
        {
            glfwSetWindowSizeCallback(window_, onWindowSizeChanged);
        }
        else
        {
            glfwSetWindowSizeCallback(window_, nullptr);
        }
    }

    //! Sets the function to be called when the window is about to close.
    //!
    //! @param  cb      Callback function
    void setCloseCallback(std::function<void(Window *)> const & cb)
    {
        handleClose_ = cb;
        if (cb)
        {
            glfwSetWindowCloseCallback(window_, onClose);
        }
        else
        {
            glfwSetWindowCloseCallback(window_, nullptr);
        }
    }

    //! Sets the function to be called when the window needs to be refreshed.
    //!
    //! @param  cb      Callback function
    void setRefreshCallback(std::function<void(Window *)> const & cb)
    {
        handleRefresh_ = cb;
        if (cb)
        {
            glfwSetWindowRefreshCallback(window_, onRefresh);
        }
        else
        {
            glfwSetWindowRefreshCallback(window_, nullptr);
        }
    }

    //! Sets the function to be called when the window gains or loses focus.
    //!
    //! @param  cb      Callback function
    void setFocusChangedCallback(std::function<void(Window *, bool)> const & cb)
    {
        handleFocusChanged_ = cb;
        if (cb)
        {
            glfwSetWindowFocusCallback(window_, onFocusChanged);
        }
        else
        {
            glfwSetWindowFocusCallback(window_, nullptr);
        }
    }

    //! Sets the function to be called when the window's iconified status has changed.
    //!
    //! @param  cb      Callback function
    void setIconifyChangedCallback(std::function<void(Window *, int)> const & cb)
    {
        handleIconifyChanged_ = cb;
        if (cb)
        {
            glfwSetWindowIconifyCallback(window_, onIconifyChanged);
        }
        else
        {
            glfwSetWindowIconifyCallback(window_, nullptr);
        }
    }

    //! Sets the function to be called when the window's framebuffer changes size.
    //!
    //! @param  cb      Callback function
    void setFramebufferSizeChangedCallback(std::function<void(Window *, int, int)> const & cb)
    {
        handleFramebufferSizeChanged_ = cb;
        if (cb)
        {
            glfwSetFramebufferSizeCallback(window_, onFramebufferSizeChanged);
        }
        else
        {
            glfwSetFramebufferSizeCallback(window_, nullptr);
        }
    }

    //! Processes any window activity.
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

    //! Waits for any window activity and processes it.
    //!
    //! @return    The close value
    //!
    //! @sa     glfwWaitEvents
    //! @sa     glfwWindowShouldClose
    int waitEvents()
    {
        glfwWaitEvents();
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
    void * context_;
    std::function<void(Window *, int, int)> handlePositionChanged_;
    std::function<void(Window *, int, int)> handleWindowSizeChanged_;
    std::function<void(Window *)> handleClose_;
    std::function<void(Window *)> handleRefresh_;
    std::function<void(Window *, bool)> handleFocusChanged_;
    std::function<void(Window *, bool)> handleIconifyChanged_;
    std::function<void(Window *, int, int)> handleFramebufferSizeChanged_;

    static void onPositionChanged(GLFWwindow * window, int x, int y)
    {
        Window * that = static_cast<Window *>(glfwGetWindowUserPointer(window));
        that->handlePositionChanged_(that, x, y);
    }

    static void onWindowSizeChanged(GLFWwindow * window, int width, int height)
    {
        Window * that = static_cast<Window *>(glfwGetWindowUserPointer(window));
        that->handleWindowSizeChanged_(that, width, height);
    }

    static void onClose(GLFWwindow * window)
    {
        Window * that = static_cast<Window *>(glfwGetWindowUserPointer(window));
        that->handleClose_(that);
    }

    static void onRefresh(GLFWwindow * window)
    {
        Window * that = static_cast<Window *>(glfwGetWindowUserPointer(window));
        that->handleRefresh_(that);
    }

    static void onFocusChanged(GLFWwindow * window, int gained)
    {
        Window * that = static_cast<Window *>(glfwGetWindowUserPointer(window));
        that->handleFocusChanged_(that, gained != 0);
    }

    static void onIconifyChanged(GLFWwindow * window, int iconified)
    {
        Window * that = static_cast<Window *>(glfwGetWindowUserPointer(window));
        that->handleIconifyChanged_(that, iconified != 0);
    }

    static void onFramebufferSizeChanged(GLFWwindow * window, int width, int height)
    {
        Window * that = static_cast<Window *>(glfwGetWindowUserPointer(window));
        that->handleFramebufferSizeChanged_(that, width, height);
    }
};
} // namespace Glfwx

#endif // !defined(GLFWX_WINDOW_H)
