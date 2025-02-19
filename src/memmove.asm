BITS 64

SECTION .text

GLOBAL memmove

; rdi, rsi, rdx
; dst, src, siz

; counter: rcx
;  return: rax

memmove:
    XOR rcx, rcx

    CMP rdi, rsi
    JA .cpy_right
    JB .cpy_left_loop
    JE .end

.cpy_left_loop:
    CMP rcx, rdx
    JE .end

    MOV r8b, [rsi + rcx]
    MOV [rdi + rcx], r8b
    INC rcx
    JMP .cpy_left_loop

.cpy_right:
    MOV rcx, rdx

.cpy_right_loop:
    CMP rcx, 0
    JE .end

    MOV r8b, [rsi + rcx - 1]
    MOV [rdi + rcx - 1], r8b
    DEC rcx
    JMP .cpy_right_loop

.end:
    MOV rax, rdi
    RET
