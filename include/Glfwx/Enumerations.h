#pragma once

#if !defined(GLFWX_ENUMERATIONS_H)
#define GLFWX_GLFWX_H

#include <GLFW/glfw3.h>

namespace Glfwx
{
//! Constants.
enum
{
    eANY_RELEASE_BEHAVIOR   = GLFW_ANY_RELEASE_BEHAVIOR,
    eDONT_CARE              = GLFW_DONT_CARE,
    eEGL_CONTEXT_API        = GLFW_EGL_CONTEXT_API,
    eFALSE                  = GLFW_FALSE,
    eLOSE_CONTEXT_ON_RESET  = GLFW_LOSE_CONTEXT_ON_RESET,
    eNATIVE_CONTEXT_API     = GLFW_NATIVE_CONTEXT_API,
    eNO_API                 = GLFW_NO_API,
    eNO_RESET_NOTIFICATION  = GLFW_NO_RESET_NOTIFICATION,
    eNO_ROBUSTNESS          = GLFW_NO_ROBUSTNESS,
    eOPENGL_ANY_PROFILE     = GLFW_OPENGL_ANY_PROFILE,
    eOPENGL_API             = GLFW_OPENGL_API,
    eOPENGL_COMPAT_PROFILE  = GLFW_OPENGL_COMPAT_PROFILE,
    eOPENGL_CORE_PROFILE    = GLFW_OPENGL_CORE_PROFILE,
    eOPENGL_ES_API          = GLFW_OPENGL_ES_API,
    eRELEASE_BEHAVIOR_FLUSH = GLFW_RELEASE_BEHAVIOR_FLUSH,
    eRELEASE_BEHAVIOR_NONE  = GLFW_RELEASE_BEHAVIOR_NONE,
    eTRUE                   = GLFW_TRUE
};

//! Keyboard keys.
enum class Key
{
    eUNKNOWN       = GLFW_KEY_UNKNOWN,
    eSPACE         = GLFW_KEY_SPACE,
    eAPOSTROPHE    = GLFW_KEY_APOSTROPHE,
    eCOMMA         = GLFW_KEY_COMMA,
    eMINUS         = GLFW_KEY_MINUS,
    ePERIOD        = GLFW_KEY_PERIOD,
    eSLASH         = GLFW_KEY_SLASH,
    e0             = GLFW_KEY_0,
    e1             = GLFW_KEY_1,
    e2             = GLFW_KEY_2,
    e3             = GLFW_KEY_3,
    e4             = GLFW_KEY_4,
    e5             = GLFW_KEY_5,
    e6             = GLFW_KEY_6,
    e7             = GLFW_KEY_7,
    e8             = GLFW_KEY_8,
    e9             = GLFW_KEY_9,
    eSEMICOLON     = GLFW_KEY_SEMICOLON,
    eEQUAL         = GLFW_KEY_EQUAL,
    eA             = GLFW_KEY_A,
    eB             = GLFW_KEY_B,
    eC             = GLFW_KEY_C,
    eD             = GLFW_KEY_D,
    eE             = GLFW_KEY_E,
    eF             = GLFW_KEY_F,
    eG             = GLFW_KEY_G,
    eH             = GLFW_KEY_H,
    eI             = GLFW_KEY_I,
    eJ             = GLFW_KEY_J,
    eK             = GLFW_KEY_K,
    eL             = GLFW_KEY_L,
    eM             = GLFW_KEY_M,
    eN             = GLFW_KEY_N,
    eO             = GLFW_KEY_O,
    eP             = GLFW_KEY_P,
    eQ             = GLFW_KEY_Q,
    eR             = GLFW_KEY_R,
    eS             = GLFW_KEY_S,
    eT             = GLFW_KEY_T,
    eU             = GLFW_KEY_U,
    eV             = GLFW_KEY_V,
    eW             = GLFW_KEY_W,
    eX             = GLFW_KEY_X,
    eY             = GLFW_KEY_Y,
    eZ             = GLFW_KEY_Z,
    eLEFT_BRACKET  = GLFW_KEY_LEFT_BRACKET,
    eBACKSLASH     = GLFW_KEY_BACKSLASH,
    eRIGHT_BRACKET = GLFW_KEY_RIGHT_BRACKET,
    eGRAVE_ACCENT  = GLFW_KEY_GRAVE_ACCENT,
    eWORLD_1       = GLFW_KEY_WORLD_1,
    eWORLD_2       = GLFW_KEY_WORLD_2,
    eESCAPE        = GLFW_KEY_ESCAPE,
    eENTER         = GLFW_KEY_ENTER,
    eTAB           = GLFW_KEY_TAB,
    eBACKSPACE     = GLFW_KEY_BACKSPACE,
    eINSERT        = GLFW_KEY_INSERT,
    eDELETE        = GLFW_KEY_DELETE,
    eRIGHT         = GLFW_KEY_RIGHT,
    eLEFT          = GLFW_KEY_LEFT,
    eDOWN          = GLFW_KEY_DOWN,
    eUP            = GLFW_KEY_UP,
    ePAGE_UP       = GLFW_KEY_PAGE_UP,
    ePAGE_DOWN     = GLFW_KEY_PAGE_DOWN,
    eHOME          = GLFW_KEY_HOME,
    eEND           = GLFW_KEY_END,
    eCAPS_LOCK     = GLFW_KEY_CAPS_LOCK,
    eSCROLL_LOCK   = GLFW_KEY_SCROLL_LOCK,
    eNUM_LOCK      = GLFW_KEY_NUM_LOCK,
    ePRINT_SCREEN  = GLFW_KEY_PRINT_SCREEN,
    ePAUSE         = GLFW_KEY_PAUSE,
    eF1            = GLFW_KEY_F1,
    eF2            = GLFW_KEY_F2,
    eF3            = GLFW_KEY_F3,
    eF4            = GLFW_KEY_F4,
    eF5            = GLFW_KEY_F5,
    eF6            = GLFW_KEY_F6,
    eF7            = GLFW_KEY_F7,
    eF8            = GLFW_KEY_F8,
    eF9            = GLFW_KEY_F9,
    eF10           = GLFW_KEY_F10,
    eF11           = GLFW_KEY_F11,
    eF12           = GLFW_KEY_F12,
    eF13           = GLFW_KEY_F13,
    eF14           = GLFW_KEY_F14,
    eF15           = GLFW_KEY_F15,
    eF16           = GLFW_KEY_F16,
    eF17           = GLFW_KEY_F17,
    eF18           = GLFW_KEY_F18,
    eF19           = GLFW_KEY_F19,
    eF20           = GLFW_KEY_F20,
    eF21           = GLFW_KEY_F21,
    eF22           = GLFW_KEY_F22,
    eF23           = GLFW_KEY_F23,
    eF24           = GLFW_KEY_F24,
    eF25           = GLFW_KEY_F25,
    eKP_0          = GLFW_KEY_KP_0,
    eKP_1          = GLFW_KEY_KP_1,
    eKP_2          = GLFW_KEY_KP_2,
    eKP_3          = GLFW_KEY_KP_3,
    eKP_4          = GLFW_KEY_KP_4,
    eKP_5          = GLFW_KEY_KP_5,
    eKP_6          = GLFW_KEY_KP_6,
    eKP_7          = GLFW_KEY_KP_7,
    eKP_8          = GLFW_KEY_KP_8,
    eKP_9          = GLFW_KEY_KP_9,
    eKP_DECIMAL    = GLFW_KEY_KP_DECIMAL,
    eKP_DIVIDE     = GLFW_KEY_KP_DIVIDE,
    eKP_MULTIPLY   = GLFW_KEY_KP_MULTIPLY,
    eKP_SUBTRACT   = GLFW_KEY_KP_SUBTRACT,
    eKP_ADD        = GLFW_KEY_KP_ADD,
    eKP_ENTER      = GLFW_KEY_KP_ENTER,
    eKP_EQUAL      = GLFW_KEY_KP_EQUAL,
    eLEFT_SHIFT    = GLFW_KEY_LEFT_SHIFT,
    eLEFT_CONTROL  = GLFW_KEY_LEFT_CONTROL,
    eLEFT_ALT      = GLFW_KEY_LEFT_ALT,
    eLEFT_SUPER    = GLFW_KEY_LEFT_SUPER,
    eRIGHT_SHIFT   = GLFW_KEY_RIGHT_SHIFT,
    eRIGHT_CONTROL = GLFW_KEY_RIGHT_CONTROL,
    eRIGHT_ALT     = GLFW_KEY_RIGHT_ALT,
    eRIGHT_SUPER   = GLFW_KEY_RIGHT_SUPER,
    eMENU          = GLFW_KEY_MENU,
    eLAST          = GLFW_KEY_LAST
};

//! Mouse buttons.
enum class Mouse
{
    eBUTTON_1      = GLFW_MOUSE_BUTTON_1,
    eBUTTON_2      = GLFW_MOUSE_BUTTON_2,
    eBUTTON_3      = GLFW_MOUSE_BUTTON_3,
    eBUTTON_4      = GLFW_MOUSE_BUTTON_4,
    eBUTTON_5      = GLFW_MOUSE_BUTTON_5,
    eBUTTON_6      = GLFW_MOUSE_BUTTON_6,
    eBUTTON_7      = GLFW_MOUSE_BUTTON_7,
    eBUTTON_8      = GLFW_MOUSE_BUTTON_8,
    eBUTTON_LAST   = GLFW_MOUSE_BUTTON_LAST,
    eBUTTON_LEFT   = GLFW_MOUSE_BUTTON_LEFT,
    eBUTTON_RIGHT  = GLFW_MOUSE_BUTTON_RIGHT,
    eBUTTON_MIDDLE = GLFW_MOUSE_BUTTON_MIDDLE
};

//! Joystick inputs.
enum class Joystick
{
    e1    = GLFW_JOYSTICK_1,
    e2    = GLFW_JOYSTICK_2,
    e3    = GLFW_JOYSTICK_3,
    e4    = GLFW_JOYSTICK_4,
    e5    = GLFW_JOYSTICK_5,
    e6    = GLFW_JOYSTICK_6,
    e7    = GLFW_JOYSTICK_7,
    e8    = GLFW_JOYSTICK_8,
    e9    = GLFW_JOYSTICK_9,
    e10   = GLFW_JOYSTICK_10,
    e11   = GLFW_JOYSTICK_11,
    e12   = GLFW_JOYSTICK_12,
    e13   = GLFW_JOYSTICK_13,
    e14   = GLFW_JOYSTICK_14,
    e15   = GLFW_JOYSTICK_15,
    e16   = GLFW_JOYSTICK_16,
    eLAST = GLFW_JOYSTICK_LAST
};

//! Error codes.
enum class Error
{
    eNOT_INITIALIZED     = GLFW_NOT_INITIALIZED,
    eNO_CURRENT_CONTEXT  = GLFW_NO_CURRENT_CONTEXT,
    eINVALID_ENUM        = GLFW_INVALID_ENUM,
    eINVALID_VALUE       = GLFW_INVALID_VALUE,
    eOUT_OF_MEMORY       = GLFW_OUT_OF_MEMORY,
    eAPI_UNAVAILABLE     = GLFW_API_UNAVAILABLE,
    eVERSION_UNAVAILABLE = GLFW_VERSION_UNAVAILABLE,
    ePLATFORM_ERROR      = GLFW_PLATFORM_ERROR,
    eFORMAT_UNAVAILABLE  = GLFW_FORMAT_UNAVAILABLE,
    eNO_WINDOW_CONTEXT   = GLFW_NO_WINDOW_CONTEXT
};

//! Window opening hints.
enum class Hint
{
    eRESIZABLE                = GLFW_RESIZABLE,
    eVISIBLE                  = GLFW_VISIBLE,
    eDECORATED                = GLFW_DECORATED,
    eFOCUSED                  = GLFW_FOCUSED,
    eAUTO_ICONIFY             = GLFW_AUTO_ICONIFY,
    eFLOATING                 = GLFW_FLOATING,
    eMAXIMIZED                = GLFW_MAXIMIZED,
    eRED_BITS                 = GLFW_RED_BITS,
    eGREEN_BITS               = GLFW_GREEN_BITS,
    eBLUE_BITS                = GLFW_BLUE_BITS,
    eALPHA_BITS               = GLFW_ALPHA_BITS,
    eDEPTH_BITS               = GLFW_DEPTH_BITS,
    eSTENCIL_BITS             = GLFW_STENCIL_BITS,
    eACCUM_RED_BITS           = GLFW_ACCUM_RED_BITS,
    eACCUM_GREEN_BITS         = GLFW_ACCUM_GREEN_BITS,
    eACCUM_BLUE_BITS          = GLFW_ACCUM_BLUE_BITS,
    eACCUM_ALPHA_BITS         = GLFW_ACCUM_ALPHA_BITS,
    eAUX_BUFFERS              = GLFW_AUX_BUFFERS,
    eSAMPLES                  = GLFW_SAMPLES,
    eREFRESH_RATE             = GLFW_REFRESH_RATE,
    eSTEREO                   = GLFW_STEREO,
    eSRGB_CAPABLE             = GLFW_SRGB_CAPABLE,
    eDOUBLEBUFFER             = GLFW_DOUBLEBUFFER,
    eCLIENT_API               = GLFW_CLIENT_API,
    eCONTEXT_CREATION_API     = GLFW_CONTEXT_CREATION_API,
    eCONTEXT_VERSION_MAJOR    = GLFW_CONTEXT_VERSION_MAJOR,
    eCONTEXT_VERSION_MINOR    = GLFW_CONTEXT_VERSION_MINOR,
    eCONTEXT_ROBUSTNESS       = GLFW_CONTEXT_ROBUSTNESS,
    eCONTEXT_RELEASE_BEHAVIOR = GLFW_CONTEXT_RELEASE_BEHAVIOR,
    eOPENGL_FORWARD_COMPAT    = GLFW_OPENGL_FORWARD_COMPAT,
    eOPENGL_DEBUG_CONTEXT     = GLFW_OPENGL_DEBUG_CONTEXT,
    eOPENGL_PROFILE           = GLFW_OPENGL_PROFILE
};
} // namespace Glfwx

#endif // !defined(GLFWX_ENUMERATIONS_H)
