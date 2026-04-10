#pragma once
#include <iostream>
#include <vector>
#include <iomanip>

template <typename T>
class Matrix
{
public:
    Matrix(int rows, int cols) : matrix_Rows(rows), matrix_Cols(cols), matrix_Data(rows, std::vector<T>(cols, 0)) {}
    Matrix(int rows, int cols, T value) : matrix_Rows(rows), matrix_Cols(cols), matrix_Data(rows, std::vector<T>(cols, value)) {}

    // for writing: a(0,1) = 5.0;
    T &operator()(int r, int c)
    {
        return matrix_Data[r][c];
    }

    // for reading inside const methods like print()
    const T &operator()(int r, int c) const
    {
        return matrix_Data[r][c];
    }

    bool operator==(const Matrix<T> &a) const
    {
        if (a.getRows() != matrix_Rows || a.getCols() != matrix_Cols)
            return false;

        for (int row = 0; row < matrix_Rows; row++)
            for (int col = 0; col < matrix_Cols; col++)
                if (a(row, col) != matrix_Data[row][col])
                    return false;

        return true;
    }

    Matrix<T> &operator+=(const Matrix<T> &a)
    {
        if (matrix_Rows != a.getRows() || matrix_Cols != a.getCols())
            exit(1);

        for (int row = 0; row < matrix_Rows; row++)
            for (int col = 0; col < matrix_Cols; col++)
                matrix_Data[row][col] += a(row, col);

        return *this;
    }

    Matrix<T> &operator-=(const Matrix<T> &a)
    {
        if (matrix_Rows != a.getRows() || matrix_Cols != a.getCols())
            exit(1);

        for (int row = 0; row < matrix_Rows; row++)
            for (int col = 0; col < matrix_Cols; col++)
                matrix_Data[row][col] -= a(row, col);

        return *this;
    }

    Matrix<T> &operator*=(const Matrix<T> &a)
    {
        if (matrix_Cols != a.getRows())
            exit(1);

        *this = *this * a;

        return *this;
    }

    Matrix<T> &operator*=(T scalar)
    {
        *this = *this * scalar;

        return *this;
    }

    Matrix<T> operator*(const Matrix<T> &a)
    {
        if (matrix_Cols != a.getRows())
            exit(1);

        int rows = matrix_Rows, cols = a.getCols();
        Matrix<T> Product_Matrix(rows, cols, 0);

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                for (int i = 0; i < matrix_Cols; i++)
                {
                    Product_Matrix(row, col) += (matrix_Data[row][i] * a(i, col));
                }
            }
        }

        return Product_Matrix;
    }

    Matrix<T> operator*(T scalar)
    {
        Matrix<T> scaled_Matrix(matrix_Rows, matrix_Cols);

        for (int row = 0; row < matrix_Rows; row++)
        {
            for (int col = 0; col < matrix_Cols; col++)
            {
                scaled_Matrix(row, col) = matrix_Data[row][col] * scalar;
            }
        }

        return scaled_Matrix;
    }

    Matrix<T> operator+(const Matrix<T> &a)
    {
        if (matrix_Rows != a.getRows() || matrix_Cols != a.getCols())
            exit(1);

        Matrix<T> sum_Matrix(matrix_Rows, matrix_Cols);

        for (int row = 0; row < matrix_Rows; row++)
        {
            for (int col = 0; col < matrix_Cols; col++)
            {
                sum_Matrix(row, col) = matrix_Data[row][col] + a(row, col);
            }
        }

        return sum_Matrix;
    }

    Matrix<T> operator-(const Matrix<T> &a)
    {
        if (matrix_Rows != a.getRows() || matrix_Cols != a.getCols())
            exit(1);

        Matrix<T> sub_Matrix(matrix_Rows, matrix_Cols);

        for (int row = 0; row < matrix_Rows; row++)
        {
            for (int col = 0; col < matrix_Cols; col++)
            {
                sub_Matrix(row, col) = matrix_Data[row][col] - a(row, col);
            }
        }

        return sub_Matrix;
    }

    int getRows() const
    {
        return matrix_Rows;
    }

    int getCols() const
    {
        return matrix_Cols;
    }

    bool isSquare() const
    {
        return matrix_Rows == matrix_Cols;
    }
    bool isSymmetric() const
    {
        if (!isSquare())
            return false;

        for (int row = 1; row < matrix_Rows; row++)
            for (int col = 0; col < row; col++)
                if (matrix_Data[row][col] != matrix_Data[col][row])
                    return false;

        return true;
    }
    bool isIdentity() const
    {
        if (!isSquare())
            return false;

        for (int row = 0; row < matrix_Rows; row++)
            for (int col = 0; col < matrix_Cols; col++)
                if (row != col && matrix_Data[row][col] != 0)
                    return false;

        for (int row = 0; row < matrix_Rows; row++)
            if (matrix_Data[row][row] != 1)
                return false;

        return true;
    }

    T trace() const
    {
        T sum = 0;

        if (!isSquare())
            exit(1);

        for (int row = 0; row < matrix_Rows; row++)
            sum += matrix_Data[row][row];

        return sum;
    }

    void fill(T value)
    {
        for (int row = 0; row < matrix_Rows; row++)
            for (int col = 0; col < matrix_Cols; col++)
                matrix_Data[row][col] = value;
    }

    void print() const
    {
        for (int row = 0; row < matrix_Rows; row++)
        {
            for (int col = 0; col < matrix_Cols; col++)
            {
                std::cout << std::setw(8) << matrix_Data[row][col];
            }

            std::cout << std::endl;
        }
    }

private:
    std::vector<std::vector<T>> matrix_Data;

    int matrix_Rows, matrix_Cols;
};