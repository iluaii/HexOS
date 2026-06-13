#include "../include/idt.h"
#include "../include/keyboard.h"

struct idt_entry {
    unsigned short base_low;
    unsigned short sel;
    unsigned char  zero;
    unsigned char  flags;
    unsigned short base_high;
} __attribute__((packed));

struct idt_ptr {
    unsigned short limit;
    unsigned int   base;
} __attribute__((packed));

static struct idt_entry idt[256];
static struct idt_ptr   ip;

extern void idt_flush(unsigned int);
extern void keyboard_isr(void);

void idt_set(int i, unsigned int base, unsigned short sel, unsigned char flags) {
    idt[i].base_low = base & 0xFFFF;
    idt[i].base_high = (base >> 16) & 0xFFFF;
    idt[i].sel = sel;
    idt[i].zero = 0;
    idt[i].flags = flags;
}

void idt_init(void) {
    ip.limit = sizeof(idt) - 1;
    ip.base = (unsigned int) &idt;

    for (int i = 0; i < 256; i++) {
        idt_set(i, 0, 0, 0);
    }

    idt_set(33, (unsigned int) keyboard_isr, 0x08, 0x8E);
    idt_flush((unsigned int) &ip);

    __asm__ __volatile__("sti");
}