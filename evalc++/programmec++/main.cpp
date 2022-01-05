#include "matrix.h"
#include "euler_resolution.h"
#include <iostream>
#include <vector>
#include "tests.h"
using namespace std;
    

 int main()
 {   
     /*Matrix matK = Matrix::init_K(3);
     cout << "~~" << matK.length << " " << matK.width << endl;
     for (int i =0; i<9; i++)
     {
         cout << "i : " << i << " " << matK.tab[i] << endl;
     };
     Matrix m(3,3);
     int x = 1;
     *m(0,0) =  1;
     for (int i =0; i<9; i++)
     {
         cout << "i : " << i << " " << m.tab[i] << endl;
     };*/
     
    Matrix m0(3,3);
    for (int i = 0; i<3; i++)
    {
        *m0(i,i) = 1;
    };
     
     Matrix m(3,3);
     m =  m*(m0);
     for (int i =0; i<9; i++)
     {
         cout << "i : " << i << " " << m.tab[i] << endl;
     };
     return 0;
 };

