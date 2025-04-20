cmake_minimum_required(VERSION 3.15)
project(MatrixLibrary C CXX)

# Enable C++14
set(CMAKE_CXX_STANDARD 14)

# C99
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -O0")

# C++ Matrix Test
add_executable(matrix_cpp
        C++matrix.cpp
        C++matrix.h
        C++main.cpp
)

# C Matrix Test
add_executable(matrix_c
        Cmatrix.c
        Cmatrix.h
        Cmain.c
)
