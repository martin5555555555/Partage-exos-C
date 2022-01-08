#include "matrix_creuse.h"
#include "matrix.h"
#include <vector>
using namespace std;

vector<Matrix_creuse> lu_decomposition(const Matrix_creuse & matrix);
vector<double> resolution_L(const Matrix_creuse & L1, const vector<double> & h);
vector<double> resolution_U(const Matrix_creuse & U, const vector<double> & h);
vector<double> final_resolution(const Matrix_creuse & K1, const vector<double> & b);



