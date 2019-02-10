#include "Glfwx/Glfwx.h"

#include <GLFW/glfw3.h>

#include <cstdint>
#include <vector>

namespace Glfwx
{
//!
//! @return     false if the initialization failed
bool init()
{
    int rv = glfwInit();
    return rv != GLFW_FALSE;
}

void terminate()
{
    glfwTerminate();
}


std::vector<char const *> requiredInstanceExtensions()
{
    uint32_t        count = 0;
    char const **   extensions;

    extensions = glfwGetRequiredInstanceExtensions(&count);
    return std::vector<char const *>(&extensions[0], &extensions[count]);
}
} // namespace Glfwx
