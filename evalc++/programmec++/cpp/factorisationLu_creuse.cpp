#include "factorisationLu_creuse.h"
#include "matrix.h"
#include "matrix_creuse.h"
#include <vector>

vector<Matrix_creuse> lu_decomposition(const Matrix_creuse & matrix)
{   int N = matrix.size;
    Matrix_creuse L = Matrix_creuse(N); 
    Matrix_creuse U = Matrix_creuse(N);
    L.diago[0] = 1;
    U.diago[0] = matrix.diago[0];
    U.diago_up[0] =matrix.diago_up[0];
    for(int i = 1; i<N; i++)
    {
        L.diago[i-1] = 1;
        
        L.diago_down[i-1]= (matrix.diago_down[i-1]) / U.diago[i-1];
        U.diago_up[i-1] = matrix.diago_up[i-1];
        U.diago[i] = matrix.diago[i] - L.diago_down[i-1] * U.diago_up[i-1];
    };
    L.diago[N-1] = 1;
    
    vector<Matrix_creuse> res;
    
    res.push_back(L);
    res.push_back(U);
    return res;
       
};

vector<double> resolution_L(const Matrix_creuse & L1, const vector<double> & h)
{   int n = L1.size;
    vector<double> res(n);
    res[0] = h[0];
    for (int i =1; i<n; i++)
    {   res[i] = h[i] - res[i-1] * L1.diago_down[i-1];
    };
    return res;
};

vector<double> resolution_U(const Matrix_creuse & U, const vector<double> & h)
{   int n = U.size;
    vector<double> res(n);
    res[n-1] = h[n-1] / U.diago[n-1];
    for (int i =1; i<n; i++)
    {
        res[n-1-i] = (h[n-1-i] - U.diago_up[n-i-1] * res[n-i]) / U.diago[n-1-i];
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