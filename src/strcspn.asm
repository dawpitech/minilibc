BITS 64

section .text

GLOBAL strcspn

; rdi,    rsi
; str, reject

;      return: rax
; str_counter: rcx
; rjt_counter: rdx

; r8b: current char in the str
; r9b: current char of reject

strcspn:
    XOR rax, rax
    XOR rcx, rcx
    XOR rdx, rdx

.loop:
    MOV r8b, BYTE[rdi + rcx]
    MOV r9b, BYTE[rsi + rdx]

    CMP r8b, 0
    JZ .end

    CMP r9b, 0
    JZ .advance_in_str

    CMP r8b, r9b
    JE .end

    INC rdx
    JMP .loop

.advance_in_str:
    INC rcx
    XOR rdx, rdx
    JMP .loop

.end:
    MOV rax, rcx
    RET
