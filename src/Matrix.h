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