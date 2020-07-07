#include <string.h>
#include "util.h"

test(memccpy)
{
    void *ret;

    char dest[256] = { 0 };
    char *src = "Hello, World";

    ret = memccpy(dest, src, 'H', 0);
    ok(!ret, "got %p, expected NULL\n", ret);
    ok(!strlen(dest), "memccpy() copied bytes: %s\n", dest);

    ret = memccpy(dest, src, 'o', 10);
    ok(ret, "got NULL, expected non-NULL\n");
    ok(!strcmp(dest, "Hello"), "got %s, expected Hello\n", dest);

    ret = memccpy(dest, src, 'z', strlen(src));
    ok(!ret, "got %p, expected NULL\n", ret);
    ok(!strcmp(dest, "Hello, World"), "got %s, expected Hello\n", dest);
}

test(memchr)
{
    void *ret;
    size_t len;
    const char *str = "Hello, World";

    ret = memchr(str, 'W', strlen(str));
    ok(ret == str + 7, "got %p, expected %p\n", ret, str + 7);

    ret = memchr(str, 'H', 0);
    ok(!ret, "got %p, expected NULL\n", ret);

    len = strlen(str);
    ret = memchr(str, 'd', len);
    ok(ret == str + len - 1, "got %p, expected %p\n", ret, str + len - 1);
}

test(memcmp)
{
    ok(!memcmp("", "", 0), "got non-zero, expected zero\n");
    ok(!memcmp("test", "test", 5), "got non-zero, expected zero\n");
    ok(memcmp("test", "testing", 5), "got non-zero, expected zero\n");
    ok(memcmp("test", "helo", 5), "got zero, expected non-zero\n");
}

test(strcmp)
{
    ok(!strcmp("", ""), "got non-zero, expected zero\n");
    ok(!strcmp("test", "test"), "got non-zero, expected zero\n");
    ok(strcmp("test", "testing"), "got non-zero, expected zero\n");
    ok(strcmp("test", "hello"), "got zero, expected non-zero\n");
}

test(memcpy)
{
    void *ret;
    char dst[64] = { 0 };
    char *src    = "Hello, World";

    ret = memcpy(dst, src, 0);
    ok(ret, "got NULL, expected non-NULL\n");
    ok(!strlen(dst), "memcpy() copied bytes: %s\n", dst);

    ret = memcpy(dst, src, 10);
    ok(ret, "got NULL, expected non-NULL\n");
    ok(!strcmp(dst, "Hello, Wor"), "got %s, expected 'Hello, Wor'\n", dst);

    ret = memcpy(dst, src, strlen(src));
    ok(ret, "got %p, expected NULL\n", ret);
    ok(!strcmp(dst, "Hello, World"), "got %s, expected Hello\n", dst);
}

test(memmove)
{
    void *ret;
    char dst[64] = { 0 };
    char *src    = "Hello, World";

    ret = memmove(dst, src, 0);
    ok(ret, "got NULL, expected non-NULL\n");
    ok(!strlen(dst), "memccpy() copied bytes: %s\n", dst);

    ret = memmove(dst, src, 10);
    ok(ret, "got NULL, expected non-NULL\n");
    ok(!strcmp(dst, "Hello, Wor"), "got %s, expected 'Hello, Wor'\n", dst);

    ret = memmove(dst, src, strlen(src));
    ok(ret, "got %p, expected NULL\n", ret);
    ok(!strcmp(dst, "Hello, World"), "got %s, expected Hello\n", dst);

    /* TODO: overlapping region */
}

test(memset)
{
    void *ret;
    unsigned set, i;
    char dst[10] = { 0 };

    ret = memset(dst, 0, sizeof(dst));
    ok(ret == dst, "got %p, expected %p\n", ret, dst);

    ret = memset(dst, 'a', sizeof(dst));
    ok(ret == dst, "got %p, expected %p\n", ret, dst);

    for (set = i = 0; i < sizeof(dst); ++i)
        if (dst[i] == 'a') set++;

    ok(set == sizeof(dst), "got %d, expected 0\n", set);
}

test(stpcpy)
{
    char dst1[20] = { 0 };
    char *src = "Hello, World";
    char *ret;

    ret = stpcpy(dst1, src);
    ok(ret == dst1 + strlen(src), "got %p, expected %p\n", ret, dst1 + strlen(src));
    ok(!strcmp(src, dst1), "got %s, expected %s\n", (char *)dst1, src);
}

test(strlen)
{
    size_t ret;

    ret = strlen("");
    ok(!ret, "got %zu, expected 0\n", ret);

    ret = strlen("Hello");
    ok(ret == 5, "got %zu, expected 5\n", ret);
}

int main(void)
{
    test_init();

    add_test(memccpy);
    add_test(memchr);
    add_test(memcmp);
    add_test(memcpy);
    add_test(memmove);
    add_test(memset);
    add_test(stpcpy);
    add_test(strcmp);
    add_test(strlen);

    test_end();
}

