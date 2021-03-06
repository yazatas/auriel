#include <limits.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

static void print_integer(unsigned int value, int width, int sign, bool zp)
{
    char c[64] = {0};
    int i = 0, nlen;

    do { 
        c[i++] = (value % 10) + '0';
        value /= 10;
    } while (value != 0);
    nlen = i;

    while (i < width && width)
        c[i++] = zp ? '0' : ' ';

    if (sign == -1)
        c[zp ? i - 1 : nlen] = '-';

    while (--i >= 0)
        putchar(c[i]);
}

int printf(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    int width = 0, zero_padding = 0;

    while (*fmt) {

        if (*fmt != '%') {
            putchar(*fmt);
            fmt++;
            continue;
        }
        
        fmt++;
        switch (*fmt) {
            case '%':
                putchar('%');
                fmt++;
                continue;

            case 'c':
                putchar(va_arg(args, int));
                fmt++;
                continue;

            case 's': {
                char *tmp = va_arg(args, char*);
                puts(tmp);
                fmt++;
                continue;
            }

        }

        if (*fmt == '0') {
            zero_padding = 1;
            fmt++;
        }

        /* get padding width */
        while ((*fmt >= '0') && (*fmt <= '9')) {
            width = width * 10 + (*fmt - '0');
            fmt++;
        }

        switch (*fmt) {
            case 'd': {
                int tmp = va_arg(args, int);
                print_integer((tmp < 0) ? -tmp : tmp, width, -(tmp < 0), zero_padding);
                break;
            }

            case 'u': {
                unsigned int tmp = va_arg(args, unsigned int);
                print_integer(tmp, width, 0, zero_padding);
                break;
            }

            case 'x': {
                const unsigned char sym[16] =
                    {'0', '1', '2', '3',
                     '4', '5', '6', '7',
                     '8', '9', 'a', 'b',
                     'c', 'd', 'e', 'f'};
                unsigned int tmp = va_arg(args, unsigned int);
                static char c[64];
                int i = tmp ? 0 : 1;

                while (tmp != 0) {
                    c[i++] = sym[tmp & 0xf];
                    tmp >>= 4;
                }

                while (i < width && width)
                    c[i++] = zero_padding ? '0' : ' ';

                while (--i >= 0)
                    putchar(c[i]);

                break;
            }
        }

        width = zero_padding = 0;
        fmt++;
    }

    va_end(args);
    return 0; /* FIXME:  */
}
