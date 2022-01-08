#include "write_vector_creuse.h"
#include "euler_implicit_resolution_creuse.h"
#include "factorisationLu_creuse.h"
#include "matrix_creuse.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


vector<vector<double>> euler_implicit_resolution(const vector<double> & T0, const double  t0, const double dt,const double t,const Matrix_creuse & K1)
{   vector<vector<double>> res;
    res.push_back(T0);
    fstream textfile_vector;
    fstream textfile_time;
    string filename_vector = "../../programmepython/results_euler_implicit_creuse";
    string filename_time = "../../programmepython/time_euler_implicit_creuse";
    textfile_vector.open(filename_vector, std::ios_base::app);
    textfile_time.open(filename_time, std::ios_base::app);
    write_vector(textfile_vector, T0);
    textfile_vector << endl;
    textfile_time << t0<<endl;

     Matrix_creuse Id = Matrix_creuse::create_id(T0.size());
     for (double time = t0 + dt; time<t; time = time + dt)
    {   
        vector<double> T1 = res.back();
         Matrix_creuse A1 = Id + K1.mult_scal(-dt);
        T1 = final_resolution(A1, T1);
        res.push_back(T1);
        write_vector(textfile_vector, T1);
        textfile_vector << endl;
        textfile_time << time << endl;
    };
    return res;
};

