#include "matrix.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <chrono>
#include <thread>
#include <iterator>
#include <algorithm>
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

vector<double> Matrix::init_random_D(const int N)
{

    
  
    // Initialize the vector with
    // initial values as 0
    vector<double> V(N, 0);
  
    // use srand() for different outputs
    srand(time(0));
  
    // Generate value using generate
    // function
    generate(V.begin(), V.end(), rand);
    
    for (int i = 0; i < N; i++) 
    {
        cout << V[i] << " ";
    };
};


Matrix Matrix::init_K_stationnaire(const int N)
{ vector<double> D1;
  for (int i =0; i<N;i++)
  {
      D1.push_back(1);
  };
Matrix m(N,N);
*m(0,0) = -D1[0] - D1[1];
for(int i= 1; i<N-1; i++)
   { *m(i,i-1) = D1[i-1];
     *m(i,i) = -D1[i] - D1[i+1];
     *m(i-1,i) = D1[i];
   };
*m(N-1,N-2) = D1[N-2];
*m(N-2, N-1) = D1[N-1];
return m;
};

Matrix Matrix::init_K_variable(const int N)
{ vector<double> D1 = Matrix::init_random_D(N);
Matrix m(N,N);
cout << "okok";
*m(0,0) = -D1[0] - D1[1];
cout << "okok";
for(int i= 1; i<N-1; i++)
   { *m(i,i-1) = D1[i-1];
     *m(i,i) = -D1[i] - D1[i+1];
     *m(i-1,i) = D1[i];
   };
*m(N-1,N-2) = D1[N-2];
*m(N-2, N-1) = D1[N-1];
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