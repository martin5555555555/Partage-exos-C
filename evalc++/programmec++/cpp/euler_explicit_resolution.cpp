#include "write_vector.h"
#include "euler_explicit_resolution.h"
#include "matrix.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;



vector<Matrix> euler_explicit_resolution(const Matrix & T0, const double t0, const double dt,const double t,const Matrix & K1)
{   vector<Matrix> res;
    res.push_back(T0);
    fstream textfile_vector;
    fstream textfile_time;
    string filename_vector = "../../programmepython/results_euler_explicit";
    string filename_time = "../../programmepython/time_euler_explicit";
    textfile_vector.open(filename_vector, std::ios_base::app);
    textfile_time.open(filename_time, std::ios_base::app);
    write_vector(textfile_vector, T0);
    textfile_vector << endl;
    textfile_time << t0<<endl;


    for (double time = t0 + dt; time<t; time = time + dt)
    {   
        Matrix T1 = res.back();
        Matrix m_int = (K1*T1)*(dt);
        for (int i =0; i<10; i++)
        {
        cout << m_int.tab[i] << " ";
        };
        T1 = T1 +  m_int;
        res.push_back(T1);
        write_vector(textfile_vector, T1);
        textfile_vector << endl;
        textfile_time << time << endl;
    };
    return res;
};

