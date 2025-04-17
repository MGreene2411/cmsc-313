#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
private:
    int rows;
    int cols;
    int** data;

public:
    Matrix(int r, int c);
    Matrix(const Matrix& other); // Copy constructor
    ~Matrix();                   // Destructor

    void set(int i, int j, int value);
    int get(int i, int j) const;
    void print() const;

    Matrix transpose() const;
    Matrix operator+(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    Matrix operator*(int scalar) const;
};

#endif

