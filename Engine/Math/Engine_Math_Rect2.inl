/* This file is apart of LastExpanse. */
/* Copyright (c) 2025 Soviet-Cat */
/* See LICENSE.md for license details. */

#ifndef __ENGINE_MATH_RECT2_INL__
#define __ENGINE_MATH_RECT2_INL__

#include "Engine_Math_Rect2.h"
#include "Engine_Memory_Copy.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ENGINE_MATH_DECLARE_RECT2_INL(name) \
ENGINE_INLINE Engine_Void Engine_Math_##name##Rect2_ConstructFromElements(Engine_Math_##name##Rect2* rect, Engine_##name x, Engine_##name y, Engine_##name w, Engine_##name h) {  \
    rect->x = x; rect->y = y; rect->w = w; rect->h = h; \
} \
ENGINE_INLINE Engine_Void Engine_Math_##name##Rect2_ConstructFromVectors(Engine_Math_##name##Rect2* rect, Engine_Math_##name##Vec2 xy, Engine_Math_##name##Vec2 wh) { \
    rect->xy = xy; rect->wh = wh; \
} \
ENGINE_INLINE Engine_Void Engine_Math_##name##Rect2_ConstructFromArray(Engine_Math_##name##Rect2* rect, Engine_##name (*array)[4]) { \
    Engine_Memory_Copy(rect->array, *array, 4 * sizeof(Engine_##name)); \
}

ENGINE_MATH_DECLARE_RECT2_INL(Int8)
ENGINE_MATH_DECLARE_RECT2_INL(UInt8)
ENGINE_MATH_DECLARE_RECT2_INL(Int16)
ENGINE_MATH_DECLARE_RECT2_INL(UInt16)
ENGINE_MATH_DECLARE_RECT2_INL(Int32)
ENGINE_MATH_DECLARE_RECT2_INL(UInt32)
ENGINE_MATH_DECLARE_RECT2_INL(Int64)
ENGINE_MATH_DECLARE_RECT2_INL(UInt64)

ENGINE_MATH_DECLARE_RECT2_INL(Float32)
ENGINE_MATH_DECLARE_RECT2_INL(Float64)
ENGINE_MATH_DECLARE_RECT2_INL(Float128)

ENGINE_MATH_DECLARE_RECT2_INL(Int)
ENGINE_MATH_DECLARE_RECT2_INL(UInt)
ENGINE_MATH_DECLARE_RECT2_INL(Float)


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __ENGINE_MATH_RECT2_INL__ */