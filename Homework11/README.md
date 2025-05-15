# hw11 - x86 Assembly

## Description

This program reads a series of bytes from 'inputBuf', converts each byte into its **2-digit uppercase ASCII hexadecimal** representation, and prints the result to the screen, separated by spaces and ending with a newline.

## Example:
83 6A 88 DE 9A C3 54 9A

## Build and Run Instructions
Make sure you're using a 32-bit system or compiling with 32-bit support:

### 1. Compile with NASM and Link with 'ld'
```bash
nasm -f elf32 -o hw11.o hw11.asm
ld -m elf-i386 -o hw11 hw11.o
```

### 2. Run the Program
```bash
./hw11