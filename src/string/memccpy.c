#include <string.h>

void *memccpy(void *destptr, const void *srcptr, int c, size_t n)
{
    unsigned char *dst       = destptr;
    const unsigned char *src = srcptr;

    for (size_t i = 0; i < n; ++i) {
        dst[i] = src[i];

        if (dst[i] == c)
            return destptr + i + 1;
    }
    return NULL;
}
