#include <stdio.h>
#include "KoodevStopwatch.h"

#include <unistd.h>

void foo()
{
    KoodevStopwatch w("foo");
    sleep(2);
}

void bar()
{
    KoodevStopwatch w("bar");
    for (int i=0; i<10000; i++) {
        KoodevStopwatch w;
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
