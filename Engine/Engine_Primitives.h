/* This file is apart of LastExpanse. */
/* Copyright (c) 2025 Soviet-Cat */
/* See LICENSE.md for license details. */

#ifndef __ENGINE_PRIMITIVES_H__
#define __ENGINE_PRIMITIVES_H__

#include "Engine_Macros.h"

#ifdef __cplusplus
extern "C" {
#endif

#define Engine_Null 0
#define Engine_NullPtr ((void*)0)
#define Engine_True 1
#define Engine_False 0

typedef signed char Engine_Int8;
typedef unsigned char Engine_UInt8;
typedef signed short Engine_Int16;
typedef unsigned short Engine_UInt16;
typedef signed int Engine_Int32;
typedef unsigned int Engine_UInt32;
typedef signed long long Engine_Int64;
typedef unsigned long long Engine_UInt64;

typedef float Engine_Float32;
typedef double Engine_Float64;
typedef long double Engine_Float128;

typedef void Engine_Void;
typedef unsigned char Engine_Bool;
typedef char Engine_Char;
typedef unsigned short Engine_WChar;

#ifdef ENGINE_BITNESS_64
typedef signed long long Engine_Int;
typedef unsigned long long Engine_UInt;
typedef double Engine_Float;
#elifdef ENGINE_BITNESS_32
typedef signed int Engine_Int;
typedef unsigned int Engine_UInt;
typedef float Engine_Float;
#elifdef ENGINE_BITNESS_UNKNOWN
#warning Unknown bitness, defaulting to 32
typedef signed int Engine_Int;
typedef unsigned int Engine_UInt;
typedef float Engine_Float;
#else
#error No bitness defined
#endif /* ENGINE_BITNESS_64 */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __ENGINE_PRIMITIVES_H__*/