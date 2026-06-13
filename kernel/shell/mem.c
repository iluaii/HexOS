#include "../../include/globals.h"
#include "../../include/vga.h"

void mem(int argc, char **argv) {
    (void)argc; (void)argv;
    uint32_t mb = g_mbi->mem_upper / 1024;
    print("RAM: ");
    printI(mb);
    print(" MB\n");
}