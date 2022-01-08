#include "matrix.h"
#include "write_vector.h"
#include "euler_explicit_resolution.h"
#include "euler_implicit_resolution.h"
#include "euler_explicit_resolution_creuse.h"
#include "euler_implicit_resolution_creuse.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include "tests.h"
#include "factorisationLu.h"
#include "matrix_creuse.h"
#include "factorisationLu_creuse.h"
using namespace std;
    


 int main()
{  
    system("../../bash/autorisation.sh"); //autorise les programmes bash à faire des actions sur les autres commandes
    system("../../bash/delete_files.sh"); // supprime les anciens fichiers textes de résultats, afin de ne pas réecrire par dessus.
    
     // premiers résultats à l'aide de D constant et de la classe Matrix "de base"
     double L = 1; // longueur du système choisi
     double N = 10; // nombre de points dans l'espace choisi
     double delta_x = L/(N-1);// pas de distance choisi
    //initialisation des paramètres t0, t et dt:
    double t0 = 0; // temps initial
    double t = 0.5; // temps final
    double dt = 0.005; // pas de temps choisi
     //initialisation des matrices K1 et T0;
     Matrix  K1 = Matrix::init_K_variable(N, delta_x);
     
     Matrix T0 = Matrix::init_T0(N, delta_x);
     
     

    //résolution avec euler_explicit
    vector<Matrix> res1 = euler_explicit_resolution(T0, t0, dt, t, K1);
    //résolution avec euler_implicite
    vector<Matrix> res2 = euler_implicit_resolution(T0, t0, dt, t, K1);

    Matrix_creuse  K1_creuse = Matrix_creuse::init_K_stationnaire(N, delta_x);
     
    vector<double> T0_creuse = Matrix_creuse::init_T0(N, delta_x);
    //resolution avec euler_explicit creuse
    vector<vector<double>> res3 = euler_explicit_resolution(T0_creuse, t0, dt, t, K1_creuse);
    //resolution avec euler_implicit_creuse
    vector<vector<double>> res4 = euler_implicit_resolution(T0_creuse, t0, dt, t, K1_creuse);
    
    //exécution du script python qui produit les graphes:
    system("../../bash/exec_python.sh");



     return 0; 
     };


    
     
 



