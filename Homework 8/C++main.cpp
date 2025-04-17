#include "C++matrix.h"
#include <iostream>

int main() {
    // Define A (2x2)
    Matrix A(2, 2);
    A.set(0, 0, 6);
    A.set(0, 1, 4);
    A.set(1, 0, 8);
    A.set(1, 1, 3);

    // Define B (2x3)
    Matrix B(2, 3);
    B.set(0, 0, 1); B.set(0, 1, 2); B.set(0, 2, 3);
    B.set(1, 0, 4); B.set(1, 1, 5); B.set(1, 2, 6);

    // Define C (2x3)
    Matrix C(2, 3);
    C.set(0, 0, 2); C.set(0, 1, 4); C.set(0, 2, 6);
    C.set(1, 0, 1); C.set(1, 1, 3); C.set(1, 2, 5);

    // Compute 3 * B
    Matrix B_scaled = B * 3;

    // Compute C transpose (3x2)
    Matrix C_T = C.transpose();

    // Compute (3 * B) * C_T
    Matrix product = B_scaled * C_T;

    // Compute D = A + (3 * B) * C^T
    Matrix D = A + product;

    // Print D
    std::cout << "Matrix D = A + (3 * B) * C^T:" << std::endl;
    D.print();

    return 0;
}
