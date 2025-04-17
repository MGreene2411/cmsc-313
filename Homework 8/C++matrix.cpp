#include "C++matrix.h"
#include <iostream>

Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    data = new int*[rows];
    for(int i = 0; i < rows; i++)
        data[i] = new int[cols]{};
}

Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
    data = new int*[rows];
    for(int i = 0; i < rows; i++) {
        data[i] = new int[cols];
        for(int j = 0; j < cols; j++)
            data[i][j] = other.data[i][j];
    }
}

Matrix::~Matrix() {
    for(int i = 0; i < rows; i++)
        delete[] data[i];
    delete[] data;
}

void Matrix::set(int i, int j, int value) {
    data[i][j] = value;
}

int Matrix::get(int i, int j) const {
    return data[i][j];
}

void Matrix::print() const {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++)
            std::cout << data[i][j] << " ";
        std::cout << std::endl;
    }
}

Matrix Matrix::transpose() const {
    Matrix result(cols, rows);
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            result.set(j, i, data[i][j]);
    return result;
}

Matrix Matrix::operator+(const Matrix& other) const {
    Matrix result(rows, cols);
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            result.set(i, j, data[i][j] + other.data[i][j]);
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    Matrix result(rows, other.cols);
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < other.cols; j++)
            for(int k = 0; k < cols; k++)
                result.data[i][j] += data[i][k] * other.data[k][j];
    return result;
}

Matrix Matrix::operator*(int scalar) const {
    Matrix result(rows, cols);
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            result.set(i, j, data[i][j] * scalar);
    return result;
}
