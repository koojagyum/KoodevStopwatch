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

#ifdef KOODEV_PLATFORM_ANDROID
#include <android/log.h>
#define KOODEV_LOGTAG "koodev"
#define KOODEV_PRINT(args...)  __android_log_print(ANDROID_LOG_INFO, KOODEV_LOGTAG , ## args)
#else
#define KOODEV_PRINT(fmt, ...) printf(fmt, __VA_ARGS__)
#endif // KOODEV_PLATFORM_ANDROID

#endif // __KOODEV_CONFIG_H__
