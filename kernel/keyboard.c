#include "../include/keyboard.h"
#include "../include/pic.h"
#include "../include/vga.h"
#include "shell/shell.h"

static const char scancode_map[] = {
    0, 0, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 0,
    0, 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
    0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`',
    0, '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0,
    '*', 0, ' '
};
static char input_buf[256];
static int  input_len = 0;

static unsigned char inb(unsigned short port) {
    unsigned char val;
    __asm__ volatile ("inb %1, %0" : "=a" (val) : "Nd" (port));
    return val;
}

void keyboard_handler(void) {
    unsigned char scancode = inb(0x60);

    if (scancode & 0x80) {
        pic_ack();
        return;
    }
    if (scancode == 0x1C) {
        input_buf[input_len] = '\0';
        print("\n");
        shell_run(input_buf);
        input_len = 0;
        pic_ack();
        return;
    }
    if (scancode == 0x0E) {
        if (input_len > 0) {
            input_len--;
            input_buf[input_len] = '\0';
        }
        vga_backspace();
        pic_ack();
        return;
    }
    if (scancode < sizeof(scancode_map) && scancode_map[scancode]) {
        char str[2] = { scancode_map[scancode], '\0' };
        print(str);
        input_buf[input_len] = scancode_map[scancode];
        input_len++;
    }
    pic_ack();
}