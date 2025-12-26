/* This file is apart of LastExpanse. */
/* Copyright (c) 2025 Soviet-Cat */
/* See LICENSE.md for license details. */

#ifndef __ENGINE_MATH_VEC2_H__
#define __ENGINE_MATH_VEC2_H__

#include "Engine_Common.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ENGINE_MATH_DECLARE_VEC2_H(name) \
typedef union { \
    struct { \
        Engine_##name x, y; \
    }; \
    struct { \
        Engine_##name w, h; \
    }; \
    Engine_##name array[2]; \
} Engine_Math_##name##Vec2; \
\
ENGINE_INLINE Engine_Void Engine_Math_##name##Vec2_ConstructFromElements(Engine_Math_##name##Vec2* vec, Engine_##name x, Engine_##name y); \
ENGINE_INLINE Engine_Void Engine_Math_##name##Vec2_ConstructFromArray(Engine_Math_##name##Vec2* vec, Engine_##name (*array)[2]); \

ENGINE_MATH_DECLARE_VEC2_H(Int8)
ENGINE_MATH_DECLARE_VEC2_H(UInt8)
ENGINE_MATH_DECLARE_VEC2_H(Int16)
ENGINE_MATH_DECLARE_VEC2_H(UInt16)
ENGINE_MATH_DECLARE_VEC2_H(Int32)
ENGINE_MATH_DECLARE_VEC2_H(UInt32)
ENGINE_MATH_DECLARE_VEC2_H(Int64)
ENGINE_MATH_DECLARE_VEC2_H(UInt64)

ENGINE_MATH_DECLARE_VEC2_H(Float32)
ENGINE_MATH_DECLARE_VEC2_H(Float64)
ENGINE_MATH_DECLARE_VEC2_H(Float128)

ENGINE_MATH_DECLARE_VEC2_H(Int)
ENGINE_MATH_DECLARE_VEC2_H(UInt)
ENGINE_MATH_DECLARE_VEC2_H(Float)

#ifdef __cplusplus
} /* extern "C" */
#endif

#include "Engine_Math_Vec2.inl"

#endif /* __ENGINE_MATH_VEC2_H__ */