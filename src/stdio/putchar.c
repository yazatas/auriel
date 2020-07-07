#include <stdio.h>
#include <unistd.h>

int putchar(int c)
{
    unsigned char uc = c;
    write(stdout, &uc, 1);
    return uc;
}
