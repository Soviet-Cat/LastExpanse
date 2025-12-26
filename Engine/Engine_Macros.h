/* This file is apart of LastExpanse. */
/* Copyright (c) 2025 Soviet-Cat */
/* See LICENSE.md for license details. */

/* Undefine useless symbols that clash */
#undef interface

#ifndef __ENGINE_MACROS_H__
#define __ENGINE_MACROS_H__

/* ENGINE_SYSTEM_WINDOWS */
#ifdef _WIN32
#define ENGINE_SYSTEM_WINDOWS

/* ENGINE_DECL */
#ifdef ENGINE_EXPORT
#define ENGINE_DECL __declspec(dllexport)
#else
#define ENGINE_DECL __declspec(dllimport)
#endif /* ENGINE_EXPORT */

#endif /* _WIN32 */

/* ENGINE_COMPILER_GNU */
#ifdef __GNUC__
#define ENGINE_COMPILER_GNU

/* ENGINE_BITNESS */
#if __SIZEOF_POINTER__ == 8
#define ENGINE_BITNESS_64
#elif __SIZEOF_POINTER__ == 4
#define ENGINE_BITNESS_32
#else
#define ENGINE_BITNESS_UNKNOWN
#endif /* __SIZEOF_POINTER__ == 8 */

/* ENGINE_INLINE */
#define ENGINE_INLINE __attribute__((always_inline)) inline

#endif /* __GNUC__ */

/* ENGINE_COMPILER_MSVC */
#ifdef _MSC_VER
#define ENGINE_COMPILER_MSVC

/* ENGINE_BITNESS */
#ifdef _WIN64
#define ENGINE_BITNESS 64
#elifdef _WIN32
#define ENGINE_BITNESS 32
#else
#define ENGINE_BITNESS_UNKNOWN
#endif /* _WIN64 */

/* ENGINE_INLINE */
#define ENGINE_INLINE __forceinline

#endif /* _MSC_VER */

/* ENGINE_COMPILER_UNKNOWN */
#if !defined(ENGINE_COMPILER_GNU) && !defined(ENGINE_COMPILER_MSVC)
#define ENGINE_COMPILER_UNKNOWN

#define ENGINE_BITNESS_UNKNOWN

/* ENGINE_INLINE */
#define ENGINE_INLINE inline

#endif /* !ENGINE_COMPILER_GNU && !ENGINE_COMPILER_MSVC */

#endif /* __ENGINE_MACROS_H__ */