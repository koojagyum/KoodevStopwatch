#include "koodev-sw-interface.h"
#include "KoodevStopwatch.h"

extern "C"
{

koodev_sw_handle
koodev_sw_new()
{
    return reinterpret_cast<koodev_sw_handle>
        (new KoodevStopwatch(NULL, false, false, true, false));
}

void
koodev_sw_start(koodev_sw_handle handle)
{
    KoodevStopwatch* w =
        reinterpret_cast<KoodevStopwatch*>(handle);
    w->start();
}

void
koodev_sw_stop(koodev_sw_handle handle, unsigned int and_dump)
{
    KoodevStopwatch* w =
        reinterpret_cast<KoodevStopwatch*>(handle);
    w->stop(and_dump);
}

void
koodev_sw_lab(koodev_sw_handle handle, const char* msg)
{
    KoodevStopwatch* w =
        reinterpret_cast<KoodevStopwatch*>(handle);
    w->lab(msg);
}

void
koodev_sw_set(koodev_sw_handle handle, unsigned int key, void* value)
{
    KoodevStopwatch* w =
        reinterpret_cast<KoodevStopwatch*>(handle);

    switch (key) {
    case KOODEV_SW_SET_IGNOREZERODUMP:
        w->setIgonreZeroDump(value);
        break;
    case KOODEV_SW_SET_TITLEMSG:
        w->setMessage((const char*)value);
        break;
    case KOODEV_SW_SET_DUMPONDESTROY:
        w->setDumpOnDestroy(value);
        break;
    default:
        break;
    }
}

void
koodev_sw_release(koodev_sw_handle handle)
{
    KoodevStopwatch* w =
        reinterpret_cast<KoodevStopwatch*>(handle);
    delete w;
}

}
