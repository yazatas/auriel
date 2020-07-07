#include <stdio.h>
#include <stdlib.h>

void abort(void)
{
    printf("abort()\n");
    while (1) { }
    __builtin_unreachable();
}
