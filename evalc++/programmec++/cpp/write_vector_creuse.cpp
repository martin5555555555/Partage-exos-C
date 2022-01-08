#include <fstream>
#include "write_vector_creuse.h"
void write_vector(fstream &textfile, const vector<double> & T1) 
{       int N = T1.size();
        for (int i = 0; i< N; i++)
        {
            textfile << T1[i] <<",";
        };
    
};