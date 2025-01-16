BITS 64

section .text

GLOBAL strrchr

strrchr:
    XOR rax, rax
    XOR rdx, rdx
    JMP .loop

.found:
    LEA rax, [rdi + rdx]
    INC rdx

.loop:
    CMP BYTE [rdi + rdx], 0
    JZ .end

    CMP BYTE [rdi + rdx], sil
    JZ .found

    INC rdx
    JMP .loop

.end:
    RET
