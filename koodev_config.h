#ifndef __KOODEV_CONFIG_H__
#define __KOODEV_CONFIG_H__

/*
 * Uncomment this line for using Android's LOG
 */
// #define KOODEV_PLATFORM_ANDROID

/*
 * Uncomment this line when using with WebKit
 */
// #define KOODEV_NAMESPACE WebKit

// FIXME: Windows build currently not supported.
/* // Check windows */
/* #if _WIN32 || _WIN64 */
/* #if _WIN64 */
/* #define KOODEV_ENV_64 */
/* #else */
/* #define KOODEV_ENV_32 */
/* #endif // _WIN64 */
/* #endif // _WIN64 || _WIN32 */

// Check GCC
// FIXME: Add other architectures(ex: MIPS, IA, ...)
#if __GNUC__
#if __x86_64__ || __ppc64__
#define KOODEV_ENV_64
#else
#define KOODEV_ENV_32
#endif // __x86_64__ || __ppc64__
#endif // __GNUC__

#ifdef KOODEV_PLATFORM_ANDROID
#include <android/log.h>
#define KOODEV_LOGTAG "koodev"
#define KOODEV_PRINT(args...)  __android_log_print(ANDROID_LOG_INFO, KOODEV_LOGTAG , ## args)
#else
#define KOODEV_PRINT(fmt, ...) printf(fmt, __VA_ARGS__)
#endif // KOODEV_PLATFORM_ANDROID

#endif // __KOODEV_CONFIG_H__
