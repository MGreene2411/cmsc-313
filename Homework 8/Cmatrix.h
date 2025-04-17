#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    int rows;
    int cols;
    int** data;
} Matrix;

Matrix* createMatrix(int rows, int cols);
void freeMatrix(Matrix* mat);
void set(Matrix* mat, int i, int j, int value);
int get(const Matrix* mat, int i, int j);
void printMatrix(const Matrix* mat);
Matrix* transpose(const Matrix* mat);
Matrix* add(const Matrix* a, const Matrix* b);
Matrix* multiply(const Matrix* a, const Matrix* b);
Matrix* scalarMultiply(const Matrix* mat, int scalar);

#endif

