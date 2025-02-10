BITS 64

section .text

GLOBAL strncmp

; rdi, rsi, rdx
; str, str2, int

; return: rax
; counter: rcx

strncmp:
    XOR rax, rax
    XOR rcx, rcx

.loop:
    CMP rcx, rdx
    JE .end

    MOV r8b, BYTE[rdi + rcx]
    MOV r9b, BYTE[rsi + rcx]
    CMP r8b, r9b
    JNE .notequal

    CMP r8b, 0
    JZ .end

    INC rcx
    JMP .loop

; if both current char are not equal
.notequal:
    SUB r8b, r9b
    MOVSX rax, r8b
    RET

; reached end of both str
.end:
    RET
