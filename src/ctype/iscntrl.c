#include <ctype.h>

int iscntrl(int c)
{
    if (c == 0x09 || c == 0x20)
        return 1;
    return 0;
}
