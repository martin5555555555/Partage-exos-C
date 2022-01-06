#include "matrix.h"
#include "write_vector.h"
#include "euler_explicit_resolution.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include "tests.h"
#include "factorisationLu.h"
using namespace std;
    


 int main()
{   system("../../bash/autorisation.sh");
    system("../../bash/delete_files.sh");
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
     
    
     Matrix K1 = Matrix::init_K_stationnaire(3);
     Matrix T0(3,1);
     double t0 = 0;
     double dt = 1;
     double t = 5;
    
    for (int i =0; i<9; i++)
     {
         cout << "i : " << i << " " << K1.tab[i] << endl;
     };


    
     //vector<Matrix> res = euler_explicit_resolution(T0, t0, dt,t,K1);
     system("../../bash/exec_python.sh");
     
     return 0; 
     };


    
     
 



