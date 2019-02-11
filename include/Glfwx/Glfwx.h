#pragma once

#if !defined(GLFWX_GLFWX_H)
#define GLFWX_GLFWX_H

#include "GLFW/glfw3.h"
#include "Glfwx/Enumerations.h"
#include "Glfwx/Window.h"
#include <vector>
#include <cstdint>

namespace Glfwx
{
//! Initializes GLFW.
    bool init()
    {
        int rv = glfwInit();
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
        uint32_t        count = 0;
        char const **   extensions;

        extensions = glfwGetRequiredInstanceExtensions(&count);
        return std::vector<char const *>(&extensions[0], &extensions[count]);
    }

} // namespace Glfwx

#endif // !defined(GLFWX_GLFWX_H)
