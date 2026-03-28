#include "MatrixOps.h"
#include <iostream>
using namespace MatrixOps;

int main()
{
    Matrix<int> a(3, 3);

    a(0, 0) = 0;
    a(0, 1) = 1;
    a(0, 2) = 2;

    a(1, 0) = 0;
    a(1, 1) = 0;
    a(1, 2) = 3;

    a(2, 0) = 1;
    a(2, 1) = 4;
    a(2, 2) = 5;

    Matrix<double> b(3, 3);
    b = rowEchelon(a);
    a.print();
    std::cout << std::endl;
    b.print();

    return 0;
}