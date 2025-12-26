/* This file is apart of LastExpanse. */
/* Copyright (c) 2025 Soviet-Cat */
/* See LICENSE.md for license details. */

#ifndef __ENGINE_RESULT_H__
#define __ENGINE_RESULT_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "Engine_Macros.h"
#include "Engine_Primitives.h"

typedef enum : Engine_UInt32 {
    Engine_Result_SUCCESS,
    Engine_Result_UNKNOWN,
    /* Warnings */
    Engine_Result_WARNING___FIRST__, /* Redundant, DO NOT USE */
    Engine_Result_WARNING_UNKNOWN,
    Engine_Result_WARNING___LAST__, /* Redundant, DO NOT USE */
    /* Failures */
    Engine_Result_FAILURE___FIRST__, /* Redundant, DO NOT USE */
    Engine_Result_FAILURE_UNKNOWN,
    Engine_Result_FAILURE_MEMORY_ALLOC,
    Engine_Result_FAILURE___LAST__, /* Redundant, DO NOT USE */
    /* Errors */
    Engine_Result_ERROR___FIRST__, /* Redundant, DO NOT USE */
    Engine_Result_ERROR_UNKNOWN,
    Engine_Result_ERROR___LAST__ /* Redundant, DO NOT USE */
} Engine_Result;

ENGINE_INLINE Engine_Bool Engine_Result_IsUnknown(Engine_Result result);
ENGINE_INLINE Engine_Bool Engine_Result_IsSuccess(Engine_Result result);
ENGINE_INLINE Engine_Bool Engine_Result_IsWarning(Engine_Result result);
ENGINE_INLINE Engine_Bool Engine_Result_IsFailure(Engine_Result result);
ENGINE_INLINE Engine_Bool Engine_Result_IsError(Engine_Result result);

ENGINE_DECL const Engine_Char* Engine_Result_GetMessage(Engine_Result result);

#ifdef __cplusplus
} /* extern "C" */
#endif

#include "Engine_Result.inl"

#endif /* __ENGINE_RESULT_H__ */