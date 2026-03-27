#include "MatrixOps.h"
#include <iostream>
using namespace MatrixOps;

int main()
{
    Matrix<double> a(3, 3);

    a(0, 0) = 1;
    a(0, 1) = 2;
    a(0, 2) = 1;

    a(1, 0) = 2;
    a(1, 1) = 4;
    a(1, 2) = 0;

    a(2, 0) = 3;
    a(2, 1) = 6;
    a(2, 2) = 3;

    Matrix<double> b(3, 3);
    b = rowEchelon(a);
    b.print();

    return 0;
}