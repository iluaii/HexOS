global idt_flush
global keyboard_isr

extern keyboard_handler

idt_flush:
    mov eax, [esp+4]
    lidt [eax]
    ret

keyboard_isr:
    pusha
    call keyboard_handler
    popa
    iret