#pragma once
#include <iostream>
#include <vector>
#include "matrix.h"
using namespace std;

class Matrix_creuse 
{
    public :
        int size;
        vector<double> diago_up;
        vector<double> diago;
        vector<double> diago_down;

    public:
    Matrix_creuse(const int N);
    Matrix_creuse( const Matrix & matrix);
    Matrix_creuse(const Matrix_creuse & matrix);
    ~Matrix_creuse();

    public:
    static Matrix_creuse init_K_stationnaire(const int N, const double delta_x) ;
    static Matrix_creuse create_id(const int n);
    static vector<double> init_random_D(const int N);
    static Matrix_creuse init_K_variable(const int N);
    static vector<double> init_T0(const int N, const double delta_x);

    double* get(const int i, const int j) const;
    double* operator ()(const int i, const int j) const;
    Matrix_creuse summ(const Matrix_creuse& matrix) const;
    Matrix_creuse operator+(const Matrix_creuse& matrix_2) const ;
    vector<double> mult_vect(const vector<double> & T) const;
    vector<double> operator*(const vector<double> & T) const;
    Matrix_creuse operator*(const Matrix_creuse& matrix_2) const;
    Matrix_creuse mult_scal(const double lambda) const ;
    Matrix_creuse operator*(const double lambda) const;
    static vector<double> mult_vect_scal(const vector<double> & T, double t);
    static vector<double> add_vect_vect(const vector<double> & T1, const vector<double> & T2);


    Matrix_creuse transpose() const;
    Matrix_creuse operator~() const;

};

