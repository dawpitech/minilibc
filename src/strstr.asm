BITS 64

section .text

GLOBAL strstr

EXTERN strncmp

;      rdi,    rsi
; haystack, needle

;      return: rax
; hay_counter: rcx
; ndl_counter: rdx

; r8b: current char of haystack
; r9b: current char of needle

strstr:
    XOR rax, rax
    XOR rcx, rcx
    XOR rdx, rdx

    CMP BYTE[rsi], 0
    JZ .empty_needle
    JMP .loop

.empty_needle:
    MOV rax, rdi
    RET

.loop:
    MOV r8b, BYTE[rdi + rcx]
    MOV r9b, BYTE[rsi + rdx]

    CMP r9b, 0
    JZ .found

    CMP r8b, 0
    JZ .notfound

    CMP r8b, r9b
    JNE .notequal

    CMP rdx, 0
    JZ .new_found
    JMP .inc_after_loop

.new_found:
    LEA rax, [rdi + rcx]

.inc_after_loop:
    INC rdx
    INC rcx
    JMP .loop

.notequal:
    INC rcx
    XOR rdx, rdx
    JMP .loop

.notfound:
    XOR rax, rax
    RET

.found:
    RET
