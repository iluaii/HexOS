void reboot(int argc, char **argv) {
    (void)argc; (void)argv;
    __asm__ volatile ("outb %0, %1" : : "a"((unsigned char)0xFE), "Nd"((unsigned short)0x64));
}
void poweroff(int argc, char **argv) {
    (void)argc; (void)argv;
    __asm__ volatile ("outw %0, %1" : : "a"((unsigned short)0x2000), "Nd"((unsigned short)0x604));
}