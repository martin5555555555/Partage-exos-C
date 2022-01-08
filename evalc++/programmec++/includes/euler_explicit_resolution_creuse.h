#pragma once
#include "matrix_creuse.h"
#include <iostream>
#include <vector> 
using namespace std;

vector<vector<double>> euler_explicit_resolution(const vector<double> & T0, const double  t0, const double dt,const double t,const Matrix_creuse & K1);
