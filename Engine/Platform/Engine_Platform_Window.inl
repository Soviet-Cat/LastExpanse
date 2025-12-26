/* This file is apart of LastExpanse. */
/* Copyright (c) 2025 Soviet-Cat */
/* See LICENSE.md for license details. */

#ifndef __ENGINE_PLATFORM_WINDOW_INL__
#define __ENGINE_PLATFORM_WINDOW_INL__

#include "Engine_Platform_Window.h"

#ifdef __cplusplus
extern "C" {
#endif

ENGINE_INLINE Engine_Void Engine_Platform_WindowInterface_ConstructFromMembers(Engine_Platform_WindowInterface* interface, Engine_Void* param, Engine_Platform_WindowInterface_Function onCreate) {
    interface->param = param; interface->onCreate = onCreate;
}

ENGINE_INLINE Engine_Void ENGINE_Platform_Window_ConstructFromMembers(Engine_Platform_Window* window, Engine_Void* internal, Engine_Platform_WindowInterface interface) {
    window->internal = internal; window->interface = interface;
}

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __ENGINE_PLATFORM_WINDOW_INL__ */