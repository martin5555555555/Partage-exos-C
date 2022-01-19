#include "write_vector_creuse.h"
#include "matrix_creuse.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

/*même chose que euler_implicit_resolution.cpp mais avec euler_explicit et le D variable 
(c'est la même fonction que euler explicit creuse, seul le nom du fichier crée change.*/


vector<vector<double>> euler_explicit_D_variable(const vector<double> & T0, const double  t0, const double dt,const double t,const Matrix_creuse & K1)
{   vector<vector<double>> res;
    res.push_back(T0);
    fstream textfile_vector;
    fstream textfile_time;
    string filename_vector = "../../programmepython/results_euler_explicit_D_variable";
    string filename_time = "../../programmepython/time_euler_explicit_D_variable";
    textfile_vector.open(filename_vector, std::ios_base::app);
    textfile_time.open(filename_time, std::ios_base::app);
    write_vector(textfile_vector, T0);
    textfile_vector << endl;
    textfile_time << t0<<endl;


    for (double time = t0 + dt; time<t; time = time + dt)
    {   
        vector<double> T1 = res.back();
        T1 = Matrix_creuse::add_vect_vect(T1, Matrix_creuse::mult_vect_scal(K1 *T1, dt));
        res.push_back(T1);
        write_vector(textfile_vector, T1);
        textfile_vector << endl;
        textfile_time << time << endl;
    };
    return res;
};

