#include "MatrixOps.h"
#include <iostream>
using namespace MatrixOps;

int main()
{
    // Matrix A: general 3x3
    Matrix<double> a(3, 3);
    a(0, 0) = 2;
    a(0, 1) = 1;
    a(0, 2) = 0;
    a(1, 0) = 1;
    a(1, 1) = 3;
    a(1, 2) = 1;
    a(2, 0) = 0;
    a(2, 1) = 1;
    a(2, 2) = 2;

    std::cout << "=== Matrix A ===\n";
    a.print();

    std::cout << "\n--- transpose(A) ---\n";
    transpose(a).print();

    std::cout << "\n--- rowEchelon(A) ---\n";
    rowEchelon(a).print();

    std::cout << "\n--- det(A) (expected: 8) ---\n";
    std::cout << det(a) << "\n";

    std::cout << "\n--- inverse(A) ---\n";
    inverse(a).print();

    std::cout << "\n--- A * inverse(A) (expected: identity) ---\n";
    (a * inverse(a)).print();

    std::cout << "\n--- rank(A) (expected: 3) ---\n";
    std::cout << rank(a) << "\n";

    std::cout << "\n--- pow(A, 0) (expected: identity) ---\n";
    pow(a, 0).print();

    std::cout << "\n--- pow(A, 2) (expected: A * A) ---\n";
    pow(a, 2).print();

    std::cout << "\n--- pow(A, -1) (expected: inverse(A)) ---\n";
    pow(a, -1).print();

    std::cout << "\n--- trace(A) (expected: 7) ---\n";
    std::cout << a.trace() << "\n";

    std::cout << "\n--- isSquare(A) (expected: 1) ---\n";
    std::cout << a.isSquare() << "\n";

    std::cout << "\n--- isSymmetric(A) (expected: 1) ---\n";
    std::cout << a.isSymmetric() << "\n";

    std::cout << "\n--- isIdentity(A) (expected: 0) ---\n";
    std::cout << a.isIdentity() << "\n";

    std::cout << "\n--- isSingular(A) (expected: 0) ---\n";
    std::cout << isSingular(a) << "\n";

    // Matrix B: singular 3x3
    Matrix<double> b(3, 3);
    b(0, 0) = 1;
    b(0, 1) = 2;
    b(0, 2) = 3;
    b(1, 0) = 2;
    b(1, 1) = 4;
    b(1, 2) = 6;
    b(2, 0) = 0;
    b(2, 1) = 1;
    b(2, 2) = 2;

    std::cout << "\n=== Matrix B (singular) ===\n";
    b.print();

    std::cout << "\n--- det(B) (expected: 0) ---\n";
    std::cout << det(b) << "\n";

    std::cout << "\n--- rank(B) (expected: 2) ---\n";
    std::cout << rank(b) << "\n";

    std::cout << "\n--- isSingular(B) (expected: 1) ---\n";
    std::cout << isSingular(b) << "\n";

    // Matrix C: identity 3x3
    Matrix<double> c(3, 3);
    c(0, 0) = 1;
    c(1, 1) = 1;
    c(2, 2) = 1;

    std::cout << "\n=== Matrix C (identity) ===\n";
    c.print();

    std::cout << "\n--- isIdentity(C) (expected: 1) ---\n";
    std::cout << c.isIdentity() << "\n";

    std::cout << "\n--- isSymmetric(C) (expected: 1) ---\n";
    std::cout << c.isSymmetric() << "\n";

    std::cout << "\n--- trace(C) (expected: 3) ---\n";
    std::cout << c.trace() << "\n";

    // Matrix D: non-square 2x3
    Matrix<double> d(2, 3);
    d(0, 0) = 1;
    d(0, 1) = 2;
    d(0, 2) = 3;
    d(1, 0) = 4;
    d(1, 1) = 5;
    d(1, 2) = 6;

    std::cout << "\n=== Matrix D (2x3) ===\n";
    d.print();

    std::cout << "\n--- transpose(D) ---\n";
    transpose(d).print();

    std::cout << "\n--- rowEchelon(D) ---\n";
    rowEchelon(d).print();

    std::cout << "\n--- rank(D) (expected: 2) ---\n";
    std::cout << rank(d) << "\n";

    // Arithmetic operators
    Matrix<double> e(2, 2);
    e(0, 0) = 1;
    e(0, 1) = 2;
    e(1, 0) = 3;
    e(1, 1) = 4;

    Matrix<double> f(2, 2);
    f(0, 0) = 5;
    f(0, 1) = 6;
    f(1, 0) = 7;
    f(1, 1) = 8;

    std::cout << "\n=== Arithmetic (E and F) ===\n";

    std::cout << "\n--- E + F ---\n";
    (e + f).print();

    std::cout << "\n--- E - F ---\n";
    (e - f).print();

    std::cout << "\n--- E * F ---\n";
    (e * f).print();

    std::cout << "\n--- E * 2.0 ---\n";
    (e * 2.0).print();

    std::cout << "\n--- E == E (expected: 1) ---\n";
    std::cout << (e == e) << "\n";

    std::cout << "\n--- E == F (expected: 0) ---\n";
    std::cout << (e == f) << "\n";

    // fill
    Matrix<double> g(2, 2);
    g.fill(7.0);
    std::cout << "\n=== Matrix G (filled with 7) ===\n";
    g.print();

    // Compound assignment operators
    Matrix<double> h(2, 2);
    h(0, 0) = 1;
    h(0, 1) = 2;
    h(1, 0) = 3;
    h(1, 1) = 4;

    Matrix<double> k(2, 2);
    k(0, 0) = 5;
    k(0, 1) = 6;
    k(1, 0) = 7;
    k(1, 1) = 8;

    std::cout << "\n=== Compound Assignment Operators (H and K) ===\n";

    std::cout << "\n--- H before +=  ---\n";
    h.print();
    h += k;
    std::cout << "\n--- H += K (expected: E + F result) ---\n";
    h.print();

    // reset h
    h(0, 0) = 1;
    h(0, 1) = 2;
    h(1, 0) = 3;
    h(1, 1) = 4;

    h -= k;
    std::cout << "\n--- H -= K (expected: E - F result) ---\n";
    h.print();

    // reset h
    h(0, 0) = 1;
    h(0, 1) = 2;
    h(1, 0) = 3;
    h(1, 1) = 4;

    h *= k;
    std::cout << "\n--- H *= K (expected: E * F result) ---\n";
    h.print();

    // reset h
    h(0, 0) = 1;
    h(0, 1) = 2;
    h(1, 0) = 3;
    h(1, 1) = 4;

    h *= 2.0;
    std::cout << "\n--- H *= 2.0 (expected: E * 2.0 result) ---\n";
    h.print();

    return 0;
}