BITS 64

section .text

GLOBAL strchr

strchr:
    XOR rax, rax
    XOR rdx, rdx

.loop:
    CMP BYTE [rdi + rdx], 0
    JZ .notfound

    CMP BYTE [rdi + rdx], sil
    JZ .found

    INC rdx
    JMP .loop

.found:
    LEA rax, [rdi + rdx]
    RET

.notfound:
    RET
