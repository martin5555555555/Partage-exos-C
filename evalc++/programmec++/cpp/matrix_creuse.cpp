#include "matrix.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <chrono>
#include <thread>
#include <iterator>
#include <algorithm>
#include <math.h>
#include "matrix_creuse.h"

using namespace std;

Matrix_creuse::Matrix_creuse(const int N) // constructeur  à partir d'un unique entier N, car les matrices
//creuses dont on a besoin sont carrées*/
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

Matrix_creuse::Matrix_creuse(const Matrix & matrix) /*constructeur à partir d'une matrice classique 
cette méthode nous permettra de transférer des matrices vers des matrices creuses, et ainsi de ne pas avoir
à recoder les fonctions d'initialisation des matrices. Cela n'est pas optimisé, puisqu'on utilise les méthodes
non efficace de la première classe pour les transférer des objets de la classe la plus "efficace", mais
on peut se le permettre car ces opérations d'initialisation ne sont effectuées qu'une fois au sein du
programme*/
{   
    this->size = matrix.getlength();
    vector<double> diago;
    for (int i =0; i<matrix.getlength(); i++)
    {
        diago.push_back(*matrix(i,i));
    };
    vector<double> diago_up;
    for (int i =1; i<matrix.getlength(); i++)
    {
        diago_up.push_back(*matrix(i-1,i));
    };
    vector<double> diago_down;
    for (int i =0; i<matrix.getlength()-1; i++)
    {
        diago_down.push_back(*matrix(i+1,i));
    };
    this->diago_up = diago_up;
    this->diago_down = diago_down;
    this->diago = diago;
    };

Matrix_creuse::Matrix_creuse(const Matrix_creuse & matrix)  //constructeur de copie 
{   this->size = matrix.size;
    this->diago = matrix.diago;
    this->diago_up = matrix.diago_up;
    this-> diago_down = matrix.diago_down;
};

Matrix_creuse::~Matrix_creuse()
{
  
};

int Matrix_creuse::getsize() const
{
    return this->size;
};

vector<double> Matrix_creuse::getdiago() const
{
    return this->diago;
};

vector<double> Matrix_creuse::getdiago_up() const
{
    return this->diago_up;
};

vector<double> Matrix_creuse::getdiago_down() const
{
    return this->diago_down;
};

//setters
vector<double> & Matrix_creuse::setdiago()
{
    return  this->diago;
};

vector<double> & Matrix_creuse::setdiago_up()
{
    return  this->diago_up;
};

vector<double> & Matrix_creuse::setdiago_down()
{
    return  this->diago_down;
};



Matrix_creuse Matrix_creuse::init_K_stationnaire(const int N, const double delta_x) //initialise la matrice K avec D constant pour une matrice creuse
{ Matrix m = Matrix::init_K_stationnaire(N,delta_x); //on utilise le constructeur à partir des matrices
  return Matrix_creuse(m);
};

Matrix_creuse Matrix_creuse::init_K_variable(const int N, const double delta_x)//initalise une matrice creuse K pou D variant
{ Matrix m = Matrix::init_K_variable(N, delta_x);
  return Matrix_creuse(m);
};
Matrix_creuse Matrix_creuse::create_id(const int N)//crée la matrice creuse identité
{
Matrix m = Matrix::create_id(N);
return Matrix_creuse(m);

  
};

vector<double> Matrix_creuse::init_T0(const int N, const double delta_x)//initialise le vecteur T0
{
    double pi = M_PI;
    vector<double> T0(N);
    T0[0] = 0;
    for (int  i =1; i<N; i++)
    {   

        T0[i] = 1/2 + sin(2*pi*i* delta_x) - 1/2 * cos(2*pi*i* delta_x);
    }
    return T0;
}
Matrix_creuse Matrix_creuse::summ(const Matrix_creuse& matrix_2) const // additionne deux matrices creuses
{   
   int n1 = this->size;
   int n2 = matrix_2.size;

    
    if (n1 = n2)
        {   Matrix_creuse res(n1);
            for (int i=0; i< n1-1; i++)
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

vector<double> Matrix_creuse::mult_vect(const vector<double> &T) const // multiplie deux matrices creuses
{   int N = this->size;
    vector<double> res(N);
    res[0] = this->diago[0] * T[0] + this->diago_up[0] * T[1];
    for (int i=1; i<N-1;i++)
    {
        res[i] = this->diago_down[i-1] * T[i-1] + this->diago[i] * T[i] + this->diago_up[i] * T[i+1];
    };
    res[N-1] = this->diago_down[N-2] * T[N-2] + this->diago[N-1] * T[N-1];
    return res;
};
vector<double> Matrix_creuse::operator*(const vector<double> & T) const
{   vector<double> res = this->mult_vect(T);
    return res;
};

Matrix_creuse Matrix_creuse::mult_scal(const double lambda) const // multiplie une matrice creuse avec un scalaire
{   int n = this->size;
    Matrix_creuse res(*this);
    for (int i =0; i< n-1;i++)
        {res.diago[i] = lambda * res.diago[i];
        res.diago_up[i] = lambda * res.diago_up[i];
        res.diago_down[i] = lambda * res.diago_down[i];

        };
    res.diago[n-1] = lambda * res.diago[n-1];
    return res;
};

Matrix_creuse Matrix_creuse::operator*(const double lambda) const
{
    Matrix_creuse res = this->mult_scal(lambda);
    return res;
};

vector<double> Matrix_creuse::mult_vect_scal(const vector<double> & T, const double t) // mutliplie un vecteur par un scalaire
{   int N = T.size();
    vector<double> res(N);
    for (int i=0; i<N; i++)
    {
        res[i] = T[i] * t;
    };
    return res;
};
vector<double> Matrix_creuse::add_vect_vect(const vector<double> & T1, const vector<double> & T2) //additionne deux vecteurs entre eux
{   int N = T1.size();
    vector<double> res(N);
    for (int i=0; i<N; i++)
    {
        res[i] = T1[i] + T2[i];
    };
    return res;
};