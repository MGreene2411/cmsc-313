# Matrix Library Project (C and C++)

## AUTHORING
- **Name:** Michael Greene
- **Class:** CMSC 313 - Spring 2025
- **Date:** April 16, 2025

## PURPOSE OF SOFTWARE
This project implements a matrix manipulation library in both **C++** and **C**. The library supports basic matrix operations including:
- Matrix addition
- Scalar multiplication
- Matrix multiplication
- Matrix transpose

The goal is to provide both an object-oriented (C++) and procedural (C99) implementation suitable for an x86 architecture, compiled using `gcc`.

## FILES

### C++ Version
- `C++matrix.cpp` — C++ implementation of the `Matrix` class
- `C++matrix.h` — Header file for the C++ Matrix class
- `C++main.cpp` — Test program that performs the matrix operation `D = A + (3 * B) * Cᵀ`

### C Version
- `Cmatrix.c` — C implementation of the matrix functions using a `struct Matrix`
- `Cmatrix.h` — Header file for the C Matrix functions and struct
- `Cmain.c` — Test program for the same matrix operation using the C functions

### Shared
- `CMakeLists.txt` — CMake build file for both C and C++ versions

## BUILD INSTRUCTIONS

### Using CLion (Recommended)
1. Open the `Homework 8` directory in CLion as a project.
2. CLion will auto-detect the `CMakeLists.txt` file.
3. Use the top-right dropdown to select either:
    - `matrix_cpp` — to run the C++ version
    - `matrix_c` — to run the C version
4. Click **Run** ▶️ or **Build → Build Project**

### Using Terminal (x86 Linux/GCC)
```bash
# For C++
g++ -std=c++14 C++matrix.cpp C++main.cpp -o matrix_cpp

# For C
gcc -std=c99 Cmatrix.c Cmain.c -o matrix_c
