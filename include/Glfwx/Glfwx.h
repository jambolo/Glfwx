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

namespace Glfwx
{
//! Initializes GLFW.
bool init()
{
    int rv = glfwInit();
#if !defined(NDEBUG)
    if (rv)
        std::cerr << "GLFW: " << glfwGetVersionString() << std::endl;
#endif
    return rv != GLFW_FALSE;
}

//! Shuts down GLFW.
void terminate()
{
    glfwTerminate();
}

//! Returns the required extensions.
std::vector<char const *> requiredInstanceExtensions()
{
    uint32_t      count      = 0;
    char const ** extensions = glfwGetRequiredInstanceExtensions(&count);
    return (extensions && count > 0) ?
           std::vector<char const *>(&extensions[0], &extensions[count]) :
           std::vector<char const *>();
}

//! RAII for Glfw.
struct Instance
{
    Instance()
    {
        ok_ = init();
        if (!ok_)
            throw std::runtime_error("glfwInit() failed.");
    }

    ~Instance()
    {
        if (ok_)
            terminate();
    }

    // Prevent copying
    Instance(Instance const &) = delete;
    Instance & operator =(Instance const &) = delete;

    bool ok_ = false; //!< True if Glfwx::init() was called successfully
};
} // namespace Glfwx

#endif // !defined(GLFWX_GLFWX_H)
