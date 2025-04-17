#include "Cmatrix.h"
#include <stdio.h>
#include <stdlib.h>

Matrix* createMatrix(int rows, int cols) {
    Matrix* mat = malloc(sizeof(Matrix));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        mat->data[i] = calloc(cols, sizeof(int));
    }
    return mat;
}

void freeMatrix(Matrix* mat) {
    for (int i = 0; i < mat->rows; i++) {
        free(mat->data[i]);
    }
    free(mat->data);
    free(mat);
}

void set(Matrix* mat, int i, int j, int value) {
    mat->data[i][j] = value;
}

int get(const Matrix* mat, int i, int j) {
    return mat->data[i][j];
}

void printMatrix(const Matrix* mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i][j]);
        }
        printf("\n");
    }
}

Matrix* transpose(const Matrix* mat) {
    Matrix* result = createMatrix(mat->cols, mat->rows);
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            result->data[j][i] = mat->data[i][j];
        }
    }
    return result;
}

Matrix* add(const Matrix* a, const Matrix* b) {
    Matrix* result = createMatrix(a->rows, a->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            result->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
    return result;
}

Matrix* scalarMultiply(const Matrix* mat, int scalar) {
    Matrix* result = createMatrix(mat->rows, mat->cols);
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            result->data[i][j] = scalar * mat->data[i][j];
        }
    }
    return result;
}

Matrix* multiply(const Matrix* a, const Matrix* b) {
    Matrix* result = createMatrix(a->rows, b->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            for (int k = 0; k < a->cols; k++) {
                result->data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }
    return result;
}
