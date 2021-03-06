#include <string.h>

char *strncat(char *dest, const char *src, size_t n)
{
    size_t dest_len = strlen(dest);
    size_t i;

    for (i = 0; src[i] && i < n; ++i)
        dest[dest_len + i] = src[i];

    dest[dest_len + i] = '\0';
    return dest;
}
