BITS 64

section .text

GLOBAL strchr

strchr:
    XOR rax, rax
    XOR rdx, rdx

.loop:
    CMP BYTE [rdi + rdx], sil
    JZ .found

    CMP BYTE [rdi + rdx], 0
    JZ .notfound

    INC rdx
    JMP .loop

.found:
    LEA rax, [rdi + rdx]
    RET

.notfound:
    RET
