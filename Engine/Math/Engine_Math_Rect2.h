/* This file is apart of LastExpanse. */
/* Copyright (c) 2025 Soviet-Cat */
/* See LICENSE.md for license details. */

#ifndef __ENGINE_MATH_RECT2_H__
#define __ENGINE_MATH_RECT2_H__

#include "Engine_Common.h"
#include "Engine_Math_Vec2.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ENGINE_MATH_DECLARE_RECT2_H(name) \
typedef union { \
    struct { \
        Engine_##name x, y, w, h; \
    }; \
    struct { \
        Engine_Math_##name##Vec2 xy, wh; \
    }; \
    Engine_##name array[4]; \
} Engine_Math_##name##Rect2; \
\
ENGINE_INLINE Engine_Void Engine_Math_##name##Rect2_ConstructFromElements(Engine_Math_##name##Rect2* rect, Engine_##name x, Engine_##name y, Engine_##name w, Engine_##name h); \
ENGINE_INLINE Engine_Void Engine_Math_##name##Rect2_ConstructFromVectors(Engine_Math_##name##Rect2* rect, Engine_Math_##name##Vec2 xy, Engine_Math_##name##Vec2 wh); \
ENGINE_INLINE Engine_Void Engine_Math_##name##Rect2_ConstructFromArray(Engine_Math_##name##Rect2* rect, Engine_##name (*array)[4]); \

ENGINE_MATH_DECLARE_RECT2_H(Int8)
ENGINE_MATH_DECLARE_RECT2_H(UInt8)
ENGINE_MATH_DECLARE_RECT2_H(Int16)
ENGINE_MATH_DECLARE_RECT2_H(UInt16)
ENGINE_MATH_DECLARE_RECT2_H(Int32)
ENGINE_MATH_DECLARE_RECT2_H(UInt32)
ENGINE_MATH_DECLARE_RECT2_H(Int64)
ENGINE_MATH_DECLARE_RECT2_H(UInt64)

ENGINE_MATH_DECLARE_RECT2_H(Float32)
ENGINE_MATH_DECLARE_RECT2_H(Float64)
ENGINE_MATH_DECLARE_RECT2_H(Float128)

ENGINE_MATH_DECLARE_RECT2_H(Int)
ENGINE_MATH_DECLARE_RECT2_H(UInt)
ENGINE_MATH_DECLARE_RECT2_H(Float)

#ifdef __cplusplus
} /* extern "C" */
#endif

#include "Engine_Math_Rect2.inl"

#endif /* __ENGINE_MATH_IRECT2_H__ */