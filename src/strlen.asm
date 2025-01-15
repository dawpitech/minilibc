BITS 64

SECTION .text

GLOBAL strlen

strlen:
    XOR rax, rax

.loop:
    CMP BYTE [rdi + rax], 0
    JZ .end

    INC rax
    JMP .loop
.end:
    RET
