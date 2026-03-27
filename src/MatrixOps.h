#pragma once
#include "Matrix.h"

namespace MatrixOps
{
    template <typename T>
    Matrix<T> add(const Matrix<T> &a, const Matrix<T> &b)
    {
        if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
            exit(1);

        int rows = a.getRows(), cols = a.getCols();
        Matrix<T> sum_Matrix(rows, cols);

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                sum_Matrix(row, col) = a(row, col) + b(row, col);
            }
        }

        return sum_Matrix;
    }

    template <typename T>
    Matrix<T> subtract(const Matrix<T> &a, const Matrix<T> &b)
    {
        if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
            exit(1);

        int rows = a.getRows(), cols = a.getCols();
        Matrix<T> sub_Matrix(rows, cols);

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                sub_Matrix(row, col) = a(row, col) - b(row, col);
            }
        }

        return sub_Matrix;
    }

    template <typename T>
    Matrix<T> scalarMultiply(const Matrix<T> &a, T scalar) // Note that scalar must have the same data type as the matrix elements.
    {
        int rows = a.getRows(), cols = a.getCols();
        Matrix<T> scaled_Matrix(rows, cols);

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                scaled_Matrix(row, col) = a(row, col) * scalar;
            }
        }

        return scaled_Matrix;
    }

    template <typename T>
    Matrix<T> transpose(const Matrix<T> &a)
    {
        int rows = a.getCols(), cols = a.getRows();
        Matrix<T> transposed_Matrix(rows, cols);

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                transposed_Matrix(row, col) = a(col, row);
            }
        }

        return transposed_Matrix;
    }

    template <typename T>
    Matrix<T> multiply(const Matrix<T> &a, const Matrix<T> &b)
    {
        if (a.getCols() != b.getRows())
            exit(1);

        int rows = a.getRows(), cols = b.getCols();
        Matrix<T> Product_Matrix(rows, cols, 0);

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                for (int i = 0; i < a.getCols(); i++)
                {
                    Product_Matrix(row, col) += (a(row, i) * b(i, col));
                }
            }
        }

        return Product_Matrix;
    }

    Matrix<double> rowEchelon(const Matrix<double> &a)
    {
        if (a.getRows() != a.getCols())
            exit(1);

        int rows = a.getRows(), cols = a.getCols();
        Matrix<double> reduced_Matrix(rows, cols);

        // Copy a into reduced_Matrix.
        for (int row = 0; row < rows; row++)
            for (int col = 0; col < cols; col++)
                reduced_Matrix(row, col) = a(row, col);

        for (int row = 0; row < rows; row++)
        {
            double pivot = reduced_Matrix(row, row);

            if (pivot == 0)
            {
                // skip this row, pivot is already 0
                continue;
            }

            for (int col = row; col < cols; col++)
            {
                reduced_Matrix(row, col) /= pivot;
            }

            for (int j = row + 1; j < rows; j++)
            {
                double factor = reduced_Matrix(j, row);
                for (int col = row; col < cols; col++)
                {
                    reduced_Matrix(j, col) += reduced_Matrix(row, col) * -1 * factor;
                }
            }
        }

        return reduced_Matrix;
    }
}
