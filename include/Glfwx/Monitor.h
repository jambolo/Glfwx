#if !defined(GLFWX_MONITOR_H)
#define GLFWX_MONITOR_H

#pragma once

#include "Glfwx/Enumerations.h"
#include <GLFW/glfw3.h>
#include <functional>
#include <stdexcept>
#include <string>
#include <vector>
#include <iterator>

namespace Glfwx
{
class Monitor
    {
    public:

        //! Video mode information.
        //!
        //! @sa     GLFWvidmode
        using VideoMode = GLFWvidmode;

        //! Gamma ramp specification.
        using GammaRamp = GLFWgammaramp;

        //! Returns a list of copies of the available monitors
        //!
        //! @sa     glfwGetMonitors
        static std::vector<Monitor> enumerate()
        {
            int count = 0;
            GLFWmonitor** monitorPointers = glfwGetMonitors(&count);

            std::vector<Monitor> rv;
            rv.reserve(count);
            for (int i = 0; i < count; ++i)
            {
                rv.emplace_back(monitorPointers[i]);
            }
            return rv;
        }

        //! Returns a copy of the primary monitor.
        //!
        //! @sa     glfwGetPrimaryMonitor
        static Monitor primary()
        {
            return Monitor(glfwGetPrimaryMonitor());
        }

        //! Returns the position of the monitor's viewport on the virtual screen.
        //!
        //! @param  x       Where to store the monitor x-coordinate, or nullptr
        //! @param  y       Where to store the monitor y-coordinate, or nullptr
        //!
        //! @sa     glfwGetMonitorPos
        void position(int * x, int * y) const
        {
            glfwGetMonitorPos(monitor_, x, y);
        }

        //! Returns the work area of the monitor.
        //!
        //! @param  x       Where to store the monitor x-coordinate, or nullptr
        //! @param  y       Where to store the monitor y-coordinate, or nullptr
        //! @param  width   Where to store the monitor width, or nullptr
        //! @param  height  Where to store the monitor height, or nullptr
        //!
        //! @sa     glfwGetMonitorWorkarea
        void workArea(int * x, int * y, int * width, int * height) const
        {
            glfwGetMonitorWorkarea(monitor_, x, y, width, height);
        }

        //! Returns the physical size of the monitor.
        //!
        //! @param  width   Where to store the width, in millimetres, of the monitor's display area, or nullptr
        //! @param  height  Where to store the height, in millimetres, of the monitor's display area, or nullptr
        //!
        //! @sa     glfwGetMonitorPhysicalSize
        void size(int * width, int * height) const
        {
            glfwGetMonitorPhysicalSize(monitor_, width, height);
        }

        //! Returns the content scale for the monitor.
        //!
        //! @param  x   Where to store the x-axis content scale, or nullptr
        //! @param  y   Where to store the y-axis content scale, or nullptr
        //!
        //! @sa glfwGetMonitorContentScale
        void scale(float *x, float * y) const
        {
            glfwGetMonitorContentScale(monitor_, x, y);
        }

        //! Returns the name of the monitor.
        //!
        //! @sa glfwGetMonitorName
        std::string name() const
        {
            return std::string(glfwGetMonitorName(monitor_));
        }

        //! Sets the user-defined context.
        //!
        //! @param  context      User-defined context
        //!
        //! @sa     glfwSetMonitorUserPointer
        void setContext(void * context)
        {
            glfwSetMonitorUserPointer(monitor_, context);
        }

        //! Returns the user-defined context.
        //!
        //! @sa     glfwGetMonitorUserPointer
        void * context() const
        {
            return glfwGetMonitorUserPointer(monitor_);
        }

        //! Sets the function to be called when the connection status of a monitor has changed.
        //!
        //! @param  cb      Callback function
        //!
        //! @sa     glfwSetMonitorCallback
        static void setConnectionChangedCallback(std::function<void(Monitor const &, bool)> const & cb)
        {
            handleConnectionChanged_ = cb;
            if (cb)
            {
                glfwSetMonitorCallback(onConnectionChanged);
            }
            else
            {
                glfwSetMonitorCallback(nullptr);
            }
        }

        //! Returns the available video modes for the monitor.
        //!
        //! @sa     glfwGetVideoModes
        std::vector<VideoMode> enumerateVideoModes() const
        {
            int count;
            GLFWvidmode const * modes = glfwGetVideoModes(monitor_, &count);
            return (modes && count > 0) ? std::vector<VideoMode>(modes, modes + count) : std::vector<VideoMode>();
        }

        //! Returns the current mode of the monitor.
        //!
        //! @sa     glfwGetVideoMode
        VideoMode videoMode() const
        {
            GLFWvidmode const * mode = glfwGetVideoMode(monitor_);
            return mode ? *mode : VideoMode{ 0, 0, 0, 0, 0, 0 };
        }

        //! Generates a gamma ramp and sets it for the monitor.
        //!
        //! @param  gamma   The desired exponent.
        //!
        //! @sa     glfwSetGamma
        void setGamma(float gamma)
        {
            glfwSetGamma(monitor_, gamma);
        }

        //! Sets the current gamma ramp for the monitor.
        //!
        //! @param  ramp        The gamma ramp to use.
        //!
        //! @sa     glfwSetGammaRamp
        void setGammaRamp(GammaRamp const & ramp)
        {
            glfwSetGammaRamp(monitor_, &ramp);
        }

        //! Returns the current gamma ramp for the monitor.
        //!
        //! @sa     glfwGetGammaRamp
        GammaRamp gammaRamp() const
        {
            GLFWgammaramp const * ramp = glfwGetGammaRamp(monitor_);
            return ramp ? *ramp : GammaRamp{ nullptr, nullptr, nullptr, 0 };
        }

    private:

        explicit Monitor(GLFWmonitor * m)
        : monitor_(m)
        {
        }

        static void onConnectionChanged(GLFWmonitor * monitor, int status)
        {
            handleConnectionChanged_(Monitor(monitor), status == GLFW_CONNECTED);
        }

        GLFWmonitor * monitor_;
        static std::function<void(Monitor const &, bool)> handleConnectionChanged_;
    };
}

#endif // !defined(GLFWX_MONITOR_H)
