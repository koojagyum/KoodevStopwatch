#ifndef __KOODEV_SW_INTERFACE_H__
#define __KOODEV_SW_INTERFACE_H__

typedef void* koodev_sw_handle;

#define KOODEV_SW_SET_IGNOREZERODUMP 1 /* default false */
#define KOODEV_SW_SET_TITLEMSG 2
#define KOODEV_SW_SET_DUMPONDESTROY 3 /* default true */

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

koodev_sw_handle
koodev_sw_new();

void
koodev_sw_start(koodev_sw_handle handle);

void
koodev_sw_stop(koodev_sw_handle handle, unsigned int and_dump);

void
koodev_sw_lab(koodev_sw_handle handle, const char* msg);

void
koodev_sw_set(koodev_sw_handle handle, unsigned int key, void* value);

void
koodev_sw_release(koodev_sw_handle handle);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __KOODEV_SW_INTERFACE_H__
