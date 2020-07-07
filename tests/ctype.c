#include <ctype.h>
#include <string.h>
#include "util.h"

test(isalpha)
{
    int ret;

    ret = isalpha(0);
    ok(!ret, "got %d, expected non-zero\n", ret);

    ret = isalpha('!');
    ok(!ret, "got %d, expected zero\n", ret);

    ret = isalpha('a');
    ok(ret, "got %d, expected non-zero\n", ret);
}

test(isalnum)
{
    int ret;

    ret = isalnum(0);
    ok(!ret, "got %d, expected 0\n", ret);

    ret = isalnum(0xa);
    ok(!ret, "got %d, expected 0\n", ret);

    ret = isalnum('0');
    ok(ret, "got %d, expected 0\n", ret);

    ret = isalnum('a');
    ok(ret, "got %d, expected 0\n", ret);

    ret = isalnum('A');
    ok(ret, "got %d, expected 0\n", ret);
}

test(isblank)
{
    int ret;
    const char *valid = "\t \0";

    for (size_t i = 0; i < strlen(valid); ++i)
        ok(isblank(valid[i]), "got zero on iteration %zu, expected zero\n", i);

    ret = !isblank('a');
    ok(ret, "got %d, expected zero\n", ret);
}

test(iscntrl)
{
    for (int i = 0; i <= 0xff; ++i) {
        if (i == 0x09 || i == 0x20)
            ok(isblank(i), "got zero, expected non-zero for 0x%x\n", i);
        else
            ok(!isblank(i), "got non-zero, expected zero for 0x%x\n", i);
    }
}

test(isdigit)
{
    for (int i = 0; i <= 0xff; ++i) {
        if (i >= '0' && i <= '9')
            ok(isdigit(i), "got zero, expected non-zero for %c\n", i);
        else
            ok(!isdigit(i), "got non-zero, expected zero for 0x%x\n", i);
    }
}

test(isgraph)
{
    for (int i = 0; i <= 0xff; ++i) {
        if (i >= 0x21 && i <= 0x7e)
            ok(isgraph(i), "got zero, expected non-zero for %d\n", i);
        else
            ok(!isgraph(i), "got non-zero, expected zero for %d\n", i);
    }
}

test(islower)
{
    for (int i = 0; i <= 0xff; ++i) {
        if (i >= 'a' && i <= 'z')
            ok(islower(i), "got zero, expected non-zero for %c\n", i);
        else
            ok(!islower(i), "got non-zero, expected zero for %c\n", i);
    }
}

test(isprint)
{
    for (int i = 0; i <= 0xff; ++i) {
        if (i >= 0x20 && i <= 0x7e)
            ok(isprint(i), "got zero, expected non-zero for %x\n", i);
        else
            ok(!isprint(i), "got non-zero, expected zero for %x\n", i);
    }
}

test(ispunct)
{
    for (int i = 0; i <= 0xff; ++i) {
        if (i >= 0x21 && i <= 0x2f)
            ok(ispunct(i), "got zero, expected non-zero for %x\n", i);
        else if (i >= 0x3a && i <= 0x40)
            ok(ispunct(i), "got zero, expected non-zero for %x\n", i);
        else if (i >= 0x5b && i <= 0x60)
            ok(ispunct(i), "got zero, expected non-zero for %x\n", i);
        else if (i >= 0x7b && i <= 0x7e)
            ok(ispunct(i), "got zero, expected non-zero for %x\n", i);
        else
            ok(!ispunct(i), "got non-zero, expected zero for %x\n", i);
    }
}

test(isspace)
{
    for (int i = 0; i <= 0xff; ++i) {
        if ((i >= 0x09 && i <= 0x0d) || i == 0x20)
            ok(isspace(i), "got zero, expected non-zero for %x\n", i);
        else
            ok(!isspace(i), "got zero, expected non-zero for %x\n", i);
    }
}

test(isupper)
{
    for (int i = 0; i <= 0xff; ++i) {
        if (i >= 'A' && i <= 'Z')
            ok(isupper(i), "got zero, expected non-zero for %c\n", i);
        else
            ok(!isupper(i), "got zero, expected non-zero for %c\n", i);
    }
}

test(isxdigit)
{
    for (int i = 0; i <= 0xff; ++i) {
        if (isdigit(i) || (i >= 'a' && i <= 'f') || (i >= 'A' && i <= 'F'))
            ok(isxdigit(i), "got zero, expected non-zero for %c\n", i);
        else
            ok(!isxdigit(i), "got zero, expected non-zero for %c\n", i);
    }
}

test(tolower)
{
    int ret;

    ret = tolower('a');
    ok(ret == 'a', "got %c, expected a\n", ret);

    ret = tolower('A');
    ok(ret == 'a', "got %c, expected a\n", ret);

    ret = tolower('Z');
    ok(ret == 'z', "got %c, expected z\n", ret);

    ret = tolower('0');
    ok(ret == '0', "got %c, expected 0\n", ret);
}

test(toupper)
{
    int ret;

    ret = toupper('a');
    ok(ret == 'A', "got %c, expected A\n", ret);

    ret = toupper('A');
    ok(ret == 'A', "got %c, expected A\n", ret);

    ret = toupper('z');
    ok(ret == 'Z', "got %c, expected Z\n", ret);

    ret = toupper('0');
    ok(ret == '0', "got %c, expected 0\n", ret);
}

int main(void)
{
    test_init();

    add_test(isalpha);
    add_test(isalnum);
    add_test(isblank);
    add_test(iscntrl);
    add_test(isdigit);
    add_test(isgraph);
    add_test(islower);
    add_test(isprint);
    add_test(ispunct);
    add_test(isspace);
    add_test(isupper);
    add_test(isxdigit);
    add_test(tolower);
    add_test(toupper);

    test_end();
}
