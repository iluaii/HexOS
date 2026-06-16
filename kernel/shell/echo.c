#include "../../include/vga.h"

void echo(int argc, char **argv) {
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            print(argv[i]); print(" ");
        }
        print("\n");
    } else {
        printC("required arguments", COLOR_RED);
    }
}