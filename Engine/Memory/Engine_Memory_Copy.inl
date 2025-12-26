/* This file is apart of LastExpanse. */
/* Copyright (c) 2025 Soviet-Cat */
/* See LICENSE.md for license details. */

#ifndef __ENGINE_MEMORY_COPY_INL__
#define __ENGINE_MEMORY_COPY_INL__

#include "Engine_Memory_Copy.h"

#ifdef __cplusplus
extern "C" {
#endif

ENGINE_INLINE Engine_Void Engine_Memory_Copy(Engine_Void* dest, Engine_Void* src, Engine_UInt size) {
    Engine_Char* d = (Engine_Char*)dest;
    Engine_Char* s = (Engine_Char*)src;
    while (size--) {
        *d++ = *s++;
    }
}

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __ENGINE_MEMORY_COPY_INL__ */