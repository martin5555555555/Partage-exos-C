#include "factorisationLu.h"

vector<Matrix> lu_decomposition(const Matrix & matrix)
{   Matrix L = Matrix(matrix.length, matrix.width); 
    Matrix U = Matrix(matrix.length, matrix.width);
    *L(0,0) = 1;
    *U(0,0) = *matrix(0,0);
    *U(0,1) = *matrix(0,1); 
    for(int i = 2; i<matrix.length; i++)
    {
        *L(i-1,i-1) = 1;
        cout << *matrix(i,i-1) << "et" << *U(i-1,i-1)<< endl;
        *L(i-1,i-2)= (*matrix(i-1,i-2)) / *U(i-2,i-2);
        cout << *L(i,i-1)<< endl;
        *U(i-1,i) = *matrix(i-1,i);
        *U(i-1,i-1) = *matrix(i-1,i-1) - *L(i-1,i-2) * (*U(i-2,i-1));
    };
    int k = matrix.length-1;
    *L(k, k) = 1;
    *U(k-1, k) = *matrix(k-1, k) ;
    *L(k,k-1)= (*matrix(k, k-1)) / *U(k-1,k-1);

    *U(k,k) = *matrix(k,k) - *L(k,k-1) * (*U(k-1,k));
    cout << *matrix(k,k) << "o" <<*L(k,k-1) << "o" << *U(k-1,k) << "0" << *U(k,k) << endl;
    vector<Matrix> res;
    
    res.push_back(L);
    res.push_back(U);
    return res;
       
}

Matrix resolution_L(const Matrix & L1, const Matrix & h)
{   int n = L1.length;
    Matrix res(n,1);
    res.tab[0] = h.tab[0];
    for (int i =1; i<n; i++)
    {   res.tab[i] = h.tab[i] - res.tab[i-1] * (*L1(i, i-1));
        cout << res.tab[i];
    };
    return res;
};

Matrix resolution_U(const Matrix & U, const Matrix & h)
{   int n = U.length;
    Matrix res(n,1);
    res.tab[n-1] = h.tab[n-1] / *U(n-1,n-1);
    for (int i =1; i<n; i++)
    {
        res.tab[n-1-i] = (h.tab[n-1-i] - *U(n-i-1,n-i) * res.tab[n-i]) / *U(n-1-i, n-1-i);
    };
    return res;
};


Matrix final_resolution(const Matrix & K1, const Matrix & b  )
{   vector<Matrix> vec = lu_decomposition(K1);
    Matrix L = vec[0];
    Matrix U = vec[1];
    Matrix h = resolution_L(L, b);
    h = resolution_U(U,h);
    return h;
}