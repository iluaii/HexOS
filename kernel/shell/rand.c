#include "../../include/vga.h"

void rand(int argc, char **argv) {
    int val;

    __asm__ __volatile__ ("rdtsc":"=a"(val)::"edx");
    printI(val); print("\n");
}