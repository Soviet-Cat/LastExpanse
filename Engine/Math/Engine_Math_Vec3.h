/* This file is apart of LastExpanse. */
/* Copyright (c) 2025 Soviet-Cat */
/* See LICENSE.md for license details. */

#ifndef __ENGINE_MATH_VEC3_H__
#define __ENGINE_MATH_VEC3_H__

#include "Engine_Common.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ENGINE_MATH_DECLARE_VEC3_H(name) \
typedef union { \
    struct { \
        Engine_##name x, y, z; \
    }; \
    struct { \
        Engine_##name w, h, d; \
    }; \
    Engine_##name array[3]; \
} Engine_Math_##name##Vec3; \
\
ENGINE_INLINE Engine_Void Engine_Math_##name##Vec3_ConstructFromElements(Engine_Math_##name##Vec3* vec, Engine_##name x, Engine_##name y, Engine_##name z); \
ENGINE_INLINE Engine_Void Engine_Math_##name##Vec3_ConstructFromArray(Engine_Math_##name##Vec3* vec, Engine_##name (*array)[3]); \


ENGINE_MATH_DECLARE_VEC3_H(Int8)
ENGINE_MATH_DECLARE_VEC3_H(UInt8)
ENGINE_MATH_DECLARE_VEC3_H(Int16)
ENGINE_MATH_DECLARE_VEC3_H(UInt16)
ENGINE_MATH_DECLARE_VEC3_H(Int32)
ENGINE_MATH_DECLARE_VEC3_H(UInt32)
ENGINE_MATH_DECLARE_VEC3_H(Int64)
ENGINE_MATH_DECLARE_VEC3_H(UInt64)

ENGINE_MATH_DECLARE_VEC3_H(Float32)
ENGINE_MATH_DECLARE_VEC3_H(Float64)
ENGINE_MATH_DECLARE_VEC3_H(Float128)

ENGINE_MATH_DECLARE_VEC3_H(Int)
ENGINE_MATH_DECLARE_VEC3_H(UInt)
ENGINE_MATH_DECLARE_VEC3_H(Float)

#ifdef __cplusplus
} /* extern "C" */
#endif

#include "Engine_Math_Vec3.inl"

#endif /* __ENGINE_MATH_VEC3_H__ */