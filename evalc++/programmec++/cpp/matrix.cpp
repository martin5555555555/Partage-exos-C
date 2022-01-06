#include "matrix.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;


Matrix::Matrix(const int i,const int j)
{   
    double* tab;
    tab = (double*) malloc (i*j*sizeof(double));
    memset(tab, 0, (i*j)*sizeof(double));
    this ->length = i;
    this ->width = j;
    this -> tab = tab;
    };

Matrix::Matrix(const Matrix & matrix) 
{   int i = matrix.length;
    int j = matrix.width;
    this-> length = i;
    this->width = j;
    double * tab = (double*) malloc((i*j)*sizeof(double));
    for (int k =0; k< i*j; k++)
    {
        tab[k] = matrix.tab[k];
    };
    this->tab = tab;
};

Matrix::~Matrix()
{
  
};

Matrix Matrix::init_K(const int N)
{
Matrix m(N,N);
for(int i= 1; i<N; i++)
   { *m(i,i-1) = 1;
     *m(i,i) = -1;
   };
*m(0,0) = -1;
for (int i =0; i<9; i++)
     {
         
     };
Matrix mtranspose = m.transpose();
for (int i =0; i<9; i++)
     {
         
     };
m = m + mtranspose ;

return m;
};

Matrix Matrix::create_id(const int n)
{
    Matrix m(n,n);
    for (int i = 0; i<n; i++)
    {
        *m(i,i) = 1;
    };
    return m;
};



double* Matrix::get(const int i, const int j) const
{
    double* res = &(this->tab)[i*(this->width) + j] ;
    return res;
}

double* Matrix::operator()(const int i, const int j) const
{
    return this->Matrix::get(i,j);
};
Matrix Matrix::summ(const Matrix& matrix_2) const
{   
    int i1 =this->length;
    int j1 = this-> width;
    int i2 = matrix_2.length;
    int j2 = matrix_2.width;
    
    
    if (i1 == i2 && j1 == j2)
        {   Matrix res(i1, j1);
            for (int i=0; i< i1 * j1; i++)
                {  res.tab[i] = this->tab[i] + matrix_2.tab[i];
              };
       return res;
        }
    else { throw std::invalid_argument("matrixes sizes don't match");};
};

Matrix Matrix::operator+(const Matrix& matrix_2) const
{   
    Matrix res = this->summ(matrix_2);
    return res;
};


Matrix Matrix::mult_mat(const Matrix& matrix_2) const
{
    int i1 = this->length;
    int j1 =  this->width;
    int i2 = matrix_2.length;
    int j2 =  matrix_2.width;
    
    if (j1 == i2)
        {Matrix res(i1,j2);
         for (int i =0; i<i1;i++)
         {
             for (int j=0;j<j2;j++)
             {  
                 for (int k=0; k<j1; k++)
                 {   
                    double u;
                    u =  (*(*this)(i,k)) * (*matrix_2(k,j));
                   
                    *res(i,j) =*res(i,j)+ u;

                 };
             };
         };
         return res;
    }
    else 
     throw std::invalid_argument("matrixes sizes don't match");

    
};

Matrix Matrix::operator*(const Matrix& matrix_2) const
{
    Matrix res = this->mult_mat(matrix_2);
    return res;
}


Matrix Matrix::mult_scal(const int lambda) const
{
    Matrix res(*this);
    for (int i =0; i< (this->length)*(this->width);i++)
        {res.tab[i] = lambda * res.tab[i];
        };
    return res;
};

Matrix Matrix::operator*(const int lambda) const
{
    Matrix res = this->mult_scal(lambda);
    return res;
};

Matrix Matrix::transpose() const
{   Matrix res(*this);
    for (int i = 0; i< this->length; i++)
    {
        for (int j=0; j<i;j++)
        {   double ex_value = *res(i,j);
            *res(i,j) = *res(j,i);
            *res(j,i) = ex_value;
        };
    };
    return res;
};

Matrix Matrix::operator~() const
{   
    Matrix res = this->transpose();
    return res;
};