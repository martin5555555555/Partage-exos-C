#include "matrix.h"
#include <iostream>
#include <vector>
using namespace std;

vector<Matrix> lu_decomposition(const Matrix & mat);
Matrix resolution_L(const Matrix & L, const Matrix & h);
Matrix resolution_U(const Matrix & U, const Matrix & h);
Matrix final_resolution(const Matrix & K1, const Matrix & b );

    