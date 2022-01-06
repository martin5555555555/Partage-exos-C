#pragma once
#include "matrix.h"
#include <iostream>
#include <vector> 
using namespace std;

vector<Matrix> euler_explicit_resolution(const Matrix & T0, const double  t0, const double dt,const double t,const Matrix & K1);
