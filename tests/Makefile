.PHONY: all

CC = gcc
CCFLAGS :=  -Wall -Wextra -Werror -O2 -Wshadow -Wno-return-type -g
CCFLAGS_ALIB := $(CCFLAGS) -ffreestanding -nostdlib -nostartfiles --sysroot=../sysroot
TEST_FILES := $(patsubst %.c, %.o, $(filter %.c, $(wildcard *.c)))

all: $(TEST_FILES)

%.o: %.c
	$(CC) $(CCFLAGS) -o glib_$@ $<
	$(CC) $(CCFLAGS_ALIB) -o alib_$@ $< ../src/crt0.S -L.. -lc
	@./glib_$@ && ./alib_$@

clean:
	rm -f glib_*.o alib_*.o
