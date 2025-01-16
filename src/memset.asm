BITS 64

section .text

GLOBAL memset

memset:
    XOR rcx, rcx

.loop:
    CMP rcx, rdx
    JE .end

    MOV BYTE [rdi + rcx], sil
    INC rcx
    JMP .loop

.end:
    MOV rax, rdi
    RET
