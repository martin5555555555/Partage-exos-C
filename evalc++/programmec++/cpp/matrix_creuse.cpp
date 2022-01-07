#include "matrix.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <chrono>
#include <thread>
#include <iterator>
#include <algorithm>
#include "matrix_ creuse.h"

using namespace std;

Matrix_creuse::Matrix_creuse(const int N)
{
    this->size = N;
    vector<double>  diago;
    for (int i =1; i<N; i++)
    {
        diago.push_back(0);
    };
    this->diago_up = diago;
    this->diago_down = diago;
    diago.push_back(0);
    this->diago = diago;
}

Matrix_creuse::Matrix_creuse(const Matrix & matrix)
{   
    this->size = matrix.length;
    vector<double> diago;
    for (int i =0; i<matrix.length; i++)
    {
        diago.push_back(*matrix(i,i));
    };
    vector<double> diago_up;
    for (int i =1; i<matrix.length; i++)
    {
        diago_up.push_back(*matrix(i-1,i));
    };
    vector<double> diago_down;
    for (int i =0; i<matrix.length-1; i++)
    {
        diago_down.push_back(*matrix(i+1,i));
    };
    this->diago_up = diago_up;
    this->diago_down = diago_down;
    this->diago = diago;
    };

Matrix_creuse::Matrix_creuse(const Matrix_creuse & matrix) 
{   this->size = matrix.size;
    this->diago = matrix.diago;
    this->diago_up = matrix.diago_up;
    this-> diago_down = matrix.diago_down;
};

Matrix_creuse::~Matrix_creuse()
{
  
};



Matrix_creuse Matrix_creuse::init_K_stationnaire(const int N)
{ Matrix m = Matrix::init_K_stationnaire(N);
  return Matrix_creuse(m);
};

Matrix_creuse Matrix_creuse::init_K_variable(const int N)
{ Matrix m = Matrix::init_K_variable(N);
  return Matrix_creuse(m);
};
Matrix_creuse Matrix_creuse::create_id(const int N)
{
Matrix m = Matrix::create_id(N);
return Matrix_creuse(m);

  
};

Matrix_creuse Matrix_creuse::summ(const Matrix_creuse& matrix_2) const
{   
   int n1 = this->size;
   int n2 = matrix_2.size;

    
    if (n1 = n2)
        {   Matrix_creuse res(n1);
            for (int i=0; i< n1; i++)
                {   
                    res.diago[i] = (this->diago)[i] + matrix_2.diago[i];
                    res.diago_up[i] = (this->diago_up)[i] + matrix_2.diago_up[i];
                    res.diago_down[i] = (this->diago_down)[i] + matrix_2.diago_down[i];

                };
             res.diago[n1-1] = (this->diago)[n1-1] + matrix_2.diago[n1-1];
       return res;
        }
    else { throw std::invalid_argument("matrixes sizes don't match");};
};

Matrix_creuse Matrix_creuse::operator+(const Matrix_creuse& matrix_2) const
{   
    Matrix_creuse res = this->summ(matrix_2);
    return res;
};



Matrix_creuse Matrix_creuse::mult_scal(const int lambda) const
{   int n = this->size;
    Matrix_creuse res(*this);
    for (int i =0; i< n-1;i++)
        {res.diago[i] = lambda * res.diago[i];
        res.diago_up[i] = lambda * res.diago_up[i];
        res.diago_down[i] = lambda * res.diago_down[i];

        };
    res.diago[n-1] = lambda * res.diago[lambda];
    return res;
};

Matrix_creuse Matrix_creuse::operator*(const int lambda) const
{
    Matrix_creuse res = this->mult_scal(lambda);
    return res;
};
