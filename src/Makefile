CC=gcc
LK=ld
CFLAGS=-nostdinc -fno-builtin -nostdlib -nostartfiles -nodefaultlibs -Wall -Wextra -c -fno-pie -no-pie -MD -ffreestanding
LKFLAGS=-e loader -T linker.ld -melf_i386 -no-pie
EXEC=kernel.bin

all: $(EXEC)

kernel.o: kernel.c
	$(CC) -o kernel.bin kernel.c $(CFLAGS)
kernel.bin: boot/boot.o kernel.o
	ld -e loader -T linker.ld melf_i386 -no-pie boot/boot.o kernel.o -o kernel.bin
