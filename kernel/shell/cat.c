#include "../../include/vga.h"
#include "../../include/string.h"
#include "fs.h"

#define FILES_COUNT 2

void cat(int argc, char **argv) {
    if (argc != 2) {
        print("usage: ls <dir>\n");
        return;
    }
    for (int i = 0; i < FILES_COUNT; i++) {
        if (strcmp(files[i].name, argv[1]) == 0) {
            print(files[i].content);
            return;
        }
    }
    print("file not found\n");
}