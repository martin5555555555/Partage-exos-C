#include "matrix.h"
#include "write_vector.h"
#include "euler_explicit_resolution.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include "tests.h"
#include "factorisationLu.h"
#include "matrix_ creuse.h"
#include "factorisationLu_creuse.h"
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
     
    /*
     Matrix K1 = Matrix::init_K_variable(3);
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
     */
    cout<< 8;
     Matrix_creuse K1 = Matrix_creuse::init_K_stationnaire(3);
     cout<< 8;
     vector<double> T0;
     T0.push_back(1);
     T0.push_back(0);
     T0.push_back(1);
     
     double t0 = 0;
     double dt = 1;
     double t = 5;
     vector<double> res = final_resolution(K1, T0);
     cout << res[0] << "r" << res[1] << "r0"<< res[2];

     return 0; 
     };


    
     
 



