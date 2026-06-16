#include "../../include/vga.h"

void help(int argc, char **argv) {
    print("ls - list files in the virtual filesystem\n");
    print("cat <file> - print file contents\n");
    print("clear - clear the screen\n");
    print("poweroff - poweroff of system\n");
    print("reboot - reboot of system\n");
    print("mem - output of used RAM\n");
    print("uname - output of system version\n");
    print("echo - print text\n");
    print("neofetch - print logo\n");
    print("time - print the time\n");
    print("whoami - print your name\n");
    print("rand - print random number generator\n");
}