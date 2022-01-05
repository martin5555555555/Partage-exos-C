#include "matrix.h"
#include <iostream>
#include <vector> 
using namespace std;

vector<Matrix> euler_explicit(Matrix & T0, Matrix & t0, const double dt,const double t,Matrix & K1);
void write_vector(fstream &textfile, Matrix T1);
