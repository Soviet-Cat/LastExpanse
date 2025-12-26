/* This file is apart of LastExpanse. */
/* Copyright (c) 2025 Soviet-Cat */
/* See LICENSE.md for license details. */

#ifndef __ENGINE_MATH_RECT3_H__
#define __ENGINE_MATH_RECT3_H__

#include "Engine_Common.h"
#include "Engine_Math_Vec3.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ENGINE_MATH_DECLARE_RECT3_H(name) \
typedef union { \
    struct { \
        Engine_##name x, y, z, w, h, d; \
    }; \
    struct { \
        Engine_Math_##name##Vec3 xyz, whd; \
    }; \
    Engine_##name array[6]; \
} Engine_Math_##name##Rect3; \
\
ENGINE_INLINE Engine_Void Engine_Math_##name##Rect3_ConstructFromElements(Engine_Math_##name##Rect3* rect, Engine_##name x, Engine_##name y, Engine_##name z, Engine_##name w, Engine_##name h, Engine_##name d); \
ENGINE_INLINE Engine_Void Engine_Math_##name##Rect3_ConstructFromVectors(Engine_Math_##name##Rect3* rect, Engine_Math_##name##Vec3 xyz, Engine_Math_##name##Vec3 whd); \
ENGINE_INLINE Engine_Void Engine_Math_##name##Rect3_ConstructFromArray(Engine_Math_##name##Rect3* rect, Engine_##name (*array)[6]); \

ENGINE_MATH_DECLARE_RECT3_H(Int8)
ENGINE_MATH_DECLARE_RECT3_H(UInt8)
ENGINE_MATH_DECLARE_RECT3_H(Int16)
ENGINE_MATH_DECLARE_RECT3_H(UInt16)
ENGINE_MATH_DECLARE_RECT3_H(Int32)
ENGINE_MATH_DECLARE_RECT3_H(UInt32)
ENGINE_MATH_DECLARE_RECT3_H(Int64)
ENGINE_MATH_DECLARE_RECT3_H(UInt64)

ENGINE_MATH_DECLARE_RECT3_H(Float32)
ENGINE_MATH_DECLARE_RECT3_H(Float64)
ENGINE_MATH_DECLARE_RECT3_H(Float128)

ENGINE_MATH_DECLARE_RECT3_H(Int)
ENGINE_MATH_DECLARE_RECT3_H(UInt)
ENGINE_MATH_DECLARE_RECT3_H(Float)

#ifdef __cplusplus
} /* extern "C" */
#endif

#include "Engine_Math_Rect3.inl"

#endif /* __ENGINE_MATH_IRECT3_H__ */