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

    MOV dh, BYTE [rsi + rcx]
    MOV BYTE [rdi + rcx], dh
    INC rcx
    JMP .loop

.end:
    MOV rax, rdi
    RET
