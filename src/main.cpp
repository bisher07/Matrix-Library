#include "MatrixOps.h"
#include <iostream>
using namespace MatrixOps;

int main()
{
    // Matrix A: general 3x3 (initializer list)
    Matrix<double> a = {{2, 1, 0},
                        {1, 3, 1},
                        {0, 1, 2}};

    std::cout << "=== Matrix A ===\n";
    std::cout << a;

    std::cout << "\n--- transpose(A) ---\n";
    std::cout << transpose(a);

    std::cout << "\n--- rowEchelon(A) ---\n";
    std::cout << rowEchelon(a);

    std::cout << "\n--- det(A) (expected: 8) ---\n";
    std::cout << det(a) << "\n";

    std::cout << "\n--- inverse(A) ---\n";
    std::cout << inverse(a);

    std::cout << "\n--- A * inverse(A) (expected: identity) ---\n";
    std::cout << (a * inverse(a));

    std::cout << "\n--- rank(A) (expected: 3) ---\n";
    std::cout << rank(a) << "\n";

    std::cout << "\n--- pow(A, 0) (expected: identity) ---\n";
    std::cout << pow(a, 0);

    std::cout << "\n--- pow(A, 2) (expected: A * A) ---\n";
    std::cout << pow(a, 2);

    std::cout << "\n--- pow(A, -1) (expected: inverse(A)) ---\n";
    std::cout << pow(a, -1);

    std::cout << "\n--- trace(A) (expected: 7) ---\n";
    std::cout << a.trace() << "\n";

    std::cout << "\n--- sum(A) (expected: 11) ---\n";
    std::cout << a.sum() << "\n";

    std::cout << "\n--- isSquare(A) (expected: 1) ---\n";
    std::cout << a.isSquare() << "\n";

    std::cout << "\n--- isSymmetric(A) (expected: 1) ---\n";
    std::cout << a.isSymmetric() << "\n";

    std::cout << "\n--- isIdentity(A) (expected: 0) ---\n";
    std::cout << a.isIdentity() << "\n";

    std::cout << "\n--- isSingular(A) (expected: 0) ---\n";
    std::cout << isSingular(a) << "\n";

    std::cout << "\n--- subMatrix(A, 0, 1, 0, 1) ---\n";
    std::cout << a.subMatrix(0, 1, 0, 1);

    // Matrix B: singular 3x3
    Matrix<double> b = {{1, 2, 3},
                        {2, 4, 6},
                        {0, 1, 2}};

    std::cout << "\n=== Matrix B (singular) ===\n";
    std::cout << b;

    std::cout << "\n--- det(B) (expected: 0) ---\n";
    std::cout << det(b) << "\n";

    std::cout << "\n--- rank(B) (expected: 2) ---\n";
    std::cout << rank(b) << "\n";

    std::cout << "\n--- isSingular(B) (expected: 1) ---\n";
    std::cout << isSingular(b) << "\n";

    // Matrix C: identity 3x3
    Matrix<double> c = {{1, 0, 0},
                        {0, 1, 0},
                        {0, 0, 1}};

    std::cout << "\n=== Matrix C (identity) ===\n";
    std::cout << c;

    std::cout << "\n--- isIdentity(C) (expected: 1) ---\n";
    std::cout << c.isIdentity() << "\n";

    std::cout << "\n--- isSymmetric(C) (expected: 1) ---\n";
    std::cout << c.isSymmetric() << "\n";

    std::cout << "\n--- trace(C) (expected: 3) ---\n";
    std::cout << c.trace() << "\n";

    // Matrix D: non-square 2x3
    Matrix<double> d = {{1, 2, 3},
                        {4, 5, 6}};

    std::cout << "\n=== Matrix D (2x3) ===\n";
    std::cout << d;

    std::cout << "\n--- transpose(D) ---\n";
    std::cout << transpose(d);

    std::cout << "\n--- rowEchelon(D) ---\n";
    std::cout << rowEchelon(d);

    std::cout << "\n--- rank(D) (expected: 2) ---\n";
    std::cout << rank(d) << "\n";

    std::cout << "\n--- sum(D) (expected: 21) ---\n";
    std::cout << d.sum() << "\n";

    // Arithmetic operators
    Matrix<double> e = {{1, 2},
                        {3, 4}};

    Matrix<double> f = {{5, 6},
                        {7, 8}};

    std::cout << "\n=== Arithmetic (E and F) ===\n";

    std::cout << "\n--- E + F ---\n";
    std::cout << (e + f);

    std::cout << "\n--- E - F ---\n";
    std::cout << (e - f);

    std::cout << "\n--- E * F ---\n";
    std::cout << (e * f);

    std::cout << "\n--- E * 2.0 ---\n";
    std::cout << (e * 2.0);

    std::cout << "\n--- 2.0 * E (scalar on left) ---\n";
    std::cout << (2.0 * e);

    std::cout << "\n--- E == E (expected: 1) ---\n";
    std::cout << (e == e) << "\n";

    std::cout << "\n--- E == F (expected: 0) ---\n";
    std::cout << (e == f) << "\n";

    std::cout << "\n--- E != F (expected: 1) ---\n";
    std::cout << (e != f) << "\n";

    std::cout << "\n--- E != E (expected: 0) ---\n";
    std::cout << (e != e) << "\n";

    // Concatenation
    std::cout << "\n=== Concatenation ===\n";

    std::cout << "\n--- E | F (horizontal) ---\n";
    std::cout << (e | f);

    std::cout << "\n--- E / F (vertical) ---\n";
    std::cout << (e / f);

    // fill
    Matrix<double> g(2, 2);
    g.fill(7.0);
    std::cout << "\n=== Matrix G (filled with 7) ===\n";
    std::cout << g;

    // Compound assignment operators
    Matrix<double> h = {{1, 2},
                        {3, 4}};

    Matrix<double> k = {{5, 6},
                        {7, 8}};

    std::cout << "\n=== Compound Assignment Operators (H and K) ===\n";

    std::cout << "\n--- H before += ---\n";
    std::cout << h;
    h += k;
    std::cout << "\n--- H += K (expected: E + F result) ---\n";
    std::cout << h;

    h = {{1, 2}, {3, 4}};
    h -= k;
    std::cout << "\n--- H -= K (expected: E - F result) ---\n";
    std::cout << h;

    h = {{1, 2}, {3, 4}};
    h *= k;
    std::cout << "\n--- H *= K (expected: E * F result) ---\n";
    std::cout << h;

    h = {{1, 2}, {3, 4}};
    h *= 2.0;
    std::cout << "\n--- H *= 2.0 (expected: E * 2.0 result) ---\n";
    std::cout << h;

    // at() bounds checked access
    std::cout << "\n=== at() bounds checked access ===\n";
    std::cout << "\n--- a.at(0,0) (expected: 2) ---\n";
    std::cout << a.at(0, 0) << "\n";
    a.at(0, 0) = 99.0;
    std::cout << "\n--- a.at(0,0) after write (expected: 99) ---\n";
    std::cout << a.at(0, 0) << "\n";
    a.at(0, 0) = 2.0; // reset

    // subMatrix
    std::cout << "\n=== subMatrix ===\n";
    std::cout << "\n--- a.subMatrix(0,1,0,1) (expected: top-left 2x2) ---\n";
    std::cout << a.subMatrix(0, 1, 0, 1);

    // Exception handling tests
    std::cout << "\n=== Exception Handling Tests ===\n";

    try
    {
        Matrix<double> x(2, 2);
        Matrix<double> y(3, 3);
        x + y;
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "Caught: " << e.what() << "\n";
    }

    try
    {
        Matrix<double> x = {{1, 2}, {2, 4}};
        inverse(x);
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "Caught: " << e.what() << "\n";
    }

    try
    {
        Matrix<double> x(2, 3);
        det(x);
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "Caught: " << e.what() << "\n";
    }

    try
    {
        Matrix<double> x(2, 2);
        x.at(5, 5);
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "Caught: " << e.what() << "\n";
    }

    try
    {
        Matrix<double> x = {{1, 2}, {2, 4}};
        pow(x, -2);
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "Caught: " << e.what() << "\n";
    }

    try
    {
        Matrix<double> x = {{1, 2, 3}, {4, 5, 6}};
        Matrix<double> y = {{1, 2}, {3, 4}, {5, 6}};
        x | y;
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "Caught: " << e.what() << "\n";
    }

    try
    {
        Matrix<double> x = {{1, 2}, {3, 4}};
        Matrix<double> y = {{1, 2, 3}, {4, 5, 6}};
        x / y;
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "Caught: " << e.what() << "\n";
    }

    try
    {
        Matrix<double> x(0, 2);
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "Caught: " << e.what() << "\n";
    }

    return 0;
}