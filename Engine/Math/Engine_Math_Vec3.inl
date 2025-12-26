/* This file is apart of LastExpanse. */
/* Copyright (c) 2025 Soviet-Cat */
/* See LICENSE.md for license details. */

#ifndef __ENGINE_MATH_VEC3_INL__
#define __ENGINE_MATH_VEC3_INL__

#include "Engine_Math_Vec3.h"
#include "Engine_Memory_Copy.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ENGINE_MATH_DECLARE_VEC3_INL(name) \
\
ENGINE_INLINE Engine_Void Engine_Math_##name##Vec3_ConstructFromElements(Engine_Math_##name##Vec3* vec, Engine_##name x, Engine_##name y, Engine_##name z) { \
    vec->x = x; vec->y = y; vec->z = z; \
} \
ENGINE_INLINE Engine_Void Engine_Math_##name##Vec3_ConstructFromArray(Engine_Math_##name##Vec3* vec, Engine_##name (*array)[3]) { \
    Engine_Memory_Copy(vec->array, *array, 3 * sizeof(Engine_##name)); \
} \

ENGINE_MATH_DECLARE_VEC3_INL(Int8)
ENGINE_MATH_DECLARE_VEC3_INL(UInt8)
ENGINE_MATH_DECLARE_VEC3_INL(Int16)
ENGINE_MATH_DECLARE_VEC3_INL(UInt16)
ENGINE_MATH_DECLARE_VEC3_INL(Int32)
ENGINE_MATH_DECLARE_VEC3_INL(UInt32)
ENGINE_MATH_DECLARE_VEC3_INL(Int64)
ENGINE_MATH_DECLARE_VEC3_INL(UInt64)

ENGINE_MATH_DECLARE_VEC3_INL(Float32)
ENGINE_MATH_DECLARE_VEC3_INL(Float64)
ENGINE_MATH_DECLARE_VEC3_INL(Float128)

ENGINE_MATH_DECLARE_VEC3_INL(Int)
ENGINE_MATH_DECLARE_VEC3_INL(UInt)
ENGINE_MATH_DECLARE_VEC3_INL(Float)

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __ENGINE_MATH_VEC3_INL__ */