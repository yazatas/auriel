#include <string.h>

int strcmp(const char *s1, const char *s2)
{
    for (size_t i = 0; s1[i] || s2[i]; ++i) {
        if (s1[i] < s2[i])
            return -1;
        else if (s1[i] > s2[i])
            return 1;
    }

    return 0;
}
