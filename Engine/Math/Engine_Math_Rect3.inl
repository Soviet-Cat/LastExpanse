/* This file is apart of LastExpanse. */
/* Copyright (c) 2025 Soviet-Cat */
/* See LICENSE.md for license details. */

#ifndef __ENGINE_MATH_RECT3_INL__
#define __ENGINE_MATH_RECT3_INL__

#include "Engine_Math_Rect3.h"
#include "Engine_Memory_Copy.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ENGINE_MATH_DECLARE_RECT3_INL(name) \
ENGINE_INLINE Engine_Void Engine_Math_##name##Rect3_ConstructFromElements(Engine_Math_##name##Rect3* rect, Engine_##name x, Engine_##name y, Engine_##name z, Engine_##name w, Engine_##name h, Engine_##name d) { \
    rect->x = x; rect->y = y; rect->z = z; rect->w = w; rect->h = h; rect->d = d;\
} \
ENGINE_INLINE Engine_Void Engine_Math_##name##Rect3_ConstructFromVectors(Engine_Math_##name##Rect3* rect, Engine_Math_##name##Vec3 xyz, Engine_Math_##name##Vec3 whd) { \
    rect->xyz = xyz; rect->whd = whd; \
} \
ENGINE_INLINE Engine_Void Engine_Math_##name##Rect3_ConstructFromArray(Engine_Math_##name##Rect3* rect, Engine_##name (*array)[6]) { \
    Engine_Memory_Copy(rect->array, *array, 6 * sizeof(Engine_##name)); \
} \

ENGINE_MATH_DECLARE_RECT3_INL(Int8)
ENGINE_MATH_DECLARE_RECT3_INL(UInt8)
ENGINE_MATH_DECLARE_RECT3_INL(Int16)
ENGINE_MATH_DECLARE_RECT3_INL(UInt16)
ENGINE_MATH_DECLARE_RECT3_INL(Int32)
ENGINE_MATH_DECLARE_RECT3_INL(UInt32)
ENGINE_MATH_DECLARE_RECT3_INL(Int64)
ENGINE_MATH_DECLARE_RECT3_INL(UInt64)

ENGINE_MATH_DECLARE_RECT3_INL(Float32)
ENGINE_MATH_DECLARE_RECT3_INL(Float64)
ENGINE_MATH_DECLARE_RECT3_INL(Float128)

ENGINE_MATH_DECLARE_RECT3_INL(Int)
ENGINE_MATH_DECLARE_RECT3_INL(UInt)
ENGINE_MATH_DECLARE_RECT3_INL(Float)


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __ENGINE_MATH_RECT3_INL__ */