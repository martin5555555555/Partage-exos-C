#pragma once
#include <iostream>
#include <vector>
using namespace std;

/* la classe matrice que nous allons utiliser nous permettra d'implémenter numériquement les matrices.
Cette classe est tout à fait générale, et ne tient pas compte du caractère tridigonal des matrices utilisées 
dans notre cas précis.
Les explications sur les fonctions sont fournies dans matrix.cpp*/

class Matrix 
{
    private :
        int length;
        int width;
        double* tab; /*j'ai choisi de prendre un array et non un vecteur (même si ça complique un peu 
        le code avec des pointeurs et des allocations de mémoire par rapport à un std::vector), car 
        on sait que la taille du fichier est fixe*/

    public:
    Matrix(const int i, const int j);
    Matrix(const Matrix & matrix);
    ~Matrix();

    public:
    //getters
    int getlength() const ;
    int getwidth() const;
    double* gettab() const;

    static Matrix init_K_stationnaire(const int N, const double delta_x) ; 
    static Matrix init_T0(const int N, const double delta_x);
    static Matrix create_id(const int n);
    double remplissage_f();
    static vector<double> init_random_D(const int N);
    static Matrix init_K_variable(const int N, const double delta_x);

    double* get(const int i, const int j) const;
    double* operator ()(const int i, const int j) const;
    Matrix summ(const Matrix& matrix_2) const;
    Matrix operator+(const Matrix& matrix_2) const ;
    Matrix mult_mat(const Matrix& matrix_2) const;
    Matrix operator*(const Matrix& matrix_2) const;
    Matrix mult_scal(const double lambda) const ;
    Matrix operator*(const double lambda) const;

    Matrix transpose() const;
    Matrix operator~() const;

};

