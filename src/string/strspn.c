#include <string.h>
#include <stdbool.h>

size_t strspn(const char *s, const char *accept)
{
    size_t i;
    size_t s_len = strlen(s);
    size_t a_len = strlen(accept);
    bool found   = false;

    for (i = 0; i < s_len; ++i) {
        for (size_t j = 0; j < a_len; ++j) {
            if (s[i] == accept[j]) {
                found = true;
                break;
            }
        }
        if (!found)
            return i;
        found = false;
    }
    return i;
}
