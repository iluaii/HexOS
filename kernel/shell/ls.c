#include "../../include/vga.h"
#include "fs.h"

void ls(int argc, char **argv) {
    (void)argc; (void)argv;
    for (int i = 0; i < FILES_COUNT; i++) {
        print(files[i].name);
        print("\n");
    }
}