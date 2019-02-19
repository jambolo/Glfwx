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
    //! @param  width
    //! @param  height
    //! @param  name
    //! @param  monitor
    //! @param  share
    //!
    //! @note   The window is not actually created until create() is called. hint() can be called to modify the creation behavior
    //!         prior to calling create().
    //!
    //! @sa hint

    Window(int width, int height, std::string const & title, GLFWmonitor * monitor = nullptr, GLFWwindow * share = nullptr)
        : width_(width)
        , height_(height)
        , title_(title)
        , monitor_(monitor)
        , share_(share)
        , window_(nullptr)
    {
        if (width <= 0 || height <= 0)
            throw std::invalid_argument("Window::Window: width <= 0 || height <= 0");
    }

    //! Destructor.
    //!
    //! @sa     glfwDestroyWindow
    virtual ~Window()
    {
        if (window_)
            glfwDestroyWindow(window_);
    }

    //! Creates the window.
    //!
    //! @sa     glfwCreateWindow
    int create()
    {
        if (!window_)
        {
            window_ = glfwCreateWindow(width_, height_, title_.c_str(), monitor_, share_);

            if (position_.deferred())
                glfwSetWindowPos(window_, position_.value().x, position_.value().y);
            if (icon_.deferred())
                glfwSetWindowIcon(window_, (int)icon_.value().size(), icon_.value().data());
            if (minSize_.deferred() || maxSize_.deferred())
                glfwSetWindowSizeLimits(window_, minSize_.value().x, minSize_.value().y, maxSize_.value().x, maxSize_.value().y);
            if (aspectRatio_.deferred())
                glfwSetWindowAspectRatio(window_, aspectRatio_.value().x, aspectRatio_.value().y);
            if (restored_.deferred())
                glfwRestoreWindow(window_);
            if (minified_.deferred())
                glfwIconifyWindow(window_);
            if (maximized_.deferred())
                glfwMaximizeWindow(window_);
            if (shown_.deferred())
            {
                if (shown_)
                    glfwShowWindow(window_);
                else
                    glfwHideWindow(window_);
            }
            if (focused_)
                glfwFocusWindow(window_);
        }

        return 0;
    }

    //! Sets the "close value".
    //!
    //! The close value is returned by processEvents(). By convention, any non-zero value indicates that window should be destroyed.
    //!
    //! @param  value   Close value
    //!
    //! @sa glfwSetWindowShouldClose
    //! @sa glfwGetWindowShouldClose
    //!
    //! @note   This method does not directly cause the window to be destroyed. It simply sets a value.
    //! @note   Ignored if the window has not been created.
    void destroy(int value)
    {
        if (window_)
            glfwSetWindowShouldClose(window_, value);
    }

    //! Sets the title.
    //!
    //! @param  title   New title
    //!
    //! @note   This method can be called before the window has been created.
    //!
    //! @sa     glfwSetWindowTitle
    //! @note   If the window has not yet been created, the title will be set after it is created.
    void setTitle(char const * title)
    {
        title_ = title;
        if (window_)
            glfwSetWindowTitle(window_, title);
    }

    //! Sets the window's icon.
    //!
    //! @param  images  icon images (default: reset to default)
    //!
    //! @sa     glfwSetWindowIcon
    //! @sa     GLFWimage
    //! @note   If the window has not yet been created, the icon will be set after it is created.
    void setIcon(std::vector<GLFWimage> images = std::vector<GLFWimage>())
    {
        icon_ = images;
        if (window_)
            glfwSetWindowIcon(window_, (int)images.size(), images.data());
    }

    //! Returns the window's icon.
    //!
    //! @return  icon images
    //!
    //! @sa     GLFWimage
    std::vector<GLFWimage> icon() const
    {
        return icon_;
    }

    //! Sets the window's position.
    //!
    //! @param  x   Horizontal position
    //! @param  y   Vertical position
    //!
    //! @sa     glfwSetWindowPos
    //! @note   If the window has not yet been created, the icon will be set after it is created.
    void setPosition(int x, int y)
    {
        if (window_)
            glfwSetWindowPos(window_, x, y);
        else
            position_ = Vector2{ x, y };
    }

    //! Returns the window's position.
    //!
    //! @param  [out]   x   Horizontal position
    //! @param  [out]   y   Vertical position
    //!
    //! @sa     glfwGetWindowPos
    void position(int & x, int & y) const
    {
        if (window_)
        {
            glfwGetWindowPos(window_, &x, &y);
        }
        else
        {
            x = position_.value().x;
            y = position_.value().y;
        }
    }

    //! Sets the size of the window.
    //!
    //! @note   If the window has not yet been created, the size will be set after it is created.
    void setSize(int width, int height)
    {
        width_ = width;
        height = height_;
        if (window_)
            glfwSetWindowSize(window_, width, height);
    }

    //! Returns the width and height of the window.
    void size(int & width, int & height) const
    {
        if (window_)
        {
            glfwGetWindowSize(window_, &width, &height);
        }
        else
        {
            width  = width_;
            height = height_;
        }
    }

    //! Limits the size of the window.
    //!
    //! @param  minWidth
    //! @param  minHeight
    //! @param  maxWidth
    //! @param  maxHeight
    //!
    //! @sa     glfwSetWindowSizeLimits
    //! @note   If the window has not yet been created, the size limits will be set after it is created.
    void setSizeLimits(int minWidth = -1, int minHeight = -1, int maxWidth = -1, int maxHeight = -1)
    {
        if (window_)
        {
            glfwSetWindowSizeLimits(window_, minWidth, minHeight, maxWidth, maxHeight);
        }
        else
        {
            minSize_ = Vector2{ minWidth, minHeight };
            maxSize_ = Vector2{ maxWidth, maxHeight };
        }
    }

    //! Sets the window's aspect ratio
    //!
    //! @note   If the window has not yet been created, the aspect ratio will be set after it is created.
    void setAspectRatio(int n, int d)
    {
        if (window_)
            glfwSetWindowAspectRatio(window_, n, d);
        else
            aspectRatio_ = Vector2{ n, d };
    }

    //! Returns the width and height of the window's framebuffer.
    //!
    //! @note   Ignored if the window has not been created.
    void framebufferSize(int & width, int & height) const
    {
        if (window_)
            glfwGetFramebufferSize(window_, &width, &height);
    }

    //! Returns the locations of the edges of the window's frame
    //!
    //! @note   Ignored if the window has not been created.
    void frame(int & left, int & top, int & right, int & bottom) const
    {
        if (window_)
            glfwGetWindowFrameSize(window_, &left, &top, &right, &bottom);
    }

    //! Reduces the window to an icon.
    //!
    //! @note   If the window has not yet been created, the window will be iconified after it is created.
    void iconify()
    {
        if (window_)
        {
            glfwIconifyWindow(window_);
        }
        else
        {
            minified_  = true;
            maximized_ = Deferred<bool>();
            restored_  = Deferred<bool>();
        }
    }

    //! Displays the window normally.
    //!
    //! @note   If the window has not yet been created, the window will be displayed normally after it is created.
    void restore()
    {
        if (window_)
        {
            glfwRestoreWindow(window_);
        }
        else
        {
            restored_  = true;
            minified_  = Deferred<bool>();
            maximized_ = Deferred<bool>();
        }
    }

    //! Fits the window to the size of the screen.
    //!
    //! @note   If the window has not yet been created, the window will be maximized after it is created.
    void maximize()
    {
        if (window_)
        {
            glfwMaximizeWindow(window_);
        }
        else
        {
            maximized_ = true;
            minified_  = Deferred<bool>();
            restored_  = Deferred<bool>();
            shown_     = Deferred<bool>();  // Automatically shown by the maximize
        }
    }

    //! Shows or hides the window.
    //!
    //! @note   If the window has not yet been created, the window will be shown or hidden after it is created.
    void show(bool shown = true)
    {
        shown_ = shown;
        if (window_)
        {
            if (shown)
                glfwShowWindow(window_);
            else
                glfwHideWindow(window_);
        }
    }

    //! Sets the focus to the window.
    //!
    //! @note   If the window has not yet been created, the focus will be set after it is created.
    void focus()
    {
        focused_ = true;
        if (window_)
            glfwFocusWindow(window_);
    }

    //! Returns the window's monitor.
    GLFWmonitor * monitor() const
    {
        if (window_)
            return glfwGetWindowMonitor(window_);
        else
            return monitor_;
    }

    //! Sets the window's monitor parameters.
    //!
    //! @note   Ignored if the window has not yet been created.
    void setMonitor(GLFWmonitor * monitor, int x, int y, int width, int height, int refreshRate)
    {
        if (window_)
            glfwSetWindowMonitor(window_, monitor, x, y, width, height, refreshRate);
    }

    //! Returns the value of the specified attribute.
    int getAttribute(int attr) const
    {
        return 0;
    }

    //! Processes window activity.
    //!
    //! @return    The close value
    //!
    //! @sa     glfwPollEvents
    //! @sa     glfwWindowShouldClose
    //! @note   Also returns false if the window has not yet been created.
    int processEvents()
    {
        if (!window_)
            return false;
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

    template <typename T>
    class Deferred
    {
public:
        Deferred() = default;
        Deferred(T const & value)
            : value_(value)
            , deferred_(true)
        {
        }
        Deferred & operator =(T const & rhs)
        {
            value_    = rhs;
            deferred_ = true;
            return *this;
        }
        ~Deferred() = default;
        operator T() const { return value_; }
        bool deferred() const { return deferred_; }
        T    value() const    { return value_; }

private:
        T value_       = T();
        bool deferred_ = false;
    };

    struct Vector2 { int x; int y; };

    int width_;
    int height_;
    std::string title_;
    GLFWmonitor * monitor_;
    GLFWwindow * share_;
    GLFWwindow * window_;
    Deferred<Vector2> position_;
    Deferred<std::vector<GLFWimage>> icon_;
    Deferred<Vector2> minSize_;
    Deferred<Vector2> maxSize_;
    Deferred<Vector2> aspectRatio_;
    Deferred<bool> minified_;
    Deferred<bool> maximized_;
    Deferred<bool> restored_;
    Deferred<bool> shown_;
    Deferred<bool> focused_;
};
} // namespace Glfwx

#endif // !defined(GLFWX_WINDOW_H)
