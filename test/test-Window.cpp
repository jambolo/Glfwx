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
        Glfwx::Window::hint(Glfwx::Window::Hint::CLIENT_API, Glfwx::Window::NO_API);
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
    openWindow("WindowTest.Construct -- Please close the window to continue.");
    waitForClose();
}

TEST_F(WindowTest, setTitle)
{
    openWindow("WindowTest.setTitle -- If you see this, the test has failed. Please close the window to continue.");
    window_->setTitle("WindowTest.setTitle -- Please close the window to continue.");
    waitForClose();
}

TEST_F(WindowTest, position)
{
    openWindow("WindowTest.position -- Please close the window to continue.");

    int x = -1;
    int y = -1;
    window_->position(x, y);
    EXPECT_NE(x, -1);
    EXPECT_NE(y, -1);
}

TEST_F(WindowTest, setPosition)
{
    openWindow("WindowTest.setPosition -- If this window is not at (640,480), the test has failed. Please close the window to continue.");
    window_->setPosition(640, 480);

    int x = -1;
    int y = -1;
    window_->position(x, y);
    EXPECT_EQ(x, 640);
    EXPECT_EQ(y, 480);

    waitForClose();
}

TEST_F(WindowTest, size)
{
    openWindow("WindowTest.size -- Please close the window to continue.");
    int w = -1;
    int h = -1;
    window_->size(w, h);
    EXPECT_EQ(w, DEFAULT_WIDTH);
    EXPECT_EQ(h, DEFAULT_HEIGHT);
}

TEST_F(WindowTest, setSize)
{
    openWindow("WindowTest.setSize -- If this window is not twice as big as the others, the test has failed. Please close the window to continue.");
    window_->setSize(DEFAULT_WIDTH*2, DEFAULT_HEIGHT*2);

    int w = -1;
    int h = -1;
    window_->size(w, h);
    EXPECT_EQ(w, DEFAULT_WIDTH*2);
    EXPECT_EQ(h, DEFAULT_HEIGHT*2);
 
    waitForClose();
}

TEST_F(WindowTest, DISABLED_setIcon)
{
/*
    openWindow("WindowTest.setIcon -- Please close the window to continue.");
    window_->setIcon(std::vector<GLFWimage> images = std::vector<GLFWimage>())
        {
            glfwSetWindowIcon(window_, (int)images.size(), images.data());
        }
*/
}

TEST_F(WindowTest, DISABLED_setSizeLimits)
{
/*
    openWindow("WindowTest.setSizeLimits -- Please close the window to continue.");
    window_->setSizeLimits(int minWidth = -1, int minHeight = -1, int maxWidth = -1, int maxHeight = -1)
        {
            glfwSetWindowSizeLimits(window_, minWidth, minHeight, maxWidth, maxHeight);
        }
*/
}

TEST_F(WindowTest, DISABLED_setAspectRatio)
{
/*
    openWindow("WindowTest.setAspectRatio -- Please close the window to continue.");
    window_->setAspectRatio(int n, int d)
        {
            glfwSetWindowAspectRatio(window_, n, d);
        }
*/
}

TEST_F(WindowTest, DISABLED_framebufferSize)
{
/*
    openWindow("WindowTest.framebufferSize -- Please close the window to continue.");
    window_->framebufferSize(int & width, int & height) const
        {
            glfwGetFramebufferSize(window_, &width, &height);
        }
*/
}

TEST_F(WindowTest, DISABLED_frame)
{
/*
    openWindow("WindowTest.frame -- Please close the window to continue.");
    window_->frame(int & left, int & top, int & right, int & bottom) const
        {
            glfwGetWindowFrameSize(window_, &left, &top, &right, &bottom);
        }
*/
}

TEST_F(WindowTest, DISABLED_iconify)
{
/*
    openWindow("WindowTest.iconify -- Please close the window to continue.");
    window_->iconify()
        {
            glfwIconifyWindow(window_);
        }
*/
}

TEST_F(WindowTest, DISABLED_restore)
{
/*
    openWindow("WindowTest.restore -- Please close the window to continue.");
    window_->restore()
        {
            glfwRestoreWindow(window_);
        }
*/
}

TEST_F(WindowTest, DISABLED_maximize)
{
/*
    openWindow("WindowTest.maximize -- Please close the window to continue.");
    window_->maximize()
        {
            glfwMaximizeWindow(window_);
        }
*/
}

TEST_F(WindowTest, DISABLED_show)
{
/*
    openWindow("WindowTest.show -- Please close the window to continue.");
    window_->show(bool shown = true)
        {
            if (shown)
                glfwShowWindow(window_);
            else
                glfwHideWindow(window_);
        }
*/
}

TEST_F(WindowTest, DISABLED_focus)
{
/*
    openWindow("WindowTest.focus -- Please close the window to continue.");
    window_->focus()
        {
            glfwFocusWindow(window_);
        }
*/
}

TEST_F(WindowTest, DISABLED_monitor)
{
/*
    openWindow("WindowTest.monitor -- Please close the window to continue.");
    window_->monitor() const
        {
            return glfwGetWindowMonitor(window_);
        }
*/
}

TEST_F(WindowTest, DISABLED_setMonitor)
{
/*
    openWindow("WindowTest.setMonitor -- Please close the window to continue.");
    window_->setMonitor(GLFWmonitor * monitor, int x, int y, int width, int height, int refreshRate)
        {
            glfwSetWindowMonitor(window_, monitor, x, y, width, height, refreshRate);
        }
*/
}

TEST_F(WindowTest, DISABLED_getAttribute)
{
/*
    openWindow("WindowTest.getAttribute -- Please close the window to continue.");
    window_->getAttribute(int attr) const
        {
            return 0;
        }
*/
}

TEST_F(WindowTest, DISABLED_context)
{
/*
    openWindow("WindowTest.context -- Please close the window to continue.");
    window_->context() const
        {
            return context_;
        }
*/
}

TEST_F(WindowTest, DISABLED_setContext)
{
/*
    openWindow("WindowTest.setContext -- Please close the window to continue.");
    window_->setContext(void * context)
        {
            context_ = context;
        }
*/
}

TEST_F(WindowTest, DISABLED_setPositionChangedCallback)
{
/*
    openWindow("WindowTest.setPositionChangedCallback -- Please close the window to continue.");
    window_->setPositionChangedCallback(std::function<void(Window *, int, int)> const & cb)
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
*/
}

TEST_F(WindowTest, DISABLED_setWindowSizeChangedCallback)
{
/*
    openWindow("WindowTest.setWindowSizeChangedCallback -- Please close the window to continue.");
    window_->setWindowSizeChangedCallback(std::function<void(Window *, int, int)> const & cb)
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
*/
}

TEST_F(WindowTest, DISABLED_setCloseCallback)
{
/*
    openWindow("WindowTest.setCloseCallback -- Please close the window to continue.");
    window_->setCloseCallback(std::function<void(Window *)> const & cb)
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
*/
}

TEST_F(WindowTest, DISABLED_setRefreshCallback)
{
/*
    openWindow("WindowTest.setRefreshCallback -- Please close the window to continue.");
    window_->setRefreshCallback(std::function<void(Window *)> const & cb)
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
*/
}

TEST_F(WindowTest, DISABLED_setFocusChangedCallback)
{
/*
    openWindow("WindowTest.setFocusChangedCallback -- Please close the window to continue.");
    window_->setFocusChangedCallback(std::function<void(Window *, bool)> const & cb)
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
*/
}

TEST_F(WindowTest, DISABLED_setIconifyChangedCallback)
{
/*
    openWindow("WindowTest.setIconifyChangedCallback -- Please close the window to continue.");
    window_->setIconifyChangedCallback(std::function<void(Window *, int)> const & cb)
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
*/
}

TEST_F(WindowTest, DISABLED_setFramebufferSizeChangedCallback)
{
/*
    openWindow("WindowTest.setFramebufferSizeChangedCallback -- Please close the window to continue.");
    window_->setFramebufferSizeChangedCallback(std::function<void(Window *, int, int)> const & cb)
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
*/
}

TEST_F(WindowTest, DISABLED_processEvents)
{
/*
    openWindow("WindowTest.processEvents -- Please close the window to continue.");
    int rv = window_->processEvents()
        {
            glfwPollEvents();
            return glfwWindowShouldClose(window_);
        }
*/
}

TEST_F(WindowTest, DISABLED_waitEvents)
{
/*
    openWindow("WindowTest.waitEvents -- Please close the window to continue.");
    int rv = window_->waitEvents()
        {
            glfwWaitEvents();
            return glfwWindowShouldClose(window_);
        }
*/
}

#if defined(GLFW_INCLUDE_VULKAN)

TEST_F(WindowTest, DISABLED_createSurface)
{
/*
    openWindow("WindowTest.createSurface -- Please close the window to continue.");
    VkSurfaceKHR surface = window_->createSurface(VkInstance instance, VkAllocationCallbacks * allocator) const
        {
            VkSurfaceKHR surface;
            if (glfwCreateWindowSurface(instance, window_, allocator, &surface) != VK_SUCCESS)
                throw std::runtime_error("glfwCreateWindowSurface failed.");
            return surface;
        }
*/
}

#endif  // defined(GLFW_INCLUDE_VULKAN)

TEST_F(WindowTest, DISABLED_resetHints)
{
/*
    Window::resetHints()
        {
            glfwDefaultWindowHints();
        }
*/
}

TEST_F(WindowTest, DISABLED_hint)
{
/*
    Window::hint(Hint id, int value)
        {
            glfwWindowHint((int)id, value);
        }
*/
}

int main(int argc, char ** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int rv = RUN_ALL_TESTS();
    return rv;
}
