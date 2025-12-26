/* This file is apart of LastExpanse. */
/* Copyright (c) 2025 Soviet-Cat */
/* See LICENSE.md for license details. */

#include "Engine_Result.h"

const Engine_Char* Engine_Result_GetMessage(Engine_Result result) {
    switch (result) {
        case Engine_Result_SUCCESS:
            return "Success";
        case Engine_Result_UNKNOWN:
            return "Unknown";
        case Engine_Result_WARNING___FIRST__:
            return "Means nothing, developer mistake";
        case Engine_Result_WARNING_UNKNOWN:
            return "Unknown warning";
        case Engine_Result_WARNING___LAST__:
            return "Means nothing, developer mistake";
        case Engine_Result_FAILURE___FIRST__:
            return "Means nothing, developer mistake";
        case Engine_Result_FAILURE_UNKNOWN:
            return "Unknown failure";
        case Engine_Result_FAILURE___LAST__:
            return "Means nothing, developer mistake";
        case Engine_Result_ERROR___FIRST__:
            return "Means nothing, developer mistake";
        case Engine_Result_ERROR_UNKNOWN:
            return "Unknown error.";
        case Engine_Result_ERROR___LAST__:
            return "Means nothing, developer mistake";
        default:
            return "Invalid result";
    }
}