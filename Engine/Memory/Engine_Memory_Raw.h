/* This file is apart of LastExpanse. */
/* Copyright (c) 2025 Soviet-Cat */
/* See LICENSE.md for license details. */

#ifndef __ENGINE_MEMORY_RAW_H__
#define __ENGINE_MEMORY_RAW_H__

#include "Engine_Common.h"

#ifdef __cplusplus
extern "C" {
#endif

ENGINE_DECL Engine_Void Engine_Memory_RawAlloc(Engine_Void** dest, Engine_UInt size);
ENGINE_DECL Engine_Void Engine_Memory_RawFree(Engine_Void** dest);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __ENGINE_MEMORY_RAW_H__ */