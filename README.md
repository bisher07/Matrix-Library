# Matrix Library

A lightweight C++ matrix library built from scratch using templates and the `MatrixOps` namespace pattern. Developed alongside a university linear algebra course to reinforce mathematical concepts through code.

## Features

- Generic matrix type via C++ templates (`int`, `float`, `double`)
- Initializer list constructor: `Matrix<double> a = {{1,2},{3,4}}`
- Element access via `operator()(row, col)` and bounds-checked `at(row, col)`
- Arithmetic operators: `+`, `-`, `*` (matrix and scalar), `==`, `!=`
- Compound assignment operators: `+=`, `-=`, `*=` (matrix and scalar)
- Transpose
- Row echelon form (with partial pivoting)
- Determinant
- Matrix inverse (Gauss-Jordan elimination)
- Matrix power (positive, zero, and negative exponents)
- Matrix concatenation: `|` (horizontal) and `/` (vertical)
- Utility checks: `isSquare`, `isSymmetric`, `isIdentity`, `isSingular`
- `trace()` — sum of diagonal elements
- `sum()` — sum of all elements
- `fill(value)` — fill entire matrix with a value
- `subMatrix(startRow, endRow, startCol, endCol)` — extract a submatrix
- `rank()` — number of linearly independent rows

## Project Structure

    MatrixLib/
    ├── src/
    │   ├── Matrix.h        ← Matrix class (constructors, element access, utility checks)
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

// initializer list construction
Matrix<double> a = {{2, 1, 0},
                    {1, 3, 1},
                    {0, 1, 2}};

Matrix<double> inv = inverse(a);
double d = det(a);
Matrix<double> ref = rowEchelon(a);
Matrix<double> squared = pow(a, 2);
Matrix<double> product = a * a;
Matrix<double> scaled = a * 2.0;
Matrix<double> scaled2 = 2.0 * a;
bool singular = isSingular(a);
double t = trace(a);
double s = a.sum();
int r = rank(a);

Matrix<double> sub = a.subMatrix(0, 1, 0, 1); // extract 2x2 top-left
Matrix<double> combined = a | a;               // horizontal concatenation
Matrix<double> stacked = a / a;                // vertical concatenation

a.at(0,0) = 5.0;              // bounds-checked write
double x = a.at(0,0);         // bounds-checked read
a.fill(0.0);
std::cout << a.isSymmetric();  // utility checks on Matrix object
std::cout << (a == b);         // equality check
std::cout << (a != b);         // inequality check
std::cout << a;                // print via operator
```

## Notes

- `operator()` provides unchecked element access for performance; use `at()` for safe bounds-checked access
- Arithmetic operators (`+`, `-`, `*`) throw `std::invalid_argument` if dimensions don't match
- Scalar multiplication requires the scalar to match the matrix element type — use casting if needed: `a * (double)2`
- `rowEchelon`, `det`, `inverse`, and `pow` with negative exponents require floating point types (`double` or `float`)
- `inverse()` and negative `pow()` throw `std::invalid_argument` if the matrix is singular
- `trace()` throws `std::invalid_argument` if the matrix is not square
- `at()` throws `std::out_of_range` if the index is out of bounds
- `|` throws `std::invalid_argument` if row counts don't match
- `/` throws `std::invalid_argument` if column counts don't match
- `rank()` works on any matrix including non-square
- Near-zero floating point values may appear in results due to standard IEEE 754 precision limits