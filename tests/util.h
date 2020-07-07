#ifndef __UTIL_H__
#define __UTIL_H__

#include <stdio.h>
#include <stddef.h>

#define test_init() \
    int __f = 0, __s = 0;

#define test_end() \
    do { \
        if (__f) \
            printf("\x1b[31msucceeded: %d, failed %d\x1b[0m\n", __s, __f); \
        else \
            printf("\x1b[32msucceeded: %d, failed %d\x1b[0m\n", __s, __f); \
        asm ("movl $1,%eax;" \
            "xorl %ebx,%ebx;" \
            "int  $0x80" \
        ); \
    } while (0)

#define add_test(func) \
    test_##func(&__s, &__f)

#define test(func) \
    static void test_##func(int *__s, int *__f)

#define ok(cond, msg, ...) \
    do { \
        if (!(cond)) { \
            printf("%s:%d: " msg, __FILE__, __LINE__, ##__VA_ARGS__); \
            (*__f)++; \
        } else { \
            (*__s)++; \
        } \
    } while (0)

#endif /* __UTIL_H__ */
