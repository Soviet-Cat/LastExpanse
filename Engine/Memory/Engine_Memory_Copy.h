/* This file is apart of LastExpanse. */
/* Copyright (c) 2025 Soviet-Cat */
/* See LICENSE.md for license details. */

#ifndef __ENGINE_MEMORY_COPY_H__
#define __ENGINE_MEMORY_COPY_H__

#include "Engine_Common.h"

#ifdef __cplusplus
extern "C" {
#endif

ENGINE_INLINE Engine_Void Engine_Memory_Copy(Engine_Void* dest, Engine_Void* src, Engine_UInt size);

#ifdef __cplusplus
} /* extern "C" */
#endif

#include "Engine_Memory_Copy.inl"

#endif /* __ENGINE_MEMORY_COPY_H__ */