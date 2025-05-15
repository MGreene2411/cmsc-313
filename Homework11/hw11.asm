section .data
inputBuf:
    db 0x83,0x6A,0x88,0x9A,0xC3,0x54,0x9A
inputLen equ $ - inputBuf

newline: db 10

section .bss
outputBuf: resb 80

section .text
    global _start

_start:
    mov esi, inputBuf   ; ESI = source pointer
    mov edi, outputBuf  ; EDI = destination pointer
    mov ecx, inputLen   ; Number of bytes to translate

translate_loop:
    lodsb   ; Load byte from [ESI] into AL, advance ESI
    push ecx    ; Save loop counter

    ; Convert byte to 2-digit hex
    movzx ecx, al   ; Move byte to ecx
    call byteToHex  ; Translates byte in CL, result in [EDI]

    add edi, 2      ; Advance output buffer by 2 bytes
    mov byte [edi], ' '     ; Add space
    inc edi

    pop ecx
    loop translate_loop

    ; Replace last space with newline
    dec edi
    mov byte [edi], 10

    ; Print buffer to stdout (sys_write)
    mov eax, 4      ; sys_write
    mov ebx, 1      ; stdout
    mov ecx, outputBuf      ; buffer
    mov edx, edi
    sub edx, outputBuf      ; length = edi - outputBuf
    int 0x80

    ; Exit
    mov eax, 1      ; sys_exit
    xor ebx, ebx
    int 0x80

