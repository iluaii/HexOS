# HexOS

A hobby x86 operating system written from scratch in C and NASM assembly. Built as a learning project to understand how operating systems work at the lowest level — bootloading, memory, interrupts, and basic I/O.

## What it does

HexOS boots via GRUB with a Multiboot-compliant kernel and drops you into a minimal shell. It runs in 32-bit protected mode.

**Shell commands:**
- `help` — list available commands
- `ls` — list files in the virtual filesystem
- `cat <file>` — print file contents
- `clear` — clear the screen
- `poweroff` - poweroff of system
- `reboot` - reboot of system
- `mem` - output of used RAM
- `uname` - output of system version
- `echo` - print text
- `neofetch` - print logo
- `time` - print the time

## How it works

- **Bootloader** — NASM assembly stub with a Multiboot header, sets up the stack and jumps to the kernel
- **GDT** — sets up the Global Descriptor Table for protected mode segmentation
- **IDT** — Interrupt Descriptor Table for handling hardware interrupts
- **PIC** — remaps IRQs so keyboard input works correctly
- **VGA** — writes directly to the VGA text buffer at `0xB8000`
- **Keyboard** — reads scancodes via IRQ1 and maps them to ASCII
- **Shell** — a simple command loop with argument parsing

## Requirements

```
nasm
gcc (with multilib / 32-bit support)
ld (binutils)
qemu-system-i386
grub
xorriso
mtools
```

On Arch Linux:
```bash
sudo pacman -S nasm gcc qemu grub xorriso mtools
```

## Build and run

```bash
make run
```

To just build the ISO:
```bash
make
```

To clean:
```bash
make clean
```

## Project structure

```
boot/        — assembly bootloader
kernel/
  arch/      — low-level ASM (GDT, IDT flush)
  shell/     — shell, commands, virtual filesystem
  kernel.c   — entry point
  gdt.c      — Global Descriptor Table
  idt.c      — Interrupt Descriptor Table
  pic.c      — Programmable Interrupt Controller
  keyboard.c — keyboard driver
  vga.c      — VGA text output
include/     — header files
linker.ld    — linker script
Makefile
```

## Notes

This is a hobby project made to learn OS internals. It has no userspace, no memory allocator, and no real filesystem — just a kernel, a keyboard, and a shell.