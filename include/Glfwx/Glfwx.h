#if !defined(GLFWX_GLFWX_H)
#define GLFWX_GLFWX_H

#pragma once

#include "Glfwx/Enumerations.h"
#include "Glfwx/Window.h"
#include <GLFW/glfw3.h>
#include <cstdint>
#include <vector>
#include <iostream>

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
    uint32_t      count = 0;
    char const ** extensions;

    extensions = glfwGetRequiredInstanceExtensions(&count);
    return std::vector<char const *>(&extensions[0], &extensions[count]);
}

//! RAII for Glfw.
struct Instance
{
    Instance()
    {
        init();
    }
    ~Instance()
    {
        terminate();
    }
    Instance(Instance const &) = delete;
    Instance & operator =(Instance const &) = delete;
};
} // namespace Glfwx

#endif // !defined(GLFWX_GLFWX_H)
