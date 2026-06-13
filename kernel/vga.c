#include "../include/string.h"
#define VGA_WIDTH 80
static char *vga;
static int cursor;
static void outb(unsigned short port, unsigned char val) {
    __asm__ volatile ("outb %0, %1" : : "a"(val), "Nd"(port));
}
void vga_clear(void) {
    outb(0x3D4, 0x0A);
    outb(0x3D5, 0x20);
    vga = (char*) 0xB8000;
    cursor = 0;
    for (int i = 0; i < 80 * 25 * 2; i += 2) {
        vga[i]     = ' ';
        vga[i + 1] = 0x07;
    }
}

void vga_backspace(void) {
    if (cursor > 0) {
        cursor--;
        vga[cursor * 2] = ' ';
    }
}

void print(const char *text) {
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == '\n') {
            cursor += VGA_WIDTH - (cursor % VGA_WIDTH);
        } else {
            vga[cursor * 2]     = text[i];
            vga[cursor * 2 + 1] = 0x0F;
            cursor++;
        }
    }
}