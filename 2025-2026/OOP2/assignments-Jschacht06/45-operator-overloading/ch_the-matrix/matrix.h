#pragma once

#include <string>

class Matrix {
    // attributen
private:
    int* data;      // Dynamische array
    int rows;
    int cols;
    int getIndex(int r, int c) const;
    Matrix scalarMultiplication(int scalar) const;

public:
    // Constructor
    Matrix(int* array, int rows, int cols);
    Matrix(const Matrix& other);

    // Destructor
    ~Matrix();

    //getters 
    std::string getString() const;
    int getElement(int r, int c) const;
    int getRows() const; 
    int getCols() const; 

    // operator overloading
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const; 
    Matrix operator*(int scalar) const;          

    friend Matrix operator*(int scalar, const Matrix& matrix);
};
