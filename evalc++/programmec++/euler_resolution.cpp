#include "euler_resolution.h"
#include "matrix.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void write_vector(fstream &textfile, Matrix T1) 
{  
        if (T1.width == 1)
    {
        for (int i = 0; i< T1.length; i++)
        {
            textfile << T1.tab[i]; textfile<<",";
        };
    } 
};

vector<Matrix> euler_resolution(const Matrix & T0, const double t0, const double dt,const double t,const Matrix & K1)
{   vector<Matrix> res = {T0};
    fstream textfile_vector;
    fstream textfile_time;
    string filename_vector = "results_euler_explicit";
    string filename_time = "time_euler_explicit";
    textfile_vector.open(filename_vector, std::ios_base::app);
    textfile_time.open(filename_time, std::ios_base::app);
    write_vector(textfile_vector, T0);
    textfile_time << t0<<endl;


    

    for (double time = t + dt; time<t; time = time + dt)
    {  
        Matrix T1 = res[-1];
        T1 = T1 + ((K1*T1)*(-dt));
        res.push_back(T1);
        write_vector(textfile_vector, T1);
        textfile_time << time << endl;
    };
    return res;
}

