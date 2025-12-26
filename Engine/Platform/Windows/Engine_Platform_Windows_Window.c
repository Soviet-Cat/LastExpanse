/* This file is apart of LastExpanse. */
/* Copyright (c) 2025 Soviet-Cat */
/* See LICENSE.md for license details. */

#include "Engine_Platform_Windows_Window.prv.h"
#include "Engine_Platform_Window.h"
#include "Engine_Memory_Raw.h"

Engine_Result Engine_Platform_Window_Create(Engine_Platform_Window* window, Engine_Math_UInt32Rect2 rect, const Engine_Char* title) {
    Engine_Memory_RawAlloc(&window->internal, sizeof(Engine_Platform_Windows_WindowInternal));
    if ( window->internal == Engine_NullPtr ) { return Engine_Result_FAILURE_MEMORY_ALLOC; }


}
Engine_Result Engine_Platform_Window_Destroy(Engine_Platform_Window* window) {

}