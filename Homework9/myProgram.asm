; Hello World - asmtutor.com
; Student: Michael Greene
; Class: CMSC 313 (Mo/Wed : 10-11:15AM)

SECTION .data
introMsg    db  'Michael Greene - CMSC 313 - Spring 2025', 0Ah
introLen    equ $ - introMsg

msg         db  'Hello from Michael Greene!', 0Ah
msgLen      equ $ - msg

SECTION .text
global _start

_start:

    ; Print intro message
    mov     edx, introLen     ; length of intro
    mov     ecx, introMsg     ; pointer to intro message
    mov     ebx, 1            ; file descriptor (stdout)
    mov     eax, 4            ; syscall number for sys_write
    int     80h

    ; Print hello message
    mov     edx, msgLen       ; length of hello message
    mov     ecx, msg          ; pointer to message
    mov     ebx, 1            ; stdout
    mov     eax, 4            ; sys_write
    int     80h

    ; Exit
    mov     ebx, 0            ; exit code
    mov     eax, 1            ; syscall for exit
    int     80h