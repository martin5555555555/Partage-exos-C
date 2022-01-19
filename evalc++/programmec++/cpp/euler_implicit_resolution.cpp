#include "write_vector.h"
#include "euler_implicit_resolution.h"
#include "factorisationLu.h"
#include "matrix.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

/* on applique l'algorithme d'euler implicite, qui nous est fourni dans l'énoncé*/
vector<Matrix> euler_implicit_resolution(const Matrix & T0, const double t0, const double dt,const double t,const Matrix & K1)
{   vector<Matrix> res;
    res.push_back(T0);
    fstream textfile_vector;
    fstream textfile_time;

    //création des deux fichiers textes que nous allons utiliser pour stocker les résultat.
    string filename_vector = "../../programmepython/results_euler_implicit";
    string filename_time = "../../programmepython/time_euler_implicit";

    //on ouvre les deux fichiers en mode "append" pour pouvoir écrire et que le curseur reste à la fin du fichier
    textfile_vector.open(filename_vector, std::ios_base::app);
    textfile_time.open(filename_time, std::ios_base::app);

    //on écrit dans les fichiers
    write_vector(textfile_vector, T0);
    textfile_vector << endl;
    textfile_time << t0<<endl;

    Matrix Id = Matrix::create_id(T0.getlength());
    for (double time = t0 + dt; time<t; time = time + dt)
    {   
        Matrix T1 = res.back(); //on reprend le dernier résultat que l'on a calculé.
        Matrix A1 = Id +K1* -dt;
        T1 = final_resolution(A1, T1);
        res.push_back(T1);

        
        write_vector(textfile_vector, T1); //on écrit le résultat dans le fichier
        textfile_vector << endl;
        textfile_time << time << endl;
    };
    return res;
};

