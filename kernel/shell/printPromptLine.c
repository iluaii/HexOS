#include "../../include/globals.h"
#include "../../include/vga.h"

void printPromptLine(void) {
    print(nameUser); print("@"); print(nameOS); print("> ");
}