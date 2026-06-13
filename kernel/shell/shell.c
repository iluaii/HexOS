#include "shell.h"
#include "../../include/string.h"
#include "../../include/bins.h"
#include "../../include/vga.h"
#include "../../include/globals.h"

#define CMD_COUNT 10

struct file {
    const char *name;
    const char *content;
};

typedef void (*cmd_func)(int argc, char **argv);

struct command {
    const char *name;
    cmd_func    func;
};

static struct command commands[] = {
    {"help",  help},
    {"ls", ls},
    {"cat", cat},
    {"clear", clear},
    {"poweroff", poweroff},
    {"reboot", reboot},
    {"mem", mem},
    {"uname", uname},
    {"echo", echo},
    {"neofetch", neofetch},
};

static char *args[16];
static int   argc;

static void parse_args(char *input) {
    argc = 0;
    args[argc++] = input;

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == ' ') {
            input[i] = '\0';
            args[argc++] = &input[i + 1];
        }
    }
}

void shell_run(char *input) {
    parse_args(input);

    for (int i = 0; i < CMD_COUNT; i++) {
        if (strcmp(args[0], commands[i].name) == 0) {
            commands[i].func(argc, args);
            print(nameUser); print("@"); print(nameOS); print("> ");
            return;
        }
    }

    printC("unknown command\n", COLOR_RED);
    print(nameUser); print("@"); print(nameOS); print("> ");
}