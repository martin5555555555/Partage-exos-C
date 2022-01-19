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
#include "euler_explicit_D_variable.h"
#include <chrono>
#include <thread>

using namespace std;
    
/*lorsqu'on exécute le main, la partie c++ est d'abord exécutée, ce qui écris les différents résultats
des fichiers. Puis, grâce au script en bash qui sera lancé, le programme python va lire ces fichiers
et afficher les graphes des données. Ces graphes se trouvent dans le build.*/
 int main()
{   cout << "voulez vous tester la classe matrice" << endl;
    string ans;
    cin >> ans;
    if (ans == "Y")
    {
        test();
    };

    cout << "les différents graphes sont été sauvegardés dans le dossier evalc++" << endl;

    
    system("../../bash/autorisation.sh"); //autorise les programmes bash à faire des actions sur les autres commandes
    system("../../bash/delete_files.sh"); // supprime les anciens fichiers textes de résultats, afin de ne pas réecrire par dessus.
    
     // premiers résultats à l'aide de D constant et de la classe Matrix "de base"
     double L = 1; // longueur du système choisi
     double N = 10; // nombre de points dans l'espace choisi
     double delta_x = L/(N-1);// pas de distance choisi
     double delta_x_trace = L/N; //pas de distance pour le graphe
    //initialisation des paramètres t0, t et dt:
    double t0 = 0; // temps initial
    double t = 0.5; // temps final
    double dt = 0.0005; // pas de temps choisi
    
    fstream file_delta_x;
    string name_delta_x = "../../programmepython/file_delta_x";
    file_delta_x.open(name_delta_x, std::ios_base::app);
    file_delta_x << delta_x_trace;
    file_delta_x.close();


    

     //initialisation des matrices K1 et T0;
     Matrix  K1 = Matrix::init_K_stationnaire(N, delta_x);

     
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
    
    //resolution avec D non constant
    Matrix_creuse K1_variable = Matrix_creuse::init_K_variable(N, delta_x);
    vector<vector<double>> res5 = euler_explicit_D_variable(T0_creuse, t0, dt, t, K1_variable);
    
    //exécution du script python qui produit les graphes:
    system("../../bash/exec_python.sh");
    
    cout << "voulez vous comparer les temps entre matrices creuses et non creuses? (Y/N)"<< endl;
    string ans2;
    cin >> ans2;
    if (ans2 =="Y")
    {   auto start = std::chrono::high_resolution_clock::now();
        for (int i=0; i<100; i++)
        {
        vector<Matrix> res = euler_explicit_resolution(T0, t0, dt, t, K1);
        };
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        cout << "euler explicit  a duré " << duration.count()/100 << "microsecondes." << endl;

        auto start2 = std::chrono::high_resolution_clock::now();
        for (int i=0; i<100; i++)
        {
        vector<vector<double>> res = euler_explicit_resolution(T0_creuse, t0, dt, t, K1_creuse);
        };
        auto end2 = std::chrono::high_resolution_clock::now();
        auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2);
        cout << "euler explicit creuse  a duré " << duration2.count()/100 << "microsecondes." << endl;
        cout << "on a bien une diminution du temps de calcul, car les opérations sur les matrices creuses nécessitent moins de calcul"<<endl;

    };
    



     return 0; 
     };


    
     
 



