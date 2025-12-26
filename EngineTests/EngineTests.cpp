/* This file is apart of LastExpanse. */
/* Copyright (c) 2025 Soviet-Cat */
/* See LICENSE.md for license details. */

#include <Engine.h>
#include <iostream>
#include <cstring>

#define TEST_SIZEOF(name, expected) \
total++; \
if (sizeof(name) * 8 != expected) { \
    failures++; \
    std::cout << "\t\033[31m[FAILED] Tested size of " << #name << " - expected " << expected << " got " << sizeof(name) * 8 << "\033[0m\n"; \
} else { \
    std::cout << "\t\033[32m[SUCCESS] Tested size of " << #name << " - expected " << expected << " got " << sizeof(name) * 8 << "\033[0m\n"; \
}

#define TEST_VALUE(name, expected) \
total++; \
if (name != expected) { \
    failures++; \
    std::cout << "\t\033[31m[FAILED] Tested value of " << #name << " - expected " << expected << " got " << name << "\033[0m\n"; \
} else { \
    std::cout << "\t\033[32m[SUCCESS] Tested value of " << #name << " - expected " << expected << " got " << name << "\033[0m\n"; \
}

#define TEST_FUNCTION_RETURN(name, args, expected) \
{ \
    total++; \
    auto result = name args; \
    if (result != expected) { \
        failures++; \
        std::cout << "\t\033[31m[FAILED] Tested function return value of " << #name << #args << " - expected " << expected << " got " << result << "\033[0m\n"; \
    } else { \
        std::cout << "\t\033[32m[SUCCESS] Tested function return value of " << #name << #args << " - expected " << expected << " got " << result << "\033[0m\n"; \
    } \
}

#define TEST_FUNCTION_RETURN_CONSTCHARPTR(name, args, expected) \
{ \
    total++; \
    auto result = name args; \
    if (strcmp(result, expected) != 0) { \
        failures++; \
        std::cout << "\t\033[31m[FAILED] Tested function return value of " << #name << #args << " - expected " << expected << " got " << result << "\033[0m\n"; \
    } else { \
        std::cout << "\t\033[32m[SUCCESS] Tested function return value of " << #name << #args << " - expected " << expected << " got " << result << "\033[0m\n"; \
    } \
}

int main(int argc, char* argv[]) {
    int total = 0;
    int failures = 0;
    
    /* Engine_Primitives.h */
    TEST_SIZEOF(Engine_Int8, 8)
    TEST_SIZEOF(Engine_UInt8, 8)
    TEST_SIZEOF(Engine_Int16, 16)
    TEST_SIZEOF(Engine_UInt16, 16)
    TEST_SIZEOF(Engine_Int32, 32)
    TEST_SIZEOF(Engine_UInt32, 32)
    TEST_SIZEOF(Engine_Int64, 64)
    TEST_SIZEOF(Engine_UInt64, 64)
    TEST_SIZEOF(Engine_Float32, 32)
    TEST_SIZEOF(Engine_Float64, 64)
    TEST_SIZEOF(Engine_Float128, 128)
    TEST_SIZEOF(Engine_Bool, 8)
    TEST_SIZEOF(Engine_Char, 8)
    TEST_SIZEOF(Engine_WChar, 16)
    #ifdef ENGINE_BITNESS_64
    TEST_SIZEOF(Engine_Int, 64)
    TEST_SIZEOF(Engine_UInt, 64)
    TEST_SIZEOF(Engine_Float, 64)
    #elifdef ENGINE_BITNESS_32
    TEST_SIZEOF(Engine_Int, 32)
    TEST_SIZEOF(Engine_UInt, 32)
    TEST_SIZEOF(Engine_Float, 32)
    #endif /* ENGINE_BITNESS_64 */

    /* Engine_Result.h */
    TEST_FUNCTION_RETURN(Engine_Result_IsUnknown, (Engine_Result_UNKNOWN), 1)
    TEST_FUNCTION_RETURN(Engine_Result_IsUnknown, (Engine_Result_SUCCESS), 0)
    TEST_FUNCTION_RETURN(Engine_Result_IsSuccess, (Engine_Result_SUCCESS), 1)
    TEST_FUNCTION_RETURN(Engine_Result_IsSuccess, (Engine_Result_UNKNOWN), 0)
    TEST_FUNCTION_RETURN(Engine_Result_IsWarning, (Engine_Result_WARNING_UNKNOWN), 1)
    TEST_FUNCTION_RETURN(Engine_Result_IsWarning, (Engine_Result_SUCCESS), 0)
    TEST_FUNCTION_RETURN(Engine_Result_IsFailure, (Engine_Result_FAILURE_UNKNOWN), 1)
    TEST_FUNCTION_RETURN(Engine_Result_IsFailure, (Engine_Result_SUCCESS), 0)
    TEST_FUNCTION_RETURN(Engine_Result_IsError, (Engine_Result_ERROR_UNKNOWN), 1)
    TEST_FUNCTION_RETURN(Engine_Result_IsError, (Engine_Result_SUCCESS), 0)
    TEST_FUNCTION_RETURN_CONSTCHARPTR(Engine_Result_GetMessage, (Engine_Result_SUCCESS), "Success");

    /* Engine_Math_Vec2.h */
    TEST_SIZEOF(Engine_Math_Int8Vec2, 8 * 2)
    TEST_SIZEOF(Engine_Math_UInt8Vec2, 8 * 2)
    TEST_SIZEOF(Engine_Math_Int16Vec2, 16 * 2)
    TEST_SIZEOF(Engine_Math_UInt16Vec2, 16 * 2)
    TEST_SIZEOF(Engine_Math_Int32Vec2, 32 * 2)
    TEST_SIZEOF(Engine_Math_UInt32Vec2, 32 * 2)
    TEST_SIZEOF(Engine_Math_Int64Vec2, 64 * 2)
    TEST_SIZEOF(Engine_Math_UInt64Vec2, 64 * 2)
    TEST_SIZEOF(Engine_Math_Float32Vec2, 32 * 2)
    TEST_SIZEOF(Engine_Math_Float64Vec2, 64 * 2)
    TEST_SIZEOF(Engine_Math_Float128Vec2, 128 * 2)
    #ifdef ENGINE_BITNESS_64
    TEST_SIZEOF(Engine_Math_IntVec2, 64 * 2)
    TEST_SIZEOF(Engine_Math_UIntVec2, 64 * 2)
    TEST_SIZEOF(Engine_Math_FloatVec2, 64 * 2)
    #elifdef ENGINE_BITNESS_32
    TEST_SIZEOF(Engine_Math_IntVec2, 32 * 2)
    TEST_SIZEOF(Engine_Math_UIntVec2, 32 * 2)
    TEST_SIZEOF(Engine_Math_FloatVec2, 32 * 2)
    #endif /* ENGINE_BITNESS_64 */
    Engine_Math_Int32Vec2 Engine_Math_Int32Vec2_Test_ConstructFromElements;
    Engine_Math_Int32Vec2_ConstructFromElements(&Engine_Math_Int32Vec2_Test_ConstructFromElements, 1, 2);
    TEST_VALUE(Engine_Math_Int32Vec2_Test_ConstructFromElements.x, 1)
    TEST_VALUE(Engine_Math_Int32Vec2_Test_ConstructFromElements.y, 2)
    Engine_Math_Int32Vec2 Engine_Math_Int32Vec2_Test_ConstructFromArray;
    Engine_Int32 Engine_Math_Int32Vec2_Test_ConstructFromArray_array[2];
    Engine_Math_Int32Vec2_Test_ConstructFromArray_array[0] = 1;
    Engine_Math_Int32Vec2_Test_ConstructFromArray_array[1] = 2;
    Engine_Math_Int32Vec2_ConstructFromArray(&Engine_Math_Int32Vec2_Test_ConstructFromArray, &Engine_Math_Int32Vec2_Test_ConstructFromArray_array);
    TEST_VALUE(Engine_Math_Int32Vec2_Test_ConstructFromArray.x, 1)
    TEST_VALUE(Engine_Math_Int32Vec2_Test_ConstructFromArray.y, 2)

    /* Engine_Math_Vec3.h */
    TEST_SIZEOF(Engine_Math_Int8Vec3, 8 * 3)
    TEST_SIZEOF(Engine_Math_UInt8Vec3, 8 * 3)
    TEST_SIZEOF(Engine_Math_Int16Vec3, 16 * 3)
    TEST_SIZEOF(Engine_Math_UInt16Vec3, 16 * 3)
    TEST_SIZEOF(Engine_Math_Int32Vec3, 32 * 3)
    TEST_SIZEOF(Engine_Math_UInt32Vec3, 32 * 3)
    TEST_SIZEOF(Engine_Math_Int64Vec3, 64 * 3)
    TEST_SIZEOF(Engine_Math_UInt64Vec3, 64 * 3)
    TEST_SIZEOF(Engine_Math_Float32Vec3, 32 * 3)
    TEST_SIZEOF(Engine_Math_Float64Vec3, 64 * 3)
    TEST_SIZEOF(Engine_Math_Float128Vec3, 128 * 3)
    #ifdef ENGINE_BITNESS_64
    TEST_SIZEOF(Engine_Math_IntVec3, 64 * 3)
    TEST_SIZEOF(Engine_Math_UIntVec3, 64 * 3)
    TEST_SIZEOF(Engine_Math_FloatVec3, 64 * 3)
    #elifdef ENGINE_BITNESS_32
    TEST_SIZEOF(Engine_Math_IntVec3, 32 * 3)
    TEST_SIZEOF(Engine_Math_UIntVec3, 32 * 3)
    TEST_SIZEOF(Engine_Math_FloatVec3, 32 * 3)
    #endif /* ENGINE_BITNESS_64 */
    Engine_Math_Int32Vec3 Engine_Math_Int32Vec3_Test_ConstructFromElements;
    Engine_Math_Int32Vec3_ConstructFromElements(&Engine_Math_Int32Vec3_Test_ConstructFromElements, 1, 2, 3);
    TEST_VALUE(Engine_Math_Int32Vec3_Test_ConstructFromElements.x, 1)
    TEST_VALUE(Engine_Math_Int32Vec3_Test_ConstructFromElements.y, 2)
    TEST_VALUE(Engine_Math_Int32Vec3_Test_ConstructFromElements.z, 3)
    Engine_Math_Int32Vec3 Engine_Math_Int32Vec3_Test_ConstructFromArray;
    Engine_Int32 Engine_Math_Int32Vec3_Test_ConstructFromArray_array[3];
    Engine_Math_Int32Vec3_Test_ConstructFromArray_array[0] = 1;
    Engine_Math_Int32Vec3_Test_ConstructFromArray_array[1] = 2;
    Engine_Math_Int32Vec3_Test_ConstructFromArray_array[2] = 3;
    Engine_Math_Int32Vec3_ConstructFromArray(&Engine_Math_Int32Vec3_Test_ConstructFromArray, &Engine_Math_Int32Vec3_Test_ConstructFromArray_array);
    TEST_VALUE(Engine_Math_Int32Vec3_Test_ConstructFromArray.x, 1)
    TEST_VALUE(Engine_Math_Int32Vec3_Test_ConstructFromArray.y, 2)
    TEST_VALUE(Engine_Math_Int32Vec3_Test_ConstructFromElements.z, 3)

    /* Engine_Math_Rect2.h */
    TEST_SIZEOF(Engine_Math_Int8Rect2, 8 * 4)
    TEST_SIZEOF(Engine_Math_UInt8Rect2, 8 * 4)
    TEST_SIZEOF(Engine_Math_Int16Rect2, 16 * 4)
    TEST_SIZEOF(Engine_Math_UInt16Rect2, 16 * 4)
    TEST_SIZEOF(Engine_Math_Int32Rect2, 32 * 4)
    TEST_SIZEOF(Engine_Math_UInt32Rect2, 32 * 4)
    TEST_SIZEOF(Engine_Math_Int64Rect2, 64 * 4)
    TEST_SIZEOF(Engine_Math_UInt64Rect2, 64 * 4)
    TEST_SIZEOF(Engine_Math_Float32Rect2, 32 * 4)
    TEST_SIZEOF(Engine_Math_Float64Rect2, 64 * 4)
    TEST_SIZEOF(Engine_Math_Float128Rect2, 128 * 4)
    #ifdef ENGINE_BITNESS_64
    TEST_SIZEOF(Engine_Math_IntRect2, 64 * 4)
    TEST_SIZEOF(Engine_Math_UIntRect2, 64 * 4)
    TEST_SIZEOF(Engine_Math_FloatRect2, 64 * 4)
    #elifdef ENGINE_BITNESS_32
    TEST_SIZEOF(Engine_Math_IntRect2, 32 * 4)
    TEST_SIZEOF(Engine_Math_UIntRect2, 32 * 4)
    TEST_SIZEOF(Engine_Math_FloatRect2, 32 * 4)
    #endif /* ENGINE_BITNESS_64 */
    Engine_Math_Int32Rect2 Engine_Math_Int32Rect2_Test_ConstructFromElements;
    Engine_Math_Int32Rect2_ConstructFromElements(&Engine_Math_Int32Rect2_Test_ConstructFromElements, 1, 2, 3, 4);
    TEST_VALUE(Engine_Math_Int32Rect2_Test_ConstructFromElements.x, 1)
    TEST_VALUE(Engine_Math_Int32Rect2_Test_ConstructFromElements.y, 2)
    TEST_VALUE(Engine_Math_Int32Rect2_Test_ConstructFromElements.w, 3)
    TEST_VALUE(Engine_Math_Int32Rect2_Test_ConstructFromElements.h, 4)
    Engine_Math_Int32Rect2 Engine_Math_Int32Rect2_Test_ConstructFromVectors;
    Engine_Math_Int32Vec2 Engine_Math_Int32Rect2_Test_ConstructFromVectors_xy;
    Engine_Math_Int32Rect2_Test_ConstructFromVectors_xy.x = 1; Engine_Math_Int32Rect2_Test_ConstructFromVectors_xy.y = 2;
    Engine_Math_Int32Vec2 Engine_Math_Int32Rect2_Test_ConstructFromVectors_wh;
    Engine_Math_Int32Rect2_Test_ConstructFromVectors_wh.x = 3; Engine_Math_Int32Rect2_Test_ConstructFromVectors_wh.y = 4;
    Engine_Math_Int32Rect2_ConstructFromVectors(&Engine_Math_Int32Rect2_Test_ConstructFromVectors, Engine_Math_Int32Rect2_Test_ConstructFromVectors_xy, Engine_Math_Int32Rect2_Test_ConstructFromVectors_wh);
    TEST_VALUE(Engine_Math_Int32Rect2_Test_ConstructFromVectors.x, 1)
    TEST_VALUE(Engine_Math_Int32Rect2_Test_ConstructFromVectors.y, 2)
    TEST_VALUE(Engine_Math_Int32Rect2_Test_ConstructFromVectors.w, 3)
    TEST_VALUE(Engine_Math_Int32Rect2_Test_ConstructFromVectors.h, 4)
    Engine_Math_Int32Rect2 Engine_Math_Int32Rect2_Test_ConstructFromArray;
    Engine_Int32 Engine_Math_Int32Rect2_Test_ConstructFromArray_array[4];
    Engine_Math_Int32Rect2_Test_ConstructFromArray_array[0] = 1;
    Engine_Math_Int32Rect2_Test_ConstructFromArray_array[1] = 2;
    Engine_Math_Int32Rect2_Test_ConstructFromArray_array[2] = 3;
    Engine_Math_Int32Rect2_Test_ConstructFromArray_array[3] = 4;
    Engine_Math_Int32Rect2_ConstructFromArray(&Engine_Math_Int32Rect2_Test_ConstructFromArray, &Engine_Math_Int32Rect2_Test_ConstructFromArray_array);
    TEST_VALUE(Engine_Math_Int32Rect2_Test_ConstructFromArray.x, 1)
    TEST_VALUE(Engine_Math_Int32Rect2_Test_ConstructFromArray.y, 2)
    TEST_VALUE(Engine_Math_Int32Rect2_Test_ConstructFromArray.w, 3)
    TEST_VALUE(Engine_Math_Int32Rect2_Test_ConstructFromArray.h, 4)

    /* Engine_Math_Rect3.h */
    TEST_SIZEOF(Engine_Math_Int8Rect3, 8 * 6)
    TEST_SIZEOF(Engine_Math_UInt8Rect3, 8 * 6)
    TEST_SIZEOF(Engine_Math_Int16Rect3, 16 * 6)
    TEST_SIZEOF(Engine_Math_UInt16Rect3, 16 * 6)
    TEST_SIZEOF(Engine_Math_Int32Rect3, 32 * 6)
    TEST_SIZEOF(Engine_Math_UInt32Rect3, 32 * 6)
    TEST_SIZEOF(Engine_Math_Int64Rect3, 64 * 6)
    TEST_SIZEOF(Engine_Math_UInt64Rect3, 64 * 6)
    TEST_SIZEOF(Engine_Math_Float32Rect3, 32 * 6)
    TEST_SIZEOF(Engine_Math_Float64Rect3, 64 * 6)
    TEST_SIZEOF(Engine_Math_Float128Rect3, 128 * 6)
    #ifdef ENGINE_BITNESS_64
    TEST_SIZEOF(Engine_Math_IntRect3, 64 * 6)
    TEST_SIZEOF(Engine_Math_UIntRect3, 64 * 6)
    TEST_SIZEOF(Engine_Math_FloatRect3, 64 * 6)
    #elifdef ENGINE_BITNESS_32
    TEST_SIZEOF(Engine_Math_IntRect3, 32 * 6)
    TEST_SIZEOF(Engine_Math_UIntRect3, 32 * 6)
    TEST_SIZEOF(Engine_Math_FloatRect3, 32 * 6)
    #endif /* ENGINE_BITNESS_64 */
    Engine_Math_Int32Rect3 Engine_Math_Int32Rect3_Test_ConstructFromElements;
    Engine_Math_Int32Rect3_ConstructFromElements(&Engine_Math_Int32Rect3_Test_ConstructFromElements, 1, 2, 3, 4, 5, 6);
    TEST_VALUE(Engine_Math_Int32Rect3_Test_ConstructFromElements.x, 1)
    TEST_VALUE(Engine_Math_Int32Rect3_Test_ConstructFromElements.y, 2)
    TEST_VALUE(Engine_Math_Int32Rect3_Test_ConstructFromElements.z, 3)
    TEST_VALUE(Engine_Math_Int32Rect3_Test_ConstructFromElements.w, 4)
    TEST_VALUE(Engine_Math_Int32Rect3_Test_ConstructFromElements.h, 5)
    TEST_VALUE(Engine_Math_Int32Rect3_Test_ConstructFromElements.d, 6)
    Engine_Math_Int32Rect3 Engine_Math_Int32Rect3_Test_ConstructFromVectors;
    Engine_Math_Int32Vec3 Engine_Math_Int32Rect3_Test_ConstructFromVectors_xyz;
    Engine_Math_Int32Rect3_Test_ConstructFromVectors_xyz.x = 1; Engine_Math_Int32Rect3_Test_ConstructFromVectors_xyz.y = 2; Engine_Math_Int32Rect3_Test_ConstructFromVectors_xyz.z = 3;
    Engine_Math_Int32Vec3 Engine_Math_Int32Rect3_Test_ConstructFromVectors_whd;
    Engine_Math_Int32Rect3_Test_ConstructFromVectors_whd.x = 4; Engine_Math_Int32Rect3_Test_ConstructFromVectors_whd.y = 5; Engine_Math_Int32Rect3_Test_ConstructFromVectors_whd.z = 6;
    Engine_Math_Int32Rect3_ConstructFromVectors(&Engine_Math_Int32Rect3_Test_ConstructFromVectors, Engine_Math_Int32Rect3_Test_ConstructFromVectors_xyz, Engine_Math_Int32Rect3_Test_ConstructFromVectors_whd);
    TEST_VALUE(Engine_Math_Int32Rect3_Test_ConstructFromVectors.x, 1)
    TEST_VALUE(Engine_Math_Int32Rect3_Test_ConstructFromVectors.y, 2)
    TEST_VALUE(Engine_Math_Int32Rect3_Test_ConstructFromVectors.z, 3)
    TEST_VALUE(Engine_Math_Int32Rect3_Test_ConstructFromVectors.w, 4)
    TEST_VALUE(Engine_Math_Int32Rect3_Test_ConstructFromVectors.h, 5)
    TEST_VALUE(Engine_Math_Int32Rect3_Test_ConstructFromVectors.d, 6)
    Engine_Math_Int32Rect3 Engine_Math_Int32Rect3_Test_ConstructFromArray;
    Engine_Int32 Engine_Math_Int32Rect3_Test_ConstructFromArray_array[6];
    Engine_Math_Int32Rect3_Test_ConstructFromArray_array[0] = 1;
    Engine_Math_Int32Rect3_Test_ConstructFromArray_array[1] = 2;
    Engine_Math_Int32Rect3_Test_ConstructFromArray_array[2] = 3;
    Engine_Math_Int32Rect3_Test_ConstructFromArray_array[3] = 4;
    Engine_Math_Int32Rect3_Test_ConstructFromArray_array[4] = 5;
    Engine_Math_Int32Rect3_Test_ConstructFromArray_array[5] = 6;
    Engine_Math_Int32Rect3_ConstructFromArray(&Engine_Math_Int32Rect3_Test_ConstructFromArray, &Engine_Math_Int32Rect3_Test_ConstructFromArray_array);
    TEST_VALUE(Engine_Math_Int32Rect3_Test_ConstructFromArray.x, 1)
    TEST_VALUE(Engine_Math_Int32Rect3_Test_ConstructFromArray.y, 2)
    TEST_VALUE(Engine_Math_Int32Rect3_Test_ConstructFromArray.z, 3)
    TEST_VALUE(Engine_Math_Int32Rect3_Test_ConstructFromArray.w, 4)
    TEST_VALUE(Engine_Math_Int32Rect3_Test_ConstructFromArray.h, 5)
    TEST_VALUE(Engine_Math_Int32Rect3_Test_ConstructFromArray.d, 6)

    if (total - failures < total) {
        std::cout << "\t\033[31m[FINISHED] Failed " << failures << " tests out of " << total << " tests\033[0m\n";
    } else {
        std::cout << "\t\033[32m[FINISHED] Failed " << failures << " tests out of " << total << " tests\033[0m\n";
    }
    
    return (int)(total - failures < total);
}