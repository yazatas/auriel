#include <string.h>

void *memchr(const void *s, int c, size_t n)
{
    const unsigned char *ptr = s;

    for (size_t i = 0; i < n; ++i) {
        if (ptr[i] == (unsigned char)c)
            return (void *)ptr + i;
    }
    return NULL;
}
