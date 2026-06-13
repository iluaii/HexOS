section .multiboot align=4
dd 0x1BADB002
dd 0x00
dd 0xE4524FFE

section .text
global _start
extern kernel_main

_start:
    cli
    mov esp, stack_space
    push ebx
    push eax
    call kernel_main
    hlt

section .bss
resb 8192
stack_space: