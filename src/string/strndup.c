#include <string.h>
#include <stdlib.h>

char *strndup(const char *s, size_t n)
{
    char *new;

    if (!(new = malloc(n + 1)))
        return NULL; /* TODO: set errno */

    for (size_t i = 0; i < n; ++i)
        new[i] = s[i];

    new[n] = '\0';
    return new;
}
