#include "factorisationLu_creuse.h"
#include "matrix.h"
#include "matrix_creuse.h"
#include <vector>

/* ce sont les mêmes programmes que dans factorisationLU.cpp, mais adaptés pour des matrices creuses. 
Le fonctionnement est exactement le même.
En terme d'efficacité temporelle pour euler implicite, il était un peu artificiel de recoder une classe matrice creuse
sachant que l'algorithme utilisé pour la résolution du système repose déjà sur le caractère tridigonal de
la matrice. Cependant, cela a du sens en terme de complexité mémoire, car toutes les cases nulles
des matrices ne seront pas représentées grâce à la classe matrice creuse*/

vector<Matrix_creuse> lu_decomposition(const Matrix_creuse & matrix)
{   int N = matrix.getsize();
    Matrix_creuse L = Matrix_creuse(N); 
    Matrix_creuse U = Matrix_creuse(N);
    L.setdiago()[0] = 1;
    U.setdiago()[0] = matrix.getdiago()[0];
    U.setdiago_up()[0] =matrix.getdiago_up()[0];
    for(int i = 1; i<N; i++)
    {
        L.setdiago()[i-1] = 1;
        
        L.setdiago_down()[i-1]= (matrix.getdiago_down()[i-1]) / U.getdiago()[i-1];
        U.setdiago_up()[i-1] = matrix.getdiago_up()[i-1];
        U.setdiago()[i] = matrix.getdiago()[i] - L.getdiago_down()[i-1] * U.getdiago_up()[i-1];
    };
    L.setdiago()[N-1] = 1;
    
    vector<Matrix_creuse> res;
    
    res.push_back(L);
    res.push_back(U);
    return res;
       
};

vector<double> resolution_L(const Matrix_creuse & L1, const vector<double> & h)
{   int n = L1.getsize();
    vector<double> res(n);
    res[0] = h[0];
    for (int i =1; i<n; i++)
    {   res[i] = h[i] - res[i-1] * L1.getdiago_down()[i-1];
    };
    return res;
};

vector<double> resolution_U(const Matrix_creuse & U, const vector<double> & h)
{   int n = U.getsize();
    vector<double> res(n);
    res[n-1] = h[n-1] / U.getdiago()[n-1];
    for (int i =1; i<n; i++)
    {
        res[n-1-i] = (h[n-1-i] - U.getdiago_up()[n-i-1] * res[n-i]) / U.getdiago()[n-1-i];
    };
    return res;
};


vector<double> final_resolution(const Matrix_creuse & K1, const vector<double> & b  )
{   vector<Matrix_creuse> vec = lu_decomposition(K1);
    Matrix_creuse L = vec[0];
    Matrix_creuse U = vec[1];
    vector<double> h = resolution_L(L, b);
    h = resolution_U(U,h);
    return h;
}