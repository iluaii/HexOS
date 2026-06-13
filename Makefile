CC = gcc
LD = ld
NASM = nasm

CFLAGS = -m32 -ffreestanding -O2 -Wall -Wextra -nostdlib -fno-builtin -fno-stack-protector
LDFLAGS = -m elf_i386 -T linker.ld
BUILDDIR = build

SRCS = $(shell find kernel/ -name "*.c")
OBJS = $(SRCS:%.c=$(BUILDDIR)/%.o) \
       $(BUILDDIR)/boot/boot.o \
       $(BUILDDIR)/kernel/arch/gdt.o \
       $(BUILDDIR)/kernel/arch/idt.o

all: my_os.iso

$(BUILDDIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/boot/boot.o: boot/boot.asm
	mkdir -p $(dir $@)
	$(NASM) -f elf32 $< -o $@

$(BUILDDIR)/kernel/arch/gdt.o: kernel/arch/gdt.asm
	mkdir -p $(dir $@)
	$(NASM) -f elf32 $< -o $@

$(BUILDDIR)/kernel/arch/idt.o: kernel/arch/idt.asm
	mkdir -p $(dir $@)
	$(NASM) -f elf32 $< -o $@

my_os.bin: $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

my_os.iso: my_os.bin
	mkdir -p iso/boot/grub
	cp my_os.bin iso/boot/
	echo 'menuentry "HexOS" { multiboot /boot/my_os.bin; boot }' > iso/boot/grub/grub.cfg
	grub-mkrescue -o my_os.iso iso/

run: my_os.iso
	qemu-system-i386 -cdrom my_os.iso

clean:
	rm -rf $(BUILDDIR) my_os.bin my_os.iso
	rm -rf iso/

.PHONY: all run clean