#if !defined(GLFWX_ENUMERATIONS_H)
#define GLFWX_ENUMERATIONS_H

#pragma once

#include <GLFW/glfw3.h>

namespace Glfwx
{
//! @name Constants
//!@{
int constexpr GLFWX_DONT_CARE = GLFW_DONT_CARE; //!< GLFW_DONT_CARE
int constexpr GLFWX_FALSE     = GLFW_FALSE;     //!< GLFW_FALSE
int constexpr GLFWX_TRUE      = GLFW_TRUE;      //!< GLFW_TRUE
//!@}

//! @name Keyboard keys
//!@{
int constexpr KEY_UNKNOWN       = GLFW_KEY_UNKNOWN;         //!< GLFW_KEY_UNKNOWN
int constexpr KEY_SPACE         = GLFW_KEY_SPACE;           //!< GLFW_KEY_SPACE
int constexpr KEY_APOSTROPHE    = GLFW_KEY_APOSTROPHE;      //!< GLFW_KEY_APOSTROPHE
int constexpr KEY_COMMA         = GLFW_KEY_COMMA;           //!< GLFW_KEY_COMMA
int constexpr KEY_MINUS         = GLFW_KEY_MINUS;           //!< GLFW_KEY_MINUS
int constexpr KEY_PERIOD        = GLFW_KEY_PERIOD;          //!< GLFW_KEY_PERIOD
int constexpr KEY_SLASH         = GLFW_KEY_SLASH;           //!< GLFW_KEY_SLASH
int constexpr KEY_0             = GLFW_KEY_0;               //!< GLFW_KEY_0
int constexpr KEY_1             = GLFW_KEY_1;               //!< GLFW_KEY_1
int constexpr KEY_2             = GLFW_KEY_2;               //!< GLFW_KEY_2
int constexpr KEY_3             = GLFW_KEY_3;               //!< GLFW_KEY_3
int constexpr KEY_4             = GLFW_KEY_4;               //!< GLFW_KEY_4
int constexpr KEY_5             = GLFW_KEY_5;               //!< GLFW_KEY_5
int constexpr KEY_6             = GLFW_KEY_6;               //!< GLFW_KEY_6
int constexpr KEY_7             = GLFW_KEY_7;               //!< GLFW_KEY_7
int constexpr KEY_8             = GLFW_KEY_8;               //!< GLFW_KEY_8
int constexpr KEY_9             = GLFW_KEY_9;               //!< GLFW_KEY_9
int constexpr KEY_SEMICOLON     = GLFW_KEY_SEMICOLON;       //!< GLFW_KEY_SEMICOLON
int constexpr KEY_EQUAL         = GLFW_KEY_EQUAL;           //!< GLFW_KEY_EQUAL
int constexpr KEY_A             = GLFW_KEY_A;               //!< GLFW_KEY_A
int constexpr KEY_B             = GLFW_KEY_B;               //!< GLFW_KEY_B
int constexpr KEY_C             = GLFW_KEY_C;               //!< GLFW_KEY_C
int constexpr KEY_D             = GLFW_KEY_D;               //!< GLFW_KEY_D
int constexpr KEY_E             = GLFW_KEY_E;               //!< GLFW_KEY_E
int constexpr KEY_F             = GLFW_KEY_F;               //!< GLFW_KEY_F
int constexpr KEY_G             = GLFW_KEY_G;               //!< GLFW_KEY_G
int constexpr KEY_H             = GLFW_KEY_H;               //!< GLFW_KEY_H
int constexpr KEY_I             = GLFW_KEY_I;               //!< GLFW_KEY_I
int constexpr KEY_J             = GLFW_KEY_J;               //!< GLFW_KEY_J
int constexpr KEY_K             = GLFW_KEY_K;               //!< GLFW_KEY_K
int constexpr KEY_L             = GLFW_KEY_L;               //!< GLFW_KEY_L
int constexpr KEY_M             = GLFW_KEY_M;               //!< GLFW_KEY_M
int constexpr KEY_N             = GLFW_KEY_N;               //!< GLFW_KEY_N
int constexpr KEY_O             = GLFW_KEY_O;               //!< GLFW_KEY_O
int constexpr KEY_P             = GLFW_KEY_P;               //!< GLFW_KEY_P
int constexpr KEY_Q             = GLFW_KEY_Q;               //!< GLFW_KEY_Q
int constexpr KEY_R             = GLFW_KEY_R;               //!< GLFW_KEY_R
int constexpr KEY_S             = GLFW_KEY_S;               //!< GLFW_KEY_S
int constexpr KEY_T             = GLFW_KEY_T;               //!< GLFW_KEY_T
int constexpr KEY_U             = GLFW_KEY_U;               //!< GLFW_KEY_U
int constexpr KEY_V             = GLFW_KEY_V;               //!< GLFW_KEY_V
int constexpr KEY_W             = GLFW_KEY_W;               //!< GLFW_KEY_W
int constexpr KEY_X             = GLFW_KEY_X;               //!< GLFW_KEY_X
int constexpr KEY_Y             = GLFW_KEY_Y;               //!< GLFW_KEY_Y
int constexpr KEY_Z             = GLFW_KEY_Z;               //!< GLFW_KEY_Z
int constexpr KEY_LEFT_BRACKET  = GLFW_KEY_LEFT_BRACKET;    //!< GLFW_KEY_LEFT_BRACKET
int constexpr KEY_BACKSLASH     = GLFW_KEY_BACKSLASH;       //!< GLFW_KEY_BACKSLASH
int constexpr KEY_RIGHT_BRACKET = GLFW_KEY_RIGHT_BRACKET;   //!< GLFW_KEY_RIGHT_BRACKET
int constexpr KEY_GRAVE_ACCENT  = GLFW_KEY_GRAVE_ACCENT;    //!< GLFW_KEY_GRAVE_ACCENT
int constexpr KEY_WORLD_1       = GLFW_KEY_WORLD_1;         //!< GLFW_KEY_WORLD_1
int constexpr KEY_WORLD_2       = GLFW_KEY_WORLD_2;         //!< GLFW_KEY_WORLD_2
int constexpr KEY_ESCAPE        = GLFW_KEY_ESCAPE;          //!< GLFW_KEY_ESCAPE
int constexpr KEY_ENTER         = GLFW_KEY_ENTER;           //!< GLFW_KEY_ENTER
int constexpr KEY_TAB           = GLFW_KEY_TAB;             //!< GLFW_KEY_TAB
int constexpr KEY_BACKSPACE     = GLFW_KEY_BACKSPACE;       //!< GLFW_KEY_BACKSPACE
int constexpr KEY_INSERT        = GLFW_KEY_INSERT;          //!< GLFW_KEY_INSERT
int constexpr KEY_DELETE        = GLFW_KEY_DELETE;          //!< GLFW_KEY_DELETE
int constexpr KEY_RIGHT         = GLFW_KEY_RIGHT;           //!< GLFW_KEY_RIGHT
int constexpr KEY_LEFT          = GLFW_KEY_LEFT;            //!< GLFW_KEY_LEFT
int constexpr KEY_DOWN          = GLFW_KEY_DOWN;            //!< GLFW_KEY_DOWN
int constexpr KEY_UP            = GLFW_KEY_UP;              //!< GLFW_KEY_UP
int constexpr KEY_PAGE_UP       = GLFW_KEY_PAGE_UP;         //!< GLFW_KEY_PAGE_UP
int constexpr KEY_PAGE_DOWN     = GLFW_KEY_PAGE_DOWN;       //!< GLFW_KEY_PAGE_DOWN
int constexpr KEY_HOME          = GLFW_KEY_HOME;            //!< GLFW_KEY_HOME
int constexpr KEY_END           = GLFW_KEY_END;             //!< GLFW_KEY_END
int constexpr KEY_CAPS_LOCK     = GLFW_KEY_CAPS_LOCK;       //!< GLFW_KEY_CAPS_LOCK
int constexpr KEY_SCROLL_LOCK   = GLFW_KEY_SCROLL_LOCK;     //!< GLFW_KEY_SCROLL_LOCK
int constexpr KEY_NUM_LOCK      = GLFW_KEY_NUM_LOCK;        //!< GLFW_KEY_NUM_LOCK
int constexpr KEY_PRINT_SCREEN  = GLFW_KEY_PRINT_SCREEN;    //!< GLFW_KEY_PRINT_SCREEN
int constexpr KEY_PAUSE         = GLFW_KEY_PAUSE;           //!< GLFW_KEY_PAUSE
int constexpr KEY_F1            = GLFW_KEY_F1;              //!< GLFW_KEY_F1
int constexpr KEY_F2            = GLFW_KEY_F2;              //!< GLFW_KEY_F2
int constexpr KEY_F3            = GLFW_KEY_F3;              //!< GLFW_KEY_F3
int constexpr KEY_F4            = GLFW_KEY_F4;              //!< GLFW_KEY_F4
int constexpr KEY_F5            = GLFW_KEY_F5;              //!< GLFW_KEY_F5
int constexpr KEY_F6            = GLFW_KEY_F6;              //!< GLFW_KEY_F6
int constexpr KEY_F7            = GLFW_KEY_F7;              //!< GLFW_KEY_F7
int constexpr KEY_F8            = GLFW_KEY_F8;              //!< GLFW_KEY_F8
int constexpr KEY_F9            = GLFW_KEY_F9;              //!< GLFW_KEY_F9
int constexpr KEY_F10           = GLFW_KEY_F10;             //!< GLFW_KEY_F10
int constexpr KEY_F11           = GLFW_KEY_F11;             //!< GLFW_KEY_F11
int constexpr KEY_F12           = GLFW_KEY_F12;             //!< GLFW_KEY_F12
int constexpr KEY_F13           = GLFW_KEY_F13;             //!< GLFW_KEY_F13
int constexpr KEY_F14           = GLFW_KEY_F14;             //!< GLFW_KEY_F14
int constexpr KEY_F15           = GLFW_KEY_F15;             //!< GLFW_KEY_F15
int constexpr KEY_F16           = GLFW_KEY_F16;             //!< GLFW_KEY_F16
int constexpr KEY_F17           = GLFW_KEY_F17;             //!< GLFW_KEY_F17
int constexpr KEY_F18           = GLFW_KEY_F18;             //!< GLFW_KEY_F18
int constexpr KEY_F19           = GLFW_KEY_F19;             //!< GLFW_KEY_F19
int constexpr KEY_F20           = GLFW_KEY_F20;             //!< GLFW_KEY_F20
int constexpr KEY_F21           = GLFW_KEY_F21;             //!< GLFW_KEY_F21
int constexpr KEY_F22           = GLFW_KEY_F22;             //!< GLFW_KEY_F22
int constexpr KEY_F23           = GLFW_KEY_F23;             //!< GLFW_KEY_F23
int constexpr KEY_F24           = GLFW_KEY_F24;             //!< GLFW_KEY_F24
int constexpr KEY_F25           = GLFW_KEY_F25;             //!< GLFW_KEY_F25
int constexpr KEY_KP_0          = GLFW_KEY_KP_0;            //!< GLFW_KEY_KP_0
int constexpr KEY_KP_1          = GLFW_KEY_KP_1;            //!< GLFW_KEY_KP_1
int constexpr KEY_KP_2          = GLFW_KEY_KP_2;            //!< GLFW_KEY_KP_2
int constexpr KEY_KP_3          = GLFW_KEY_KP_3;            //!< GLFW_KEY_KP_3
int constexpr KEY_KP_4          = GLFW_KEY_KP_4;            //!< GLFW_KEY_KP_4
int constexpr KEY_KP_5          = GLFW_KEY_KP_5;            //!< GLFW_KEY_KP_5
int constexpr KEY_KP_6          = GLFW_KEY_KP_6;            //!< GLFW_KEY_KP_6
int constexpr KEY_KP_7          = GLFW_KEY_KP_7;            //!< GLFW_KEY_KP_7
int constexpr KEY_KP_8          = GLFW_KEY_KP_8;            //!< GLFW_KEY_KP_8
int constexpr KEY_KP_9          = GLFW_KEY_KP_9;            //!< GLFW_KEY_KP_9
int constexpr KEY_KP_DECIMAL    = GLFW_KEY_KP_DECIMAL;      //!< GLFW_KEY_KP_DECIMAL
int constexpr KEY_KP_DIVIDE     = GLFW_KEY_KP_DIVIDE;       //!< GLFW_KEY_KP_DIVIDE
int constexpr KEY_KP_MULTIPLY   = GLFW_KEY_KP_MULTIPLY;     //!< GLFW_KEY_KP_MULTIPLY
int constexpr KEY_KP_SUBTRACT   = GLFW_KEY_KP_SUBTRACT;     //!< GLFW_KEY_KP_SUBTRACT
int constexpr KEY_KP_ADD        = GLFW_KEY_KP_ADD;          //!< GLFW_KEY_KP_ADD
int constexpr KEY_KP_ENTER      = GLFW_KEY_KP_ENTER;        //!< GLFW_KEY_KP_ENTER
int constexpr KEY_KP_EQUAL      = GLFW_KEY_KP_EQUAL;        //!< GLFW_KEY_KP_EQUAL
int constexpr KEY_LEFT_SHIFT    = GLFW_KEY_LEFT_SHIFT;      //!< GLFW_KEY_LEFT_SHIFT
int constexpr KEY_LEFT_CONTROL  = GLFW_KEY_LEFT_CONTROL;    //!< GLFW_KEY_LEFT_CONTROL
int constexpr KEY_LEFT_ALT      = GLFW_KEY_LEFT_ALT;        //!< GLFW_KEY_LEFT_ALT
int constexpr KEY_LEFT_SUPER    = GLFW_KEY_LEFT_SUPER;      //!< GLFW_KEY_LEFT_SUPER
int constexpr KEY_RIGHT_SHIFT   = GLFW_KEY_RIGHT_SHIFT;     //!< GLFW_KEY_RIGHT_SHIFT
int constexpr KEY_RIGHT_CONTROL = GLFW_KEY_RIGHT_CONTROL;   //!< GLFW_KEY_RIGHT_CONTROL
int constexpr KEY_RIGHT_ALT     = GLFW_KEY_RIGHT_ALT;       //!< GLFW_KEY_RIGHT_ALT
int constexpr KEY_RIGHT_SUPER   = GLFW_KEY_RIGHT_SUPER;     //!< GLFW_KEY_RIGHT_SUPER
int constexpr KEY_MENU          = GLFW_KEY_MENU;            //!< GLFW_KEY_MENU
int constexpr KEY_LAST          = GLFW_KEY_LAST;            //!< GLFW_KEY_LAST
//!@}

//! @name Mouse buttons
//!@{
int constexpr MOUSE_1      = GLFW_MOUSE_BUTTON_1;       //!< GLFW_MOUSE_BUTTON_1
int constexpr MOUSE_2      = GLFW_MOUSE_BUTTON_2;       //!< GLFW_MOUSE_BUTTON_2
int constexpr MOUSE_3      = GLFW_MOUSE_BUTTON_3;       //!< GLFW_MOUSE_BUTTON_3
int constexpr MOUSE_4      = GLFW_MOUSE_BUTTON_4;       //!< GLFW_MOUSE_BUTTON_4
int constexpr MOUSE_5      = GLFW_MOUSE_BUTTON_5;       //!< GLFW_MOUSE_BUTTON_5
int constexpr MOUSE_6      = GLFW_MOUSE_BUTTON_6;       //!< GLFW_MOUSE_BUTTON_6
int constexpr MOUSE_7      = GLFW_MOUSE_BUTTON_7;       //!< GLFW_MOUSE_BUTTON_7
int constexpr MOUSE_8      = GLFW_MOUSE_BUTTON_8;       //!< GLFW_MOUSE_BUTTON_8
int constexpr MOUSE_LAST   = GLFW_MOUSE_BUTTON_LAST;    //!< GLFW_MOUSE_BUTTON_LAST
int constexpr MOUSE_LEFT   = GLFW_MOUSE_BUTTON_LEFT;    //!< GLFW_MOUSE_BUTTON_LEFT
int constexpr MOUSE_RIGHT  = GLFW_MOUSE_BUTTON_RIGHT;   //!< GLFW_MOUSE_BUTTON_RIGHT
int constexpr MOUSE_MIDDLE = GLFW_MOUSE_BUTTON_MIDDLE;  //!< GLFW_MOUSE_BUTTON_MIDDLE
//!@}

//! @name Joystick inputs
//!@{
int constexpr JOYSTICK_1    = GLFW_JOYSTICK_1;      //!< GLFW_JOYSTICK_1
int constexpr JOYSTICK_2    = GLFW_JOYSTICK_2;      //!< GLFW_JOYSTICK_2
int constexpr JOYSTICK_3    = GLFW_JOYSTICK_3;      //!< GLFW_JOYSTICK_3
int constexpr JOYSTICK_4    = GLFW_JOYSTICK_4;      //!< GLFW_JOYSTICK_4
int constexpr JOYSTICK_5    = GLFW_JOYSTICK_5;      //!< GLFW_JOYSTICK_5
int constexpr JOYSTICK_6    = GLFW_JOYSTICK_6;      //!< GLFW_JOYSTICK_6
int constexpr JOYSTICK_7    = GLFW_JOYSTICK_7;      //!< GLFW_JOYSTICK_7
int constexpr JOYSTICK_8    = GLFW_JOYSTICK_8;      //!< GLFW_JOYSTICK_8
int constexpr JOYSTICK_9    = GLFW_JOYSTICK_9;      //!< GLFW_JOYSTICK_9
int constexpr JOYSTICK_10   = GLFW_JOYSTICK_10;     //!< GLFW_JOYSTICK_10
int constexpr JOYSTICK_11   = GLFW_JOYSTICK_11;     //!< GLFW_JOYSTICK_11
int constexpr JOYSTICK_12   = GLFW_JOYSTICK_12;     //!< GLFW_JOYSTICK_12
int constexpr JOYSTICK_13   = GLFW_JOYSTICK_13;     //!< GLFW_JOYSTICK_13
int constexpr JOYSTICK_14   = GLFW_JOYSTICK_14;     //!< GLFW_JOYSTICK_14
int constexpr JOYSTICK_15   = GLFW_JOYSTICK_15;     //!< GLFW_JOYSTICK_15
int constexpr JOYSTICK_16   = GLFW_JOYSTICK_16;     //!< GLFW_JOYSTICK_16
int constexpr JOYSTICK_LAST = GLFW_JOYSTICK_LAST;   //!< GLFW_JOYSTICK_LAST
//!@}

//! @name Error codes
//!@{
int constexpr NO_ERROR            = GLFW_NO_ERROR;              //!< GLFW_NO_ERROR
int constexpr NOT_INITIALIZED     = GLFW_NOT_INITIALIZED;       //!< GLFW_NOT_INITIALIZED
int constexpr NO_CURRENT_CONTEXT  = GLFW_NO_CURRENT_CONTEXT;    //!< GLFW_NO_CURRENT_CONTEXT
int constexpr INVALID_ENUM        = GLFW_INVALID_ENUM;          //!< GLFW_INVALID_ENUM
int constexpr INVALID_VALUE       = GLFW_INVALID_VALUE;         //!< GLFW_INVALID_VALUE
int constexpr OUT_OF_MEMORY       = GLFW_OUT_OF_MEMORY;         //!< GLFW_OUT_OF_MEMORY
int constexpr API_UNAVAILABLE     = GLFW_API_UNAVAILABLE;       //!< GLFW_API_UNAVAILABLE
int constexpr VERSION_UNAVAILABLE = GLFW_VERSION_UNAVAILABLE;   //!< GLFW_VERSION_UNAVAILABLE
int constexpr PLATFORM_ERROR      = GLFW_PLATFORM_ERROR;        //!< GLFW_PLATFORM_ERROR
int constexpr FORMAT_UNAVAILABLE  = GLFW_FORMAT_UNAVAILABLE;    //!< GLFW_FORMAT_UNAVAILABLE
int constexpr NO_WINDOW_CONTEXT   = GLFW_NO_WINDOW_CONTEXT;     //!< GLFW_NO_WINDOW_CONTEXT
//!@}

//! Initialization hints.
//! @note as of GLFW 3.3.2
enum class Hint
{
    JOYSTICK_HAT_BUTTONS  = GLFW_JOYSTICK_HAT_BUTTONS,  //!< GLFW_JOYSTICK_HAT_BUTTONS,
    COCOA_CHDIR_RESOURCES = GLFW_COCOA_CHDIR_RESOURCES, //!< GLFW_COCOA_CHDIR_RESOURCES,
    COCOA_MENUBAR         = GLFW_COCOA_MENUBAR,         //!< GLFW_COCOA_MENUBAR,
};
} // namespace Glfwx

#endif // !defined(GLFWX_ENUMERATIONS_H)
