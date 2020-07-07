#include <string.h>

char *strrchr(const char *s, int c)
{
    size_t len = strlen(s);

    for (int i = len; i >= 0; --i) {
        if (s[i] == c)
            return (char *)&s[i];
    }
    return NULL;
}
