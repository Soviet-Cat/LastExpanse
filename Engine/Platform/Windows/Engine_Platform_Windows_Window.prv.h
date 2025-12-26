/* This file is apart of LastExpanse. */
/* Copyright (c) 2025 Soviet-Cat */
/* See LICENSE.md for license details. */

#ifndef __ENGINE_PLATFORM_WINDOWS_WINDOW_PRV_H__
#define __ENGINE_PLATFORM_WINDOWS_WINDOW_PRV_H__

#include "Engine_Common.h"
#ifdef ENGINE_SYSTEM_WINDOWS

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    HWND windowHandle;
} Engine_Platform_Windows_WindowInternal;

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* ENGINE_SYSTEM_WINDOWS */

#endif /* __ENGINE_PLATFORM_WINDOWS_WINDOW_PRV_H__ */