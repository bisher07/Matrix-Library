# Matrix Library

A lightweight C++ matrix library built from scratch using templates and the `MatrixOps` namespace pattern. Developed alongside a university linear algebra course to reinforce mathematical concepts through code.

## Features

- Generic matrix type via C++ templates (`int`, `float`, `double`)
- Element access via `operator()(row, col)` and bounds-checked `at(row, col)`
- Arithmetic operators: `+`, `-`, `*` (matrix and scalar), `==`
- Compound assignment operators: `+=`, `-=`, `*=` (matrix and scalar)
- Transpose
- Row echelon form (with partial pivoting)
- Determinant
- Matrix inverse (Gauss-Jordan elimination)
- Matrix power (positive, zero, and negative exponents)
- Utility checks: `isSquare`, `isSymmetric`, `isIdentity`, `isSingular`
- `trace()` — sum of diagonal elements
- `fill(value)` — fill entire matrix with a value
- `rank()` — number of linearly independent rows

## Project Structure

    MatrixLib/
    ├── src/
    │   ├── Matrix.h        ← Matrix class (constructors, element access, print, utility checks)
    │   ├── MatrixOps.h     ← All operations as free functions in MatrixOps namespace
    │   └── main.cpp        ← Test driver
    ├── bin/                ← Compiled binary (ignored by git)
    └── .vscode/
        └── tasks.json      ← VS Code build config

## Building

Requires g++ with C++17 support (MinGW on Windows).

Press `Ctrl+Shift+B` in VS Code to build, or run manually:
```bash
g++ -std=c++17 src/main.cpp -o bin/main.exe
```

## Usage
```cpp
#include "MatrixOps.h"
using namespace MatrixOps;

Matrix<double> a(3, 3);
a(0,0)=2; a(0,1)=1; a(0,2)=0;
a(1,0)=1; a(1,1)=3; a(1,2)=1;
a(2,0)=0; a(2,1)=1; a(2,2)=2;

Matrix<double> inv = inverse(a);
double d = det(a);
Matrix<double> ref = rowEchelon(a);
Matrix<double> squared = pow(a, 2);
Matrix<double> product = a * a;
Matrix<double> scaled = a * 2.0;
bool singular = isSingular(a);
double t = trace(a);
int r = rank(a);

a.at(0,0) = 5.0;         // bounds-checked write
double x = a.at(0,0);    // bounds-checked read
a.fill(0.0);
std::cout << a.isSymmetric();  // utility checks on Matrix object
std::cout << (a == b);         // equality check
```

## Notes

- `operator()` provides unchecked element access for performance; use `at()` for safe bounds-checked access
- Arithmetic operators (`+`, `-`, `*`) throw `std::invalid_argument` if dimensions don't match
- Scalar multiplication requires the scalar to match the matrix element type — use casting if needed: `a * (double)2`
- `rowEchelon`, `det`, `inverse`, and `pow` with negative exponents require floating point types (`double` or `float`)
- `inverse()` and negative `pow()` throw `std::invalid_argument` if the matrix is singular
- `trace()` throws `std::invalid_argument` if the matrix is not square
- `at()` throws `std::out_of_range` if the index is out of bounds
- `rank()` works on any matrix including non-square
- Near-zero floating point values may appear in results due to standard IEEE 754 precision limits