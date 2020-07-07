#include <string.h>

char *strtok(char *str, const char *delim)
{ 
    static char *sp = NULL; 
    size_t i = 0;
    size_t len = strlen(delim);

    if (!str && !sp)
        return NULL;

    if (str && !sp)
        sp = str;

    char *p_start = sp;
    for (;;) {
        for (i = 0; i < len; i++) {
            if (*p_start == delim[i]) {
                p_start++;
                break;
            }
        }

        if (i == len) {
            sp = p_start;
            break;
        }
    }

    if (!*sp) {
        sp = NULL;
        return sp;
    }

    while (*sp) {
        for (i = 0; i < len; i ++) {
            if (*sp == delim[i]) {
                *sp = '\0';
                break;
            }
        }

        sp++;
        if (i < len)
            break;
    }
    return p_start;
}
