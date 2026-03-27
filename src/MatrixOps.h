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

}
