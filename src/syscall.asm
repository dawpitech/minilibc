BITS 64

section .text

GLOBAL syscall

EXTERN __errno_location

syscall:
    ; save all registers to the stack
    ; except rax as it will be overwritten
    PUSH rcx
    PUSH rdx
    PUSH rbx
    PUSH rsp
    PUSH rbp
    PUSH rsi
    PUSH rdi
    PUSH r8
    PUSH r9
    PUSH r10
    PUSH r11
    PUSH r12
    PUSH r13
    PUSH r14
    PUSH r15

    ; call the actual syscall
    syscall

;    CMP rax, 0
;    JZ .restore_reg
;
;    ; if syscall returned an error
;    ; put it inside errno
;    MOV rdx, rax
;    CALL __errno_location
;    MOV [rax], rdx
;    MOV rax, rdx

.restore_reg:
    ; retrieve all registers from the stack
    ; except rax as it will be overwritten
    POP r15
    POP r14
    POP r13
    POP r12
    POP r11
    POP r10
    POP r9
    POP r8
    POP rdi
    POP rsi
    POP rbp
    POP rsp
    POP rbx
    POP rdx
    POP rcx
    RET
