#include "../include/string.h"
#include "../include/vga.h"
#include "../include/gdt.h"
#include "../include/idt.h"
#include "../include/pic.h"


void kernel_main(void) {
    vga_clear();
    gdt_init();
    idt_init();
    pic_init();
    print("root@HexOS> ");
    while(1);
}
