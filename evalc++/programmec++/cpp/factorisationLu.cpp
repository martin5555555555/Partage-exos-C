#include "factorisationLu.h"

/*la méthode que j'ai choisi pour résoudre le système Ax = b est est la factorisation LU, qui repose
sur le fait que les matrices utilisées sont tridigonales. Il faut d'abord décomper A en A =L U, ou 
L est tridigonale avec des 0 sur sa diagonale supérieure et des 1 sur sa diagonale et U est tridigonale
 avec une  diagonale inférieure nulle.
 Pour résoudre le système, on résout donc d'abord : Lh = B d'inconnue h, 
                      puis on termine en résolvant: Ux = h d'inconnue x,
            et on a donc bien LUx = Bb, donc Ax = b!
Cet algorithme est efficace car la résolution des systèmes ainsi que la décomposition ne demande pas 
beaucoup de calcul pour des matrices avec aussi peu de ceofficients non nuls*/
 

vector<Matrix> lu_decomposition(const Matrix & matrix) // renvoie le vecteur {L,U} tq LU = matrix
{   Matrix L = Matrix(matrix.getlength(), matrix.getwidth()); 
    Matrix U = Matrix(matrix.getlength(), matrix.getwidth());
    *L(0,0) = 1;
    *U(0,0) = *matrix(0,0);
    *U(0,1) = *matrix(0,1); 
    for(int i = 2; i<matrix.getlength(); i++)
    {
        *L(i-1,i-1) = 1;
        *L(i-1,i-2)= (*matrix(i-1,i-2)) / *U(i-2,i-2);
        *U(i-1,i) = *matrix(i-1,i);
        *U(i-1,i-1) = *matrix(i-1,i-1) - *L(i-1,i-2) * (*U(i-2,i-1));
    };
    int k = matrix.getlength()-1;
    *L(k, k) = 1;
    *U(k-1, k) = *matrix(k-1, k) ;
    *L(k,k-1)= (*matrix(k, k-1)) / *U(k-1,k-1);

    *U(k,k) = *matrix(k,k) - *L(k,k-1) * (*U(k-1,k));
    vector<Matrix> res;
    
    res.push_back(L);
    res.push_back(U);
    return res;
       
}

Matrix resolution_L(const Matrix & L1, const Matrix & h) // renvoie le résultat de Lx = h
{   int n = L1.getlength();
    Matrix res(n,1);
    res.gettab()[0] = h.gettab()[0];
    for (int i =1; i<n; i++)
    {   res.gettab()[i] = h.gettab()[i] - res.gettab()[i-1] * (*L1(i, i-1));
        
    };
    return res;
};

Matrix resolution_U(const Matrix & U, const Matrix & h)//renvoie le résultat de Ux = h
{   int n = U.getlength();
    Matrix res(n,1);
    res.gettab()[n-1] = h.gettab()[n-1] / *U(n-1,n-1);
    for (int i =1; i<n; i++)
    {
        res.gettab()[n-1-i] = (h.gettab()[n-1-i] - *U(n-i-1,n-i) * res.gettab()[n-i]) / *U(n-1-i, n-1-i);
    };
    return res;
};


Matrix final_resolution(const Matrix & K1, const Matrix & b  )// renvoie le résultat K1x = b, qui est ce qui nous intéresse
{   vector<Matrix> vec = lu_decomposition(K1);
    Matrix L = vec[0];
    Matrix U = vec[1];
    Matrix h = resolution_L(L, b);
    h = resolution_U(U,h);
    return h;
}