/* This file is apart of LastExpanse. */
/* Copyright (c) 2025 Soviet-Cat */
/* See LICENSE.md for license details. */

#include "Engine_Memory_Raw.h"

#include <stdlib.h> /* TODO: Replace and stop using stdlib.h */

Engine_Void Engine_Memory_RawAlloc(Engine_Void** dest, Engine_UInt size) {
    *dest = Engine_NullPtr;
    *dest = malloc(size);
}
Engine_Void Engine_Memory_RawFree(Engine_Void** dest) {
    free(*dest);
    *dest = Engine_NullPtr;
}