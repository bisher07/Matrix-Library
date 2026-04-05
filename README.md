# Matrix Library

A lightweight C++ matrix library built from scratch using templates and the `MatrixOps` namespace pattern. Developed alongside a university linear algebra course to reinforce mathematical concepts through code.

## Features

- Generic matrix type via C++ templates (`int`, `float`, `double`)
- Element access via `operator()(row, col)`
- Arithmetic: addition, subtraction, scalar multiplication, matrix multiplication
- Transpose
- Row echelon form (with partial pivoting)
- Determinant
- Matrix inverse (Gauss-Jordan elimination)
- Matrix power (positive, zero, and negative exponents)
- Utility checks: `isSquare`, `isSymmetric`, `isIdentity`, `isSingular`

## Project Structure
```
MatrixLib/
├── src/
│   ├── Matrix.h        ← Matrix class (constructors, element access, print, utility checks)
│   ├── MatrixOps.h     ← All operations as free functions in MatrixOps namespace
│   └── main.cpp        ← Test driver
├── bin/                ← Compiled binary (ignored by git)
└── .vscode/
    └── tasks.json      ← VS Code build config
```

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
bool singular = isSingular(a);

std::cout << a.isSymmetric(); // utility checks on Matrix object
```

## Notes

- `scalarMultiply` requires the scalar to match the matrix element type (e.g. `Matrix<double>` requires a `double` scalar, use casting if needed: `(double)2`)
- `rowEchelon`, `det`, `inverse`, and `pow` with negative exponents require floating point types (`double` or `float`)
- Singular matrices (det = 0) will trigger `exit(1)` in `inverse` and negative `pow`
- Near-zero floating point values may appear in results due to standard IEEE 754 precision limits
- Matrices that are not invertible (singular) cannot be raised to a negative power and will trigger `exit(1)`