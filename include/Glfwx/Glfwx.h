#if !defined(GLFWX_GLFWX_H)
#define GLFWX_GLFWX_H

#pragma once

#include <cstdint>
#include <Glfwx/Enumerations.h>
#include <Glfwx/Monitor.h>
#include <Glfwx/Window.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

//! C++ wrapper for GLFW.
//!
//! @note   This implementation is based on GLFW 3.3.2.

namespace Glfwx
{
//! Initializes Glfwx.
//!
//! @return     true, if successfully initialized
bool init()
{
    int rv = glfwInit();
#if !defined(NDEBUG)
    if (rv)
        std::cerr << "GLFW: " << glfwGetVersionString() << std::endl;
#endif
    return rv != GLFW_FALSE;
}

//! Shuts down Glfwx.
void terminate()
{
    glfwTerminate();
}

//! Provides some initialization context.
//!
//! @param  id          Hint ID
//! @param  value       Value
//!
//! @sa glfwInitHint
//! @sa Glfwx::Hint
void hint(Hint id, int value)
{
    glfwInitHint((int)id, value);
}

//! Returns the required extensions.
//!
//! @return     List of required extensions
//!
//! @sa glfwGetRequiredInstanceExtensions
std::vector<char const *> requiredInstanceExtensions()
{
    uint32_t      count      = 0;
    char const ** extensions = glfwGetRequiredInstanceExtensions(&count);
    return (extensions && count > 0) ?
           std::vector<char const *>(&extensions[0], &extensions[count]) :
           std::vector<char const *>();
}

//! Returns the GLFW version.
//!
//! @param  [out]   major           Major version
//! @param  [out]   minor           Minor version
//! @param  [out]   revision        Revision
//! @param  [out]   versionString   Version as a string
//!
//! @sa glfwGetVersion
//! @sa glfwGetVersionString
void version(int & major, int & minor, int & revision, std::string & versionString)
{
    glfwGetVersion(&major, &minor, &revision);
    versionString = glfwGetVersionString();
}

//! Returns the status reported by GLFW since the last call.
//!
//! @param  [out]   code            Error code
//! @param  [out]   description     Error description
//!
//! @sa glfwGetError
//! @sa Glfwx::Error
void status(int & code, std::string & description)
{
    char const * d;
    code        = glfwGetError(&d);
    description = d ? std::string(d) : std::string();
}

//! Sets the error callback.
//! @bug not yet implemented
//!
//! @param  cb  Callback function
void setErrorCallback(std::function<void(int, const char *)> const & cb)
{
}

//! RAII for Glfwx.
//!
//! Instantiation of an Instance will initialize GLFW and Glfwx. Destruction will terminate them.
//!
//! @warning    Glfwx::Instance should only be instantiated once, and only if Glfwx::init() and glfwInit() are not called.
//!
//! @sa Glfwx::init()
class Instance
{
public:

    //! Constructor
    Instance()
    {
        ok_ = init();
        if (!ok_)
            throw std::runtime_error("glfwInit() failed.");
    }

    //! Destructor.
    ~Instance()
    {
        if (ok_)
            terminate();
    }

    //! Returns the state of GLFW.
    //!
    //! @return     true, if GLFW is initialized
    bool ok() const { return ok_; }

private:

    //! @cond

    // Prevent copying
    Instance(Instance const &) = delete;
    Instance & operator =(Instance const &) = delete;

    bool ok_ = false;

    //! @endcond
};
} // namespace Glfwx

#endif // !defined(GLFWX_GLFWX_H)
