#include <string.h>

char *stpcpy(char *dest, const char *src)
{
    size_t i = 0;

    while (src[i])
        dest[i] = src[i++];

    dest[i] = '\0';
    return dest + i;
}
