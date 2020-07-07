include src/string/make.config
include src/stdlib/make.config
include src/stdio/make.config
include src/ctype/make.config
include src/arch/linux/make.config

CC = x86_64-elf-gcc
AR = x86_64-elf-ar
AS = x86_64-elf-as

CFLAGS := -g -ffreestanding --sysroot=sysroot -isystem=/usr/include -O2 -fPIC

OBJS = \
$(ARCH_FREEOBJS) \
$(LIBC_STRING_OBJS) \
$(LIBC_STDIO_OBJS) \
$(LIBC_STDLIB_OBJS) \
$(LIBC_CTYPE_OBJS) \

BINARIES=libc.a

.PHONY: all clean sysroot tests
.SUFFIXES: .o .libk.o .c .S

all: sysroot $(BINARIES)

libc.a: $(OBJS)
	$(AR) rcs $@ $(OBJS)

.c.o:
	$(CC) -MD -c $< -o $@ -std=gnu11 $(CFLAGS)

.c.S:
	$(CC) -MD -c $< -o $@ $(CFLAGS)

tests:
	@make all
	@make all -C tests

clean:
	rm -f $(BINARIES) *.a
	rm -f $(OBJS) *.o */*.o */*/*.o
	rm -f $(OBJS:.o=.d) *.d */*.d */*/*.d
	rm -rf sysroot

sysroot:
	mkdir -p sysroot/usr
	cp -R --preserve=timestamps src/include/ sysroot/usr
