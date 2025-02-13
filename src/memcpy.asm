BITS 64

section .text

GLOBAL memcpy

; rdi, rsi, rdx
; dst, src, siz

memcpy:
    XOR rcx, rcx

.loop:
    CMP rcx, rdx
    JE .end

    MOV r8b, BYTE [rsi + rcx]
    MOV BYTE [rdi + rcx], r8b
    INC rcx
    JMP .loop

.end:
    MOV rax, rdi
    RET
