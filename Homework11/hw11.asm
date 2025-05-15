section .data
inputBuf:
    db 0x83,0x6A,0x88,0xDE,0x9A,0xC3,0x54,0x9A
inputLen equ $ - inputBuf

newline: db 10

section .bss
outputBuf: resb 80

section .text
    global _start

_start:
    mov esi, inputBuf   ; Set ESI to point to the input byte buffer
    mov edi, outputBuf  ; Set EDI to point to the output character buffer
    mov ecx, inputLen   ; Set loop counter to number of bytes to translate

translate_loop:
    lodsb   ; Load next byte into AL and advance ESI
    push ecx    ; Preserve loop counter across subroutine call

    ; Translate the byte into two ASCII hex characters
    ; Writes result directly into [EDI]
    movzx ecx, al   ; Move byte into ECX for subroutine
    call byteToHex

    add edi, 2      ; Advance output position for 2 hex digits
    mov byte [edi], ' '     ; Add space
    inc edi

    pop ecx         ; Restore loop counter
    loop translate_loop

    ; Overwrite last space with newline
    dec edi
    mov byte [edi], 10
    inc edi

    ; System call to print outputBuf to stdout
    mov eax, 4      
    mov ebx, 1
    mov ecx, outputBuf
    mov edx, edi
    sub edx, outputBuf      ; length = edi - outputBuf
    int 0x80

    ; Exit the program
    mov eax, 1
    xor ebx, ebx
    int 0x80

; -------------------------
; byteToHex:
; Takes a byte in CL
; Translates it to 2 ASCII hex digits (high and low nibble)
; Stores result in [EDI] and [EDI+1]
; -------------------------

byteToHex:
    push eax
    push ebx
    mov al, cl 
    shr al, 4
    call nibbleToAscii
    mov [edi], al 

    mov al, cl 
    and al, 0x0F
    call nibbleToAscii
    mov [edi+1], al

    pop ebx 
    pop eax
    ret 

; ------------------------
; nibbleToAscii:
; Converts a 4-bit nibble in AL to its ASCII hex character
; If nibble < 10, it returns '0'-'9'
; If nibble >= 10, it returns 'A'-'F'
; ------------------------

nibbleToAscii:
    cmp al, 9
    jbe .is_digit
    add al, 0x37    ; 'A' - 10 = 65 - 10 = 55
    ret 
.is_digit:
    add al, '0'
    ret