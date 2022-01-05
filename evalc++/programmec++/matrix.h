#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Matrix 
{
    public :
        int length;
        int width;
        int* tab;

    public:
    Matrix(const int i, const int j);
    Matrix(const Matrix & matrix);
    ~Matrix();

    public:
    static Matrix init_K(const int N) ;
    int* get(const int i, const int j) const;
    int* operator ()(const int i, const int j) const;
    Matrix summ(const Matrix& matrix_2) const;
    Matrix operator+(const Matrix& matrix_2) const ;
    Matrix mult_mat(const Matrix& matrix_2) const;
    Matrix operator*(const Matrix& matrix_2) const;
    Matrix mult_scal(const int lambda) const ;
    Matrix operator*(const int lambda) const;

    Matrix transpose() const;
    Matrix operator~() const;

};

