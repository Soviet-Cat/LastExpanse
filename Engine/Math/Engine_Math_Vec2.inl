/* This file is apart of LastExpanse. */
/* Copyright (c) 2025 Soviet-Cat */
/* See LICENSE.md for license details. */

#ifndef __ENGINE_MATH_VEC2_INL__
#define __ENGINE_MATH_VEC2_INL__

#include "Engine_Math_Vec2.h"
#include "Engine_Memory_Copy.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ENGINE_MATH_DECLARE_VEC2_INL(name) \
ENGINE_INLINE Engine_Void Engine_Math_##name##Vec2_ConstructFromElements(Engine_Math_##name##Vec2* vec, Engine_##name x, Engine_##name y) { \
    vec->x = x; vec->y = y; \
} \
ENGINE_INLINE Engine_Void Engine_Math_##name##Vec2_ConstructFromArray(Engine_Math_##name##Vec2* vec, Engine_##name (*array)[2]) { \
    Engine_Memory_Copy(vec->array, *array, 2 * sizeof(Engine_##name)); \
} \

ENGINE_MATH_DECLARE_VEC2_INL(Int8)
ENGINE_MATH_DECLARE_VEC2_INL(UInt8)
ENGINE_MATH_DECLARE_VEC2_INL(Int16)
ENGINE_MATH_DECLARE_VEC2_INL(UInt16)
ENGINE_MATH_DECLARE_VEC2_INL(Int32)
ENGINE_MATH_DECLARE_VEC2_INL(UInt32)
ENGINE_MATH_DECLARE_VEC2_INL(Int64)
ENGINE_MATH_DECLARE_VEC2_INL(UInt64)

ENGINE_MATH_DECLARE_VEC2_INL(Float32)
ENGINE_MATH_DECLARE_VEC2_INL(Float64)
ENGINE_MATH_DECLARE_VEC2_INL(Float128)

ENGINE_MATH_DECLARE_VEC2_INL(Int)
ENGINE_MATH_DECLARE_VEC2_INL(UInt)
ENGINE_MATH_DECLARE_VEC2_INL(Float)

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __ENGINE_MATH_VEC2_INL__ */