#include "MatrixOps.h"
#include <iostream>
using namespace MatrixOps;

int main()
{
    Matrix<int> a(3, 3);
    Matrix<double> b(3, 3);
    double deter;

    a(0, 0) = 0;
    a(0, 1) = 1;
    a(0, 2) = 2;

    a(1, 0) = 1;
    a(1, 1) = 4;
    a(1, 2) = 5;

    a(2, 0) = 0;
    a(2, 1) = 0;
    a(2, 2) = 3;

    b = rowEchelon(a);
    deter = det(a);

    a.print();
    std::cout << std::endl;
    b.print();
    std::cout << std::endl;
    std::cout << deter << std::endl
              << std::endl;

    a(0, 0) = 1;
    a(0, 1) = 2;
    a(0, 2) = 3;

    a(1, 0) = 2;
    a(1, 1) = 4;
    a(1, 2) = 6;

    a(2, 0) = 7;
    a(2, 1) = 8;
    a(2, 2) = 9;

    b = rowEchelon(a);
    deter = det(a);

    a.print();
    std::cout << std::endl;
    b.print();
    std::cout << std::endl;
    std::cout << deter << std::endl
              << std::endl;

    a(0, 0) = 0;
    a(0, 1) = 2;
    a(0, 2) = 1;

    a(1, 0) = 3;
    a(1, 1) = 0;
    a(1, 2) = 5;

    a(2, 0) = 6;
    a(2, 1) = 1;
    a(2, 2) = 2;

    b = rowEchelon(a);
    deter = det(a);

    a.print();
    std::cout << std::endl;
    b.print();
    std::cout << std::endl;
    std::cout << deter << std::endl
              << std::endl;

    a(0, 0) = 2;
    a(0, 1) = 3;
    a(0, 2) = 1;

    a(1, 0) = 0;
    a(1, 1) = 5;
    a(1, 2) = 4;

    a(2, 0) = 0;
    a(2, 1) = 0;
    a(2, 2) = 7;

    b = rowEchelon(a);
    deter = det(a);

    a.print();
    std::cout << std::endl;
    b.print();
    std::cout << std::endl;
    std::cout << deter << std::endl
              << std::endl;

    return 0;
}