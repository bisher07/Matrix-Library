#include "MatrixOps.h"
#include <iostream>
using namespace MatrixOps;

int main()
{
    Matrix<double> a(2, 2);
    a(0, 0) = 4;
    a(0, 1) = 7;
    a(1, 0) = 2;
    a(1, 1) = 6;
    a = multiply(a, inverse(a));
    a.print();
    std::cout << "\n\n";
    // det = 10, inverse should be: 0.6  -0.7 / -0.2  0.4

    Matrix<double> b(3, 3);
    b(0, 0) = 1;
    b(0, 1) = 2;
    b(0, 2) = 3;
    b(1, 0) = 0;
    b(1, 1) = 1;
    b(1, 2) = 4;
    b(2, 0) = 5;
    b(2, 1) = 6;
    b(2, 2) = 0;
    b = multiply(b, inverse(b));
    b.print();
    std::cout << "\n\n";
    // det = 1, verify by multiplying b * inverse(b) = identity

    Matrix<double> c(3, 3);
    c(0, 0) = 1;
    c(1, 1) = 1;
    c(2, 2) = 1;
    c = multiply(c, inverse(c));
    c.print();
    std::cout << "\n\n";
    // inverse(c) should equal c

    Matrix<double> d(2, 2);
    d(0, 0) = 1;
    d(0, 1) = 2;
    d(1, 0) = 2;
    d(1, 1) = 4;
    d = multiply(d, inverse(d));
    d.print();
    std::cout << "\n\n";
    // det = 0, should trigger exit(1)

    return 0;
}