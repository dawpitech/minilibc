BITS 64

SECTION .text

GLOBAL memmove

; rdi, rsi, rdx
; dst, src, siz

; counter: rcx
;  return: rax

memmove:

.buffer_in:
    XOR rcx, rcx
    XOR r8, r8

.loop_in:
    CMP rcx, rdx
    JE .buffer_out
    MOV r8b, [rsi + rcx]
    PUSH r8
    INC rcx
    JMP .loop_in

.buffer_out:

.loop_out:
    CMP rcx, 0
    JZ .end
    DEC rcx
    POP r8
    MOV [rdi + rcx], r8b
    JMP .loop_out

.end:
    MOV rax, rdi
    RET
