#pragma once

#if !defined(GLFWX_WINDOW_H)
#define GLFWX_WINDOW_H

#include <string>

struct GLFWmonitor;
struct GLFWwindow;

namespace Glfwx
{
enum class Hint;

//! Wrapper for GLFW window.
class Window
{
public:

    //! Constructor.
    Window(int width, int height, std::string const & name, void * monitor = nullptr, void * share = nullptr);

    //! Destructor.
    virtual ~Window();

    //! Creates the window.
    int create();

    //! Returns the value of the specified attribute.
    int getAttribute(int attr) const;

    //! Returns the width and height of the window.
    void size(int & width, int & height) const;

    //! Returns the width and height of the window's frame buffer.
    void frameBufferSize(int & width, int & height) const;

    //! Sets the window's icon.
    void setIcon();

    //! Processes window activity until the window is closed.
    void run();

    //! Provides some window initialization context.
    static void hint(Hint id, int value);

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
