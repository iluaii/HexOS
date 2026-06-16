#include "../include/globals.h"
#include "../include/vga.h"
#include "../include/gdt.h"
#include "../include/idt.h"
#include "../include/pic.h"
//#include <stdint.h>

//#include "../../../../../../usr/include/ncurses.h"


struct multiboot_info *g_mbi;
char nameOS[32] = "4865784F53";
char nameUser[64] = "root";
char versionOS[64] = "1.1";

void kernel_main(uint32_t magic, struct multiboot_info *mbi) {
    g_mbi = mbi;
    vga_clear();
    gdt_init();
    idt_init();
    pic_init();
    print("                     #   #  #####  #   #   ###    ####\n");
    print("                    #   #  #       # #   #   #  #\n");
    print("                   #####  ####     #    #   #   ###\n");
    print("                  #   #  #       # #   #   #      #\n");
    print("                 #   #  #####  #   #   ###   ####\n\n");
    printC("                       Welcome to HexOS ", COLOR_GREEN); printC(versionOS, COLOR_GREEN); print("\n\n");
    printPromptLine();
    while(1);
}
