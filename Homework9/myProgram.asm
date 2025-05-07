; Hello World - asmtutor.com
; Student: Michael Greene
; Class: CMSC 313 (Mo/Wed : 10-11:15AM)

SECTION .data
msg     db      'Hello from Michael Greene!', 0Ah

SECTION .text
global  _start

_start:
    mov     edx, 27        ; Length of message
    mov     ecx, msg       ; Message address
    mov     ebx, 1         ; STDOUT
    mov     eax, 4         ; sys_write
    int     80h

    mov     ebx, 0         ; Exit code 0 (no error)
    mov     eax, 1         ; sys_exit
    int     80h