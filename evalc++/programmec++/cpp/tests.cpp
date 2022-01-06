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
   double* tab = (double*) malloc(9 * sizeof(double));
   
   
   mat_test1.tab = tab;
   return mat_test1;

};

 Matrix create_mattest2()
{
   Matrix mat_test2(3,3);
   double tab[9] = {1,2,0,0,5,0,1,-1,0} ;
   mat_test2.tab = tab;
   return mat_test2;
};

bool test_mult_mat()
{  Matrix mat_test_1 =  create_mattest1();
   Matrix mat_test_2 =  create_mattest2();
    
    double theoric_result_tab[9] = {0,5,0,4,25,0,0,5,0};
    bool res = true;
    for (int i = 0; i<9; i++)
    {
        if (theoric_result_tab[i] != (mat_test_1 * mat_test_2).tab[i])
        {
            return false;
        }
    };
    return true;
    
};

bool test_summ()
{  Matrix mat_test_1 =  create_mattest1();
   Matrix mat_test_2 =  create_mattest2();
    
    int theoric_result_tab[9] = {1,3,0,3,9,1,1,0,0};
    bool res = true;
    for (int i = 0; i<9; i++)
    {
        if (theoric_result_tab[i] != (mat_test_1 + mat_test_2).tab[i])
        {
            return false;
        }
    };
    return true;
    
};

bool test_mult_scal()
{  Matrix mat_test_1 =  create_mattest1();
    
    int theoric_result_tab[9] = {0,5,0,15,20,5,0,5,0};
    bool res = true;
    for (int i = 0; i<9; i++)
    {
        if (theoric_result_tab[i] != (mat_test_1 * 5).tab[i])
        {
            return false;
        }
    };
    return true;
    
};

bool test_transpose()
{  Matrix mat_test_1 =  create_mattest1();
    
    double theoric_result_tab[9] = {0,3,0,1,4,1,0,1,0};
    bool res = true;
    for (int i = 0; i<9; i++)
    {
        if (theoric_result_tab[i] != (~mat_test_1).tab[i])
        {
            return false;
        }
    };
    return true;
    
};

bool test_initK()
{  Matrix mat_test_1 =  create_mattest1();
    
    int theoric_result_tab[9] = {-2,1,0,1,-2,1,0,1,-2};
    bool res = true;
    for (int i = 0; i<9; i++)
    {
        if (theoric_result_tab[i] != (~mat_test_1).tab[i])
        {
            return false;
        }
    };
    return true;
    
};

