//
// Created by ilu on 6/12/26.
//

#ifndef CODPROJECTS_VGA_H
#define CODPROJECTS_VGA_H

#define COLOR_WHITE   0x0F
#define COLOR_RED     0x04
#define COLOR_GREEN   0x02
#define COLOR_BLUE    0x01
#define COLOR_CYAN    0x03
#define COLOR_YELLOW  0x0E

void print(const char *text);
void printI(int n);
void printC(const char *text, unsigned char color);
void vga_clear(void);
void vga_backspace(void);
#endif //CODPROJECTS_VGA_H
