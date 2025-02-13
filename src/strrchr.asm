BITS 64

section .text

GLOBAL strrchr

strrchr:
    XOR rax, rax
    XOR rdx, rdx

.loop:
    CMP BYTE [rdi + rdx], sil
    JZ .found

    CMP BYTE [rdi + rdx], 0
    JZ .end

    INC rdx
    JMP .loop

.found:
    LEA rax, [rdi + rdx]

    CMP BYTE [rdi + rdx], 0
    JZ .end

    INC rdx
    JMP .loop

.end:
    RET
