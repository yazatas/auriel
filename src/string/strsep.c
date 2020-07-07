#include <string.h>
#include <stdbool.h>

/* similar to freebsd's strsep implementation but this skips 
 * all delim characters from the beginning */

static bool char_in_delim(char c, const char *delim)
{
    while (*delim) {
        if (*delim++ == c)
            return true;
    }
    return false;
}

static char *find_first_non_delim(const char *str, const char *delim)
{
    while (char_in_delim(*str, delim))
        str++;
    return (char *)str;
}

char *strsep(char **str, const char *delim)
{
    char *s, *tok, *c;

    if (!*str)
        return NULL;

    s = tok = find_first_non_delim(*str, delim);
    
    while (*s) {
        c = (char *)delim;

        while (*c) {
            if (*s == *c) {
                *s = '\0';
                *str = s + 1;
                return tok;
            }
            c++;
        }
        s++;
    }

    *str = NULL;
    return tok;
}
