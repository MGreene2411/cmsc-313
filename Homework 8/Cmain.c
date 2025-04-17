#include <stdio.h>
#include "Cmatrix.h"

int main() {
    // Matrix A (2x2)
    Matrix* A = createMatrix(2, 2);
    set(A, 0, 0, 6); set(A, 0, 1, 4);
    set(A, 1, 0, 8); set(A, 1, 1, 3);

    // Matrix B (2x3)
    Matrix* B = createMatrix(2, 3);
    set(B, 0, 0, 1); set(B, 0, 1, 2); set(B, 0, 2, 3);
    set(B, 1, 0, 4); set(B, 1, 1, 5); set(B, 1, 2, 6);

    // Matrix C (2x3)
    Matrix* C = createMatrix(2, 3);
    set(C, 0, 0, 2); set(C, 0, 1, 4); set(C, 0, 2, 6);
    set(C, 1, 0, 1); set(C, 1, 1, 3); set(C, 1, 2, 5);

    // Compute 3 * B
    Matrix* B_scaled = scalarMultiply(B, 3);

    // Compute C^T (3x2)
    Matrix* C_T = transpose(C);

    // Multiply (3B) * C^T → (2x3) * (3x2) = (2x2)
    Matrix* product = multiply(B_scaled, C_T);

    // Compute D = A + product
    Matrix* D = add(A, product);

    printf("Matrix D = A + (3 * B) * C^T:\n");
    printMatrix(D);

    // Clean up
    freeMatrix(A);
    freeMatrix(B);
    freeMatrix(C);
    freeMatrix(B_scaled);
    freeMatrix(C_T);
    freeMatrix(product);
    freeMatrix(D);

    return 0;
}
