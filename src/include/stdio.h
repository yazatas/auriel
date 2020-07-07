#ifndef __STDIO_H__
#define __STDIO_H__

#include <sys/cdefs.h>

#define EOF   (-1)
#define stdin  0
#define stdout 1
#define stderr 2

int printf(const char *fmt, ...);
int fprintf(int fd, const char *fmt, ...);
int putchar(int c);
int puts(const char *fmt);

#endif /* __STDIO_H__ */
