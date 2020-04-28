#if !defined(GLFWX_WINDOW_H)
#define GLFWX_WINDOW_H

#pragma once

#include <functional>
#include <Glfwx/Enumerations.h>
#include <Glfwx/Monitor.h>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <string>
#include <vector>

namespace Glfwx
{
//! C++ wrapper for a GLFW window.
//!
//! @sa     GLFWwindow
class Window
{
public:

    //! Window hints.
    //! @note as of GLFW 3.3.2
    enum class Hint
    {
        FOCUSED                  = GLFW_FOCUSED,
        ICONIFIED                = GLFW_ICONIFIED,
        RESIZABLE                = GLFW_RESIZABLE,
        VISIBLE                  = GLFW_VISIBLE,
        DECORATED                = GLFW_DECORATED,
        AUTO_ICONIFY             = GLFW_AUTO_ICONIFY,
        FLOATING                 = GLFW_FLOATING,
        MAXIMIZED                = GLFW_MAXIMIZED,
        CENTER_CURSOR            = GLFW_CENTER_CURSOR,
        TRANSPARENT_FRAMEBUFFER  = GLFW_TRANSPARENT_FRAMEBUFFER,
        HOVERED                  = GLFW_HOVERED,
        FOCUS_ON_SHOW            = GLFW_FOCUS_ON_SHOW,
        RED_BITS                 = GLFW_RED_BITS,
        GREEN_BITS               = GLFW_GREEN_BITS,
        BLUE_BITS                = GLFW_BLUE_BITS,
        ALPHA_BITS               = GLFW_ALPHA_BITS,
        DEPTH_BITS               = GLFW_DEPTH_BITS,
        STENCIL_BITS             = GLFW_STENCIL_BITS,
        ACCUM_RED_BITS           = GLFW_ACCUM_RED_BITS,
        ACCUM_GREEN_BITS         = GLFW_ACCUM_GREEN_BITS,
        ACCUM_BLUE_BITS          = GLFW_ACCUM_BLUE_BITS,
        ACCUM_ALPHA_BITS         = GLFW_ACCUM_ALPHA_BITS,
        AUX_BUFFERS              = GLFW_AUX_BUFFERS,
        STEREO                   = GLFW_STEREO,
        SAMPLES                  = GLFW_SAMPLES,
        SRGB_CAPABLE             = GLFW_SRGB_CAPABLE,
        REFRESH_RATE             = GLFW_REFRESH_RATE,
        DOUBLEBUFFER             = GLFW_DOUBLEBUFFER,
        CLIENT_API               = GLFW_CLIENT_API,
        CONTEXT_VERSION_MAJOR    = GLFW_CONTEXT_VERSION_MAJOR,
        CONTEXT_VERSION_MINOR    = GLFW_CONTEXT_VERSION_MINOR,
        CONTEXT_REVISION         = GLFW_CONTEXT_REVISION,
        CONTEXT_ROBUSTNESS       = GLFW_CONTEXT_ROBUSTNESS,
        OPENGL_FORWARD_COMPAT    = GLFW_OPENGL_FORWARD_COMPAT,
        OPENGL_DEBUG_CONTEXT     = GLFW_OPENGL_DEBUG_CONTEXT,
        OPENGL_PROFILE           = GLFW_OPENGL_PROFILE,
        CONTEXT_RELEASE_BEHAVIOR = GLFW_CONTEXT_RELEASE_BEHAVIOR,
        CONTEXT_NO_ERROR         = GLFW_CONTEXT_NO_ERROR,
        CONTEXT_CREATION_API     = GLFW_CONTEXT_CREATION_API,
        SCALE_TO_MONITOR         = GLFW_SCALE_TO_MONITOR,
        COCOA_RETINA_FRAMEBUFFER = GLFW_COCOA_RETINA_FRAMEBUFFER,
        COCOA_FRAME_NAME         = GLFW_COCOA_FRAME_NAME,
        COCOA_GRAPHICS_SWITCHING = GLFW_COCOA_GRAPHICS_SWITCHING,
        X11_CLASS_NAME           = GLFW_X11_CLASS_NAME,
        X11_INSTANCE_NAME        = GLFW_X11_INSTANCE_NAME,
        JOYSTICK_HAT_BUTTONS     = GLFW_JOYSTICK_HAT_BUTTONS,
        COCOA_CHDIR_RESOURCES    = GLFW_COCOA_CHDIR_RESOURCES,
        COCOA_MENUBAR            = GLFW_COCOA_MENUBAR
    };

    //! Window attributes.
    //! @note as of GLFW 3.3.2
    enum class Attribute
    {
        FOCUSED                  = GLFW_FOCUSED,
        ICONIFIED                = GLFW_ICONIFIED,
        VISIBLE                  = GLFW_VISIBLE,
        DECORATED                = GLFW_DECORATED,
        AUTO_ICONIFY             = GLFW_AUTO_ICONIFY,
        RESIZABLE                = GLFW_RESIZABLE,
        FLOATING                 = GLFW_FLOATING,
        MAXIMIZED                = GLFW_MAXIMIZED,
        TRANSPARENT_FRAMEBUFFER  = GLFW_TRANSPARENT_FRAMEBUFFER,
        HOVERED                  = GLFW_HOVERED,
        FOCUS_ON_SHOW            = GLFW_FOCUS_ON_SHOW,
        CLIENT_API               = GLFW_CLIENT_API,
        CONTEXT_VERSION_MAJOR    = GLFW_CONTEXT_VERSION_MAJOR,
        CONTEXT_VERSION_MINOR    = GLFW_CONTEXT_VERSION_MINOR,
        CONTEXT_REVISION         = GLFW_CONTEXT_REVISION,
        CONTEXT_ROBUSTNESS       = GLFW_CONTEXT_ROBUSTNESS,
        OPENGL_FORWARD_COMPAT    = GLFW_OPENGL_FORWARD_COMPAT,
        OPENGL_DEBUG_CONTEXT     = GLFW_OPENGL_DEBUG_CONTEXT,
        OPENGL_PROFILE           = GLFW_OPENGL_PROFILE,
        CONTEXT_RELEASE_BEHAVIOR = GLFW_CONTEXT_RELEASE_BEHAVIOR,
        CONTEXT_NO_ERROR         = GLFW_CONTEXT_NO_ERROR,
        CONTEXT_CREATION_API     = GLFW_CONTEXT_CREATION_API,
    };

    //! @name Client API attribute values
    //! @note as of GLFW 3.3.2
    //! @sa CLIENT_API
    //!@{
    static int constexpr NO_API        = GLFW_NO_API;
    static int constexpr OPENGL_API    = GLFW_OPENGL_API;
    static int constexpr OPENGL_ES_API = GLFW_OPENGL_ES_API;
    //!@}

    //! @name Context robustness attribute values
    //! @note as of GLFW 3.3.2
    //! @sa CONTEXT_ROBUSTNESS
    //!@{
    static int constexpr NO_ROBUSTNESS         = GLFW_NO_ROBUSTNESS;
    static int constexpr NO_RESET_NOTIFICATION = GLFW_NO_RESET_NOTIFICATION;
    static int constexpr LOSE_CONTEXT_ON_RESET = GLFW_LOSE_CONTEXT_ON_RESET;
    //!@}

    //! @name OpenGL profile attribute values
    //! @note as of GLFW 3.3.2
    //! @sa OPENGL_PROFILE
    //!@{
    static int constexpr OPENGL_ANY_PROFILE    = GLFW_OPENGL_ANY_PROFILE;
    static int constexpr OPENGL_CORE_PROFILE   = GLFW_OPENGL_CORE_PROFILE;
    static int constexpr OPENGL_COMPAT_PROFILE = GLFW_OPENGL_COMPAT_PROFILE;
    //!@}

    //! @name Context release behavior attribute values
    //! @note as of GLFW 3.3.2
    //! @sa CONTEXT_RELEASE_BEHAVIOR
    //!@{
    static int constexpr ANY_RELEASE_BEHAVIOR   = GLFW_ANY_RELEASE_BEHAVIOR;
    static int constexpr RELEASE_BEHAVIOR_FLUSH = GLFW_RELEASE_BEHAVIOR_FLUSH;
    static int constexpr RELEASE_BEHAVIOR_NONE  = GLFW_RELEASE_BEHAVIOR_NONE;
    //!@}

    //! @name Context creation API attribute values
    //! @note as of GLFW 3.3.2
    //! @sa CONTEXT_CREATION_API
    //!@{
    static int constexpr NATIVE_CONTEXT_API = GLFW_NATIVE_CONTEXT_API;
    static int constexpr EGL_CONTEXT_API    = GLFW_EGL_CONTEXT_API;
    static int constexpr OSMESA_CONTEXT_API = GLFW_OSMESA_CONTEXT_API;
    //!@}

    //! Constructor.
    //!
    //! @param  width       The desired width of the window (must be > 0)
    //! @param  height      The desired height of the window (must be > 0)
    //! @param  title       The initial UTF-8 window title
    //! @param  monitor     The monitor to use for full screen mode, or nullptr for windowed mode (optional)
    //! @param  share       The window whose context to share resources with, or nullptr to not share resources (optional)
    //!
    //! @sa hint()

    Window(int width, int height, char const * title, Monitor * monitor = nullptr, GLFWwindow * share = nullptr)
    {
        if (width <= 0 || height <= 0)
            throw std::invalid_argument("Window::Window: width <= 0 || height <= 0");
        window_ = glfwCreateWindow(width, height, title, (monitor) ? (GLFWmonitor *)*monitor : nullptr, share);
        if (!window_)
            throw std::runtime_error("glfwCreateWindow failed.");
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
    //!
    //! @param  width       Size
    //! @param  height      Size
    void setSize(int width, int height)
    {
        glfwSetWindowSize(window_, width, height);
    }

    //! Returns the width and height of the window.
    //!
    //! @param  [out]   width       Size
    //! @param  [out]   height      Size
    void size(int & width, int & height) const
    {
        glfwGetWindowSize(window_, &width, &height);
    }

    //! Returns the content scale.
    //!
    //! @param  [out]   x       Scale
    //! @param  [out]   y       Scale
    void contentScale(float & x, float & y) const
    {
        glfwGetWindowContentScale(window_, &x, &y);
    }

    //! Limits the size of the window.
    //!
    //! @param  minWidth        Minimum size (-1 = no limit, optional, default is -1)
    //! @param  minHeight       Minimum size (-1 = no limit, optional, default is -1)
    //! @param  maxWidth        Maximum size (-1 = no limit, optional, default is -1)
    //! @param  maxHeight       Maximum size (-1 = no limit, optional, default is -1)
    //!
    //! @sa     glfwSetWindowSizeLimits
    void setSizeLimits(int minWidth = -1, int minHeight = -1, int maxWidth = -1, int maxHeight = -1)
    {
        glfwSetWindowSizeLimits(window_, minWidth, minHeight, maxWidth, maxHeight);
    }

    //! Sets the window's aspect ratio.
    //!
    //! The aspect ratio is set the value of the fraction n/d.
    //!
    //! @param  n   numerator
    //! @param  d   denominator
    void setAspectRatio(int n, int d)
    {
        glfwSetWindowAspectRatio(window_, n, d);
    }

    //! Returns the width and height of the window's framebuffer.
    //!
    //! @param  [out]   width   Width
    //! @param  [out]   height  Height
    void framebufferSize(int & width, int & height) const
    {
        glfwGetFramebufferSize(window_, &width, &height);
    }

    //! Returns the locations of the edges of the window's frame.
    //!
    //! @param  [out]   left        Location of the left edge
    //! @param  [out]   top         Location of the top edge
    //! @param  [out]   right       Location of the right edge
    //! @param  [out]   bottom      Location of the bottom edge
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
    //!
    //! @param  shown       Shows if true, hides if false (optional, default is true)
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
    //!
    //! @return     The window's monitor
    Monitor monitor() const
    {
        return Monitor(glfwGetWindowMonitor(window_));
    }

    //! Sets the window's monitor parameters.
    //!
    //! @param  monitor         Monitor to display window
    //! @param  x               Location
    //! @param  y               Location
    //! @param  width           Size
    //! @param  height          Size
    //! @param  refreshRate     Refresh rate
    void setMonitor(GLFWmonitor * monitor, int x, int y, int width, int height, int refreshRate)
    {
        glfwSetWindowMonitor(window_, monitor, x, y, width, height, refreshRate);
    }

    //! Sets the value of the specified attribute.
    //!
    //! @param  id      The attribute to change
    //! @param  value   THe value to set
    //!
    //! @sa Attribute
    void setAttribute(Attribute id, int value)
    {
        glfwSetWindowAttrib(window_, static_cast<int>(id), value);
    }

    //! Returns the value of the specified attribute.
    //!
    //! @param  id      The attribute to query
    //!
    //! @return     The attribute's value
    int attribute(Attribute id) const
    {
        return glfwGetWindowAttrib(window_, static_cast<int>(id));
    }

    //! Saves a context for the window.
    //!
    //! @param  context     Value to set
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
            glfwSetWindowPosCallback(window_, onPositionChanged);
        else
            glfwSetWindowPosCallback(window_, nullptr);
    }

    //! Sets the function to be called when the window changes size.
    //!
    //! @param  cb      Callback function
    void setWindowSizeChangedCallback(std::function<void(Window *, int, int)> const & cb)
    {
        handleWindowSizeChanged_ = cb;
        if (cb)
            glfwSetWindowSizeCallback(window_, onWindowSizeChanged);
        else
            glfwSetWindowSizeCallback(window_, nullptr);
    }

    //! Sets the function to be called when the window is about to close.
    //!
    //! @param  cb      Callback function
    void setCloseCallback(std::function<void(Window *)> const & cb)
    {
        handleClose_ = cb;
        if (cb)
            glfwSetWindowCloseCallback(window_, onClose);
        else
            glfwSetWindowCloseCallback(window_, nullptr);
    }

    //! Sets the function to be called when the window needs to be refreshed.
    //!
    //! @param  cb      Callback function
    void setRefreshCallback(std::function<void(Window *)> const & cb)
    {
        handleRefresh_ = cb;
        if (cb)
            glfwSetWindowRefreshCallback(window_, onRefresh);
        else
            glfwSetWindowRefreshCallback(window_, nullptr);
    }

    //! Sets the function to be called when the window gains or loses focus.
    //!
    //! @param  cb      Callback function
    void setFocusChangedCallback(std::function<void(Window *, bool)> const & cb)
    {
        handleFocusChanged_ = cb;
        if (cb)
            glfwSetWindowFocusCallback(window_, onFocusChanged);
        else
            glfwSetWindowFocusCallback(window_, nullptr);
    }

    //! Sets the function to be called when the window's iconified status has changed.
    //!
    //! @param  cb      Callback function
    void setIconifyChangedCallback(std::function<void(Window *, int)> const & cb)
    {
        handleIconifyChanged_ = cb;
        if (cb)
            glfwSetWindowIconifyCallback(window_, onIconifyChanged);
        else
            glfwSetWindowIconifyCallback(window_, nullptr);
    }

    //! Sets the function to be called when the window's framebuffer changes size.
    //!
    //! @param  cb      Callback function
    void setFramebufferSizeChangedCallback(std::function<void(Window *, int, int)> const & cb)
    {
        handleFramebufferSizeChanged_ = cb;
        if (cb)
            glfwSetFramebufferSizeCallback(window_, onFramebufferSizeChanged);
        else
            glfwSetFramebufferSizeCallback(window_, nullptr);
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
    //! @name Vulkan-specific
    //! These methods are specific to Vulkan and defined only when GLFW_INCLUDE_VULKAN is defined
    //!@{

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

    //!@}
#endif  // defined(GLFW_INCLUDE_VULKAN)

    //! Resets all window hints back to default values.
    //!
    //! @sa Hint
    //! @sa glfwDefaultWindowHints
    static void resetHints()
    {
        glfwDefaultWindowHints();
    }

    //! Provides some window initialization context.
    //! @param  id      Hint ID
    //! @param  value   Value
    //!
    //! @sa Hint
    //! @sa glfwWindowHint
    static void hint(Hint id, int value)
    {
        glfwWindowHint(static_cast<int>(id), value);
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
