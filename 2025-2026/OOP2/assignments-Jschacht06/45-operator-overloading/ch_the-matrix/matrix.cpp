#include "Matrix.h"
#include <iostream>
#include <sstream>

// Constructors
Matrix::Matrix(int *array, int rows, int cols) : rows(rows), cols(cols)
{

    int size = rows * cols;
    data = new int[size];

    for (int i = 0; i < size; i++)
    {
        data[i] = array[i];
    }
}

Matrix::Matrix(const Matrix &other) : rows(other.rows), cols(other.cols)
{
    int size = rows * cols;
    data = new int[size];
    for (int i = 0; i < size; i++)
    {
        data[i] = other.data[i];
    }
}

// destructor
Matrix::~Matrix()
{
    delete[] data;
}

int Matrix::getIndex(int r, int c) const
{
    return r * cols + c;
}

int Matrix::getElement(int r, int c) const
{
    return data[getIndex(r, c)];
}

int Matrix::getRows() const { return rows; }
int Matrix::getCols() const { return cols; }

std::string Matrix::getString() const
{
    std::stringstream ss;
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            ss << data[getIndex(r, c)];

            if (c < cols - 1)
            {
                ss << " ";
            }
        }

        if (r < rows - 1)
        {
            ss << "\n";
        }
    }
    return ss.str();
}

Matrix Matrix::scalarMultiplication(int scalar) const
{
    Matrix result(data, rows, cols);

    int size = rows * cols;
    for (int i = 0; i < size; i++)
    {
        result.data[i] = this->data[i] * scalar;
    }
    return result;
}

Matrix Matrix::operator+(const Matrix &other) const
{
    Matrix result(data, rows, cols);

    int size = rows * cols;
    for (int i = 0; i < size; i++)
    {
        result.data[i] = this->data[i] + other.data[i];
    }
    return result;
}

Matrix Matrix::operator-(const Matrix &other) const
{
    Matrix result(data, rows, cols);

    int size = rows * cols;
    for (int i = 0; i < size; i++)
    {
        result.data[i] = this->data[i] - other.data[i];
    }
    return result;
}

Matrix Matrix::operator*(int scalar) const
{
    return scalarMultiplication(scalar);
}

Matrix operator*(int scalar, const Matrix &matrix)
{
    return matrix.scalarMultiplication(scalar);
}
Matrix Matrix::operator*(const Matrix &other) const
{

    int newRows = this->rows;
    int newCols = other.cols;

    int *tempArr = new int[newRows * newCols];

    for (int i = 0; i < newRows * newCols; i++)
        tempArr[i] = 0;

    for (int r = 0; r < newRows; r++)
    {
        for (int c = 0; c < newCols; c++)
        {
            int sum = 0;
            for (int k = 0; k < this->cols; k++)
            {
                sum += this->getElement(r, k) * other.getElement(k, c);
            }
            tempArr[r * newCols + c] = sum;
        }
    }

    Matrix result(tempArr, newRows, newCols);

    delete[] tempArr;

    return result;
}