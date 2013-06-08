#include <stdio.h>
#include "KoodevStopwatch.h"

#include <windows.h>

void foo()
{
    KoodevStopwatch w("foo");
    Sleep(2000);
}

void bar()
{
    KoodevStopwatch w("bar");
    for (int i=0; i<10000; i++) {
        KoodevStopwatch w;
        w.setIgonreZeroDump(true);
    }
}

int main()
{
    KoodevStopwatch w;
    foo();
    bar();
    printf("Hello, world!\n");
    return 0;
}
