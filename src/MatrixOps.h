#pragma once
#include "Matrix.h"
#include <cmath>

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

    template <typename T>
    Matrix<double> rowEchelon(const Matrix<T> &a)
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
            int maxRow = row;
            for (int i = row + 1; i < rows; i++)
                if (abs(reduced_Matrix(i, row)) > abs(reduced_Matrix(maxRow, row)))
                    maxRow = i;

            // swap
            if (maxRow != row)
                for (int col = 0; col < cols; col++)
                    std::swap(reduced_Matrix(row, col), reduced_Matrix(maxRow, col));

            double pivot = reduced_Matrix(row, row);

            if (pivot == 0)
                continue;

            for (int j = row + 1; j < rows; j++)
            {
                double factor = reduced_Matrix(j, row) / pivot;
                for (int col = row; col < cols; col++)
                    reduced_Matrix(j, col) -= factor * reduced_Matrix(row, col);
            }
        }

        return reduced_Matrix;
    }

    template <typename T>
    double det(const Matrix<T> &a)
    {
        if (a.getRows() != a.getCols())
            exit(1);

        int rows = a.getRows(), cols = a.getCols(), counter = 0;
        Matrix<double> reduced_Matrix(rows, cols);

        // Copy a into reduced_Matrix.
        for (int row = 0; row < rows; row++)
            for (int col = 0; col < cols; col++)
                reduced_Matrix(row, col) = a(row, col);

        for (int row = 0; row < rows; row++)
        {
            int maxRow = row;
            for (int i = row + 1; i < rows; i++)
                if (abs(reduced_Matrix(i, row)) > abs(reduced_Matrix(maxRow, row)))
                    maxRow = i;

            // swap
            if (maxRow != row)
            {
                for (int col = 0; col < cols; col++)
                    std::swap(reduced_Matrix(row, col), reduced_Matrix(maxRow, col));
                counter++;
            }

            double pivot = reduced_Matrix(row, row);

            if (pivot == 0)
                continue;

            for (int j = row + 1; j < rows; j++)
            {
                double factor = reduced_Matrix(j, row) / pivot;
                for (int col = row; col < cols; col++)
                    reduced_Matrix(j, col) -= factor * reduced_Matrix(row, col);
            }
        }

        double det = 1;
        for (int row = 0; row < rows; row++)
        {
            det *= reduced_Matrix(row, row);
        }

        if (counter % 2 != 0)
            det *= -1;

        return det;
    }
}
