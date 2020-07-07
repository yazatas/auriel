#include <string.h>

char *strpbrk(const char *s, const char *accept)
{
    size_t s_len = strlen(s);
    size_t a_len = strlen(accept);

    for (size_t i = 0; i < s_len; ++i) {
        for (size_t j = 0; j < a_len; ++j) {
            if (s[i] == accept[j])
                return (char *)s + i;
        }
    }

    return NULL;
}
