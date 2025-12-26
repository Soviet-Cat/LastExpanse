/* This file is apart of LastExpanse. */
/* Copyright (c) 2025 Soviet-Cat */
/* See LICENSE.md for license details. */

#ifndef __ENGINE_RESULT_INL__
#define __ENGINE_RESULT_INL__

#include "Engine_Result.h"

#ifdef __cplusplus
extern "C" {
#endif

ENGINE_INLINE Engine_Bool Engine_Result_IsUnknown(Engine_Result result) {
    return result == Engine_Result_UNKNOWN;
}
ENGINE_INLINE Engine_Bool Engine_Result_IsSuccess(Engine_Result result) {
    return result == Engine_Result_SUCCESS;
}
ENGINE_INLINE Engine_Bool Engine_Result_IsWarning(Engine_Result result) {
    return result > Engine_Result_WARNING___FIRST__ && result < Engine_Result_WARNING___LAST__;
}
ENGINE_INLINE Engine_Bool Engine_Result_IsFailure(Engine_Result result) {
    return result > Engine_Result_FAILURE___FIRST__ && result < Engine_Result_FAILURE___LAST__;
}
ENGINE_INLINE Engine_Bool Engine_Result_IsError(Engine_Result result) {
    return result > Engine_Result_ERROR___FIRST__ && result < Engine_Result_ERROR___LAST__;
}

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __ENGINE_RESULT_INL__ */