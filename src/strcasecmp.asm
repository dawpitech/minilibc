BITS 64

section .text

GLOBAL strcasecmp

; rdi, rsi,
; str, str2

; return: rax
; counter: rcx

strcasecmp:
    XOR rax, rax
    XOR rcx, rcx

.loop:
    MOV r8b, BYTE[rdi + rcx]
    MOV r9b, BYTE[rsi + rcx]
    CMP r8b, r9b
    JNE .compareDiffCase

    CMP r8b, 0
    JZ .end

    INC rcx
    JMP .loop

.compareDiffCase:
    OR r8b, 32 ; apply a bitmask to make the char uppercase
    OR r9b, 32 ; same
    CMP r8b, r9b
    JNE .notequal

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
