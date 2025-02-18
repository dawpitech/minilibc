BITS 64

section .text

GLOBAL strpbrk

; rdi,    rsi
; str, accept

;      return: rax
; str_counter: rcx
; acp_counter: rdx

; r8b: current char in the str
; r9b: current char of accept

strpbrk:
    XOR rax, rax
    XOR rcx, rcx
    XOR rdx, rdx

.loop:
    MOV r8b, BYTE[rdi + rcx]
    MOV r9b, BYTE[rsi + rdx]

    CMP r8b, 0
    JZ .notfound

    CMP r9b, 0
    JZ .advance_in_str

    CMP r8b, r9b
    JE .found

    INC rdx
    JMP .loop

.advance_in_str:
    INC rcx
    XOR rdx, rdx
    JMP .loop

.found:
    LEA rax, [rdi + rcx]
    RET

.notfound:
    RET
