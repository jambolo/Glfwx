#pragma once

#if !defined(GLFWX_GLFWX_H)
#define GLFWX_GLFWX_H

#include "Glfwx/Enumerations.h"
#include "Glfwx/Window.h"

namespace Glfwx
{
//! Initializes GLFW.
bool start();

//! Shuts down GLFW.
void finish();

//! Returns the required extensions.
std::vector<char const *> requiredInstanceExtensions();
} // namespace Glfwx

#endif // !defined(GLFWX_GLFWX_H)
