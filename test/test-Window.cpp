#include <Glfwx/Window.h>

#include <Glfwx/Glfwx.h>
#include <Glfwx/Monitor.h>
#include <gtest/gtest.h>

class WindowTest : public testing::Test
{
public:

    static int constexpr DEFAULT_WIDTH  = 640;
    static int constexpr DEFAULT_HEIGHT = 480;

    WindowTest()
    {
        Glfwx::Window::hint(Glfwx::Hint::eCLIENT_API, Glfwx::eNO_API);
    }

    ~WindowTest()
    {
        delete window_;
    }

    void openWindow(char const * title)
    {
        window_ = new Glfwx::Window(DEFAULT_WIDTH, DEFAULT_HEIGHT, title);
    }

    void waitForClose()
    {
        int flag = 0;
        while (!(flag = window_->waitEvents()))
        {
        }
        EXPECT_EQ(flag, 1);
    }

    Glfwx::Instance glfwx_;
    Glfwx::Window * window_ = nullptr;
};

TEST_F(WindowTest, Construct)
{
    openWindow("WindowTest_Construct -- Close the window.");
    waitForClose();
}

TEST_F(WindowTest, setTitle)
{
    openWindow("WindowTest_setTitle -- If you see this, the test has failed.");
    window_->setTitle("WindowTest_setTitle -- Close the window.");
    waitForClose();
}

TEST_F(WindowTest, setPosition)
{
    openWindow("WindowTest_setPosition -- If this window is not at (0,0), the test has failed.");
    window_->setPosition(0, 0);
/*
    int x = -1;
    int y = -1;
    window_->position(x, y);
    EXPECT_EQ(x, 0);
    EXPECT_EQ(y, 0);
 */
    waitForClose();
}
/*
TEST_F(WindowTest, position)
{
    openWindow("WindowTest_position");
    static int constexpr WINDOW_X = 11;
    static int constexpr WINDOW_Y = 13;
    window_->setPosition(WINDOW_X, WINDOW_Y);
    int x = -1;
    int y = -1;
    window_->position(x, y);
    EXPECT_EQ(x, WINDOW_X);
    EXPECT_EQ(y, WINDOW_Y);
}
*/
TEST_F(WindowTest, setSize)
{
    openWindow("WindowTest_setSize -- If this window is not twice as big, the test has failed.");
    window_->setSize(DEFAULT_WIDTH*2, DEFAULT_HEIGHT*2);
/*
    int w = -1;
    int h = -1;
    window_->size(w, h);
    EXPECT_EQ(w, DEFAULT_WIDTH*2);
    EXPECT_EQ(h, DEFAULT_HEIGHT*2);
 */
    waitForClose();
}

/*
TEST_F(WindowTest, size)
{
    openWindow("WindowTest_size");
    int w = -1;
    int h = -1;
    window_->size(w, h);
    EXPECT_EQ(w, DEFAULT_WIDTH);
    EXPECT_EQ(h, DEFAULT_HEIGHT);
}
*/

#if 0
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

#endif

int main(int argc, char ** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int rv = RUN_ALL_TESTS();
    return rv;
}
