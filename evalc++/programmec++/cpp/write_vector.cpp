#include <fstream>
#include "write_vector.h"
void write_vector(fstream &textfile, const Matrix & T1) 
{       
        if (T1.width == 1)
    {
        for (int i = 0; i< T1.length; i++)
        {
            textfile << T1.tab[i] <<",";
        };
    } 
};