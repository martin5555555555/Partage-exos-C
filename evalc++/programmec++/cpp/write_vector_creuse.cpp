#include <fstream>
#include "write_vector_creuse.h"
void write_vector(fstream &textfile, const vector<double> & T1) //écrit les composantes d'un vecteur sous 
//le format x1,x2,...,xN dans un fichier texte déjà ouvert à la dernière ligne
{       int N = T1.size();
        for (int i = 0; i< N; i++)
        {
            textfile << T1[i] <<",";
        };
    
};