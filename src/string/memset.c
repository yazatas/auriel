#include <string.h>

void *memset(void *buf, int c, size_t size)
{
    unsigned char *ptr = buf;
    while (size--)
        *ptr++ = c;
    return buf;
}
