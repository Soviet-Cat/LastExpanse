/* This file is apart of LastExpanse. */
/* Copyright (c) 2025 Soviet-Cat */
/* See LICENSE.md for license details. */

#ifndef __ENGINE_PLATFORM_WINDOW_H__
#define __ENGINE_PLATFORM_WINDOW_H__

#include "Engine_Common.h"
#include "Engine_Math_Vec2.h"
#include "Engine_Math_Rect2.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum : Engine_UInt32 {
    Engine_Platform_WindowType_WINDOWED,
    Engine_Platform_WindowType_BORDERLESS,
    Engine_Platform_WindowType_FULLSCREEN
} Engine_Platform_WindowType;

struct Engine_Platform_Window; /* forward declare */
typedef Engine_UInt32 (*Engine_Platform_WindowInterface_Function)(Engine_Void* param, struct Engine_Platform_Window* window, Engine_Void* args);

typedef struct {
    Engine_Void* param;
    Engine_Platform_WindowInterface_Function onCreate;
} Engine_Platform_WindowInterface;

ENGINE_INLINE Engine_Void Engine_Platform_WindowInterface_ConstructFromMembers(Engine_Platform_WindowInterface* interface, Engine_Void* param, Engine_Platform_WindowInterface_Function onCreate);

typedef struct Engine_Platform_Window {
    Engine_Void* internal;
    Engine_Platform_WindowInterface interface;
} Engine_Platform_Window;

ENGINE_INLINE Engine_Void ENGINE_Platform_Window_ConstructFromMembers(Engine_Platform_Window* window, Engine_Void* internal, Engine_Platform_WindowInterface interface);

ENGINE_DECL Engine_Result Engine_Platform_Window_Create(Engine_Platform_Window* window, Engine_Math_UInt32Rect2 rect, const Engine_Char* title);
ENGINE_DECL Engine_Result Engine_Platform_Window_Destroy(Engine_Platform_Window* window);

ENGINE_DECL Engine_Result Engine_Platform_Window_GetTitle(Engine_Platform_Window window, Engine_Char** title);
ENGINE_DECL Engine_Result Engine_Platform_Window_SetTitle(Engine_Platform_Window window, const Engine_Char* title);

ENGINE_DECL Engine_Result Engine_Platform_Window_GetWidth(Engine_Platform_Window window, Engine_UInt32* width);
ENGINE_DECL Engine_Result Engine_Platform_Window_SetWidth(Engine_Platform_Window window, Engine_UInt32 width);

ENGINE_DECL Engine_Result Engine_Platform_Window_GetHeight(Engine_Platform_Window window, Engine_UInt32* height);
ENGINE_DECL Engine_Result Engine_Platform_Window_SetHeight(Engine_Platform_Window window, Engine_UInt32 height);

ENGINE_DECL Engine_Result Engine_Platform_Window_GetPosition(Engine_Platform_Window window, Engine_Math_UInt32Vec2* vec);
ENGINE_DECL Engine_Result Engine_Platform_Window_SetPosition(Engine_Platform_Window window, Engine_Math_UInt32Vec2 vec);

ENGINE_DECL Engine_Result Engine_Platform_Window_GetSize(Engine_Platform_Window window, Engine_Math_UInt32Vec2* vec);
ENGINE_DECL Engine_Result Engine_Platform_Window_SetSize(Engine_Platform_Window window, Engine_Math_UInt32Vec2 vec);

ENGINE_DECL Engine_Result Engine_Platform_Window_GetRect(Engine_Platform_Window window, Engine_Math_UInt32Rect2* rect);
ENGINE_DECL Engine_Result Engine_Platform_Window_SetRect(Engine_Platform_Window window, Engine_Math_UInt32Rect2 rect);

#ifdef __cplusplus
} /* extern "C" */
#endif

#include "Engine_Platform_Window.inl"

#endif /* __ENGINE_PLATFORM_WINDOW_H__ */