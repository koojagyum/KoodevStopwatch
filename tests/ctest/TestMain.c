#include <stdio.h>
#include "koodev-sw-interface.h"

#include <unistd.h>

void foo()
{
    koodev_sw_handle sw = koodev_sw_new();
    koodev_sw_set(sw, KOODEV_SW_SET_TITLEMSG, (void*)"foo");
    koodev_sw_start(sw);

    sleep(2);

    koodev_sw_release(sw);
}

void bar()
{
    int i;
    koodev_sw_handle sw1 = koodev_sw_new();
    koodev_sw_handle sw2 = koodev_sw_new();
    koodev_sw_set(sw1, KOODEV_SW_SET_TITLEMSG, (void*)"bar");
    koodev_sw_set(sw2, KOODEV_SW_SET_IGNOREZERODUMP, 1);
    koodev_sw_set(sw2, KOODEV_SW_SET_DUMPONDESTROY, 1);

    koodev_sw_start(sw1);

    for (i=0; i<10000; i++) {
        koodev_sw_start(sw2);
        koodev_sw_stop(sw2, 1);
    }

    koodev_sw_release(sw1);
    koodev_sw_release(sw2);
}

int main()
{
    koodev_sw_handle sw = koodev_sw_new();
    koodev_sw_start(sw);
    foo();
    bar();
    printf("Hello, world!\n");
    koodev_sw_release(sw);
    return 0;
}
