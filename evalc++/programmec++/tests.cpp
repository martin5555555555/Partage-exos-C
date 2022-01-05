#include "tests.h"
#include "matrix.h"

Matrix create_id(const int n)
{
    Matrix m(n,n);
    for (int i = 0; i<n; i++)
    {
        *m(i,i) = 1;
    };
    return m;
};
Matrix create_mattest1()
{
   Matrix mat_test1(3,3);
   mat_test1.tab = {0,1,0,3,4,1,0,1,0};
};


Matrix test_mult_mat()
{
    
    
}

