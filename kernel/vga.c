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

void printI(int n) {
    char buf[16];
    int i = 0;
    if (n == 0) { print("0"); return; }
    char tmp[16];
    int j = 0;
    while (n > 0) { tmp[j++] = '0' + (n % 10); n /= 10; }
    while (j > 0) { buf[i++] = tmp[--j]; }
    buf[i] = '\0';
    print(buf);
}

void printC(const char *text, unsigned char color) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == '\n') {
            cursor += VGA_WIDTH - (cursor % VGA_WIDTH);
        } else {
            vga[cursor * 2]     = text[i];
            vga[cursor * 2 + 1] = color;
            cursor++;
        }
    }
}