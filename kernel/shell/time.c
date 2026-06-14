#include "../../../../../../../usr/include/ncurses.h"
#include "../../include/vga.h"
#include "../../include/globals.h"


static unsigned char rtcRead(unsigned char reg) {
    __asm__ volatile ("outb %0, $0x70" :: "a" (reg));
    unsigned char val;
    __asm__ volatile ("inb $0x71, %0" : "=a" (val));
    return val;
}
static unsigned char bcdToBin(unsigned char bcd) {
    return (bcd >> 4) * 10 + (bcd & 0x0F);
}

void time(int argc, char **argv) {
    unsigned char h = bcdToBin(rtcRead(0x04));
    h = (h+TIME_UTC) % 24;
    unsigned char m = bcdToBin(rtcRead(0x02));
    unsigned char s = bcdToBin(rtcRead(0x00));

    printI(h); print(":");
    printI(m); print(":");
    printI(s); print("\n");
}