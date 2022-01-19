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
using namespace std;


Matrix::Matrix(const int i,const int j) // constructeur qui renvoie une matrice de 0 de hauteur i et de lageur j
{   
    double* tab;
    tab = (double*) malloc (i*j*sizeof(double)); /* cette ligne est essentielle car elle alloue la 
    mémoire qui sera occupée par le tableau. Si on ne faisait pas ça, les valeurs des cases mémoires 
    du tableau seraient écrasées dès la fin de la fonctio*/ 
    memset(tab, 0, (i*j)*sizeof(double)); // met les valeurs du tableau à 0
    this ->length = i;
    this ->width = j;
    this -> tab = tab;
    };

Matrix::Matrix(const Matrix & matrix) //constructeur de copie d'une matrice
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

int Matrix::getlength() const
{
    return this->length;
};
int Matrix::getwidth() const
{
    return this->width;
};
double* Matrix::gettab() const
{
    return this->tab;
};

double f_remplissage() // cette fonction renvoie un nombre aléatoire entre 0.5 et 1.5
    {   double x = rand()%100;
        return (50 + x)/100;
    };

vector<double> Matrix::init_random_D(const int N) //cette fonction renvoie un vecteur D aléatoire
{
    vector<double> D(N, 0);
  
    srand(time(0)); // permet d'avoir un D différent à chaque appel, sinon c'est toujours le même

    generate(D.begin(), D.end(), f_remplissage); //rempli tout le vecteur D avec des valeurs aléatoires
    
   
    return D;
};


Matrix Matrix::init_K_stationnaire(const int N, const double delta_x) // initialise K avec D constant, (=1 partout)
{ vector<double> D1;
  for (int i =0; i<N;i++)
  {
      D1.push_back(1);
  };
Matrix m(N,N);
for(int i= 1; i<N-1; i++) // on applique l'algorithme proposé dans l'énoncé
   { *m(i,i-1) = D1[i-1];
     *m(i,i) = -D1[i] - D1[i+1];
     *m(i-1,i) = D1[i];
   };
*m(N-1,N-2) = 0; /* J'ai choisi de mettre des 0 sur toute la première et la dernière ligne afin de respecter 
la condition de nullité aux extrémités lors de l'évolution du système*/
*m(N-2, N-1) = D1[N-1];
*m(0,0)= 0; 
*m(N-1,N-1)= 0;
*m(0,1) =0;


return m*(1/(delta_x*delta_x));
};

Matrix Matrix::init_K_variable(const int N, const double delta_x) // même programme que le précédent mais avec D variable
{ vector<double> D1 = Matrix::init_random_D(N);

Matrix m(N,N);
for(int i= 1; i<N-1; i++)
   { *m(i,i-1) = D1[i-1];
     *m(i,i) = -D1[i] - D1[i+1];
     *m(i-1,i) = D1[i];
   };
*m(N-1,N-2) = 0;
*m(N-2, N-1) = D1[N-1];
*m(0,0)= 0;
*m(N-1,N-1)= 0;
*m(0,1) =0;


return m*(1/(delta_x*delta_x));
};

Matrix Matrix::init_T0(const int N, const double delta_x) //initialise le vecteur de température au temps 0
{   double pi = M_PI;
    Matrix T0(N,1);
    for (int  i =0; i<N; i++)
    {   

        T0.tab[i] = 1/2 + sin(2*pi*i* delta_x) - 1/2 * cos(2*pi*i* delta_x);
    }
    return T0;

}

Matrix Matrix::create_id(const int n) //renvoie la matrice identité
{
    Matrix m(n,n);
    for (int i = 0; i<n; i++)
    {
        *m(i,i) = 1;
    };
    return m;
};



double* Matrix::get(const int i, const int j) const // cette fonction renvoie un pointeur sur la "case" (i,j) de la matrice
{
    double* res = &(this->tab)[i*(this->width) + j] ;
    return res;
}

double* Matrix::operator()(const int i, const int j) const
{
    return this->Matrix::get(i,j);
};
Matrix Matrix::summ(const Matrix& matrix_2) const // renvoie la somme de deux matrices
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


Matrix Matrix::mult_mat(const Matrix& matrix_2) const // multiplie deux matrices
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


Matrix Matrix::mult_scal(const double lambda) const //multiplie une matrice par un scalaire
{
    Matrix res(*this);
    for (int i =0; i< (this->length)*(this->width);i++)
        {res.tab[i] = lambda * res.tab[i];
        };
    return res;
};

Matrix Matrix::operator*(const double lambda) const
{
    Matrix res = this->mult_scal(lambda);
    return res;
};

Matrix Matrix::transpose() const // renvoie la transposée d'une matrice (on ne s'en servira finalement pas)
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