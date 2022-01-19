#include <fstream>
#include "write_vector.h"
void write_vector(fstream &textfile, const Matrix & T1) //écrit les composantes d'une Matrice colonne sous 
//le format x1,x2,...,xN dans un fichier texte déjà ouvert à la dernière ligne
{       
        if (T1.getwidth() == 1)
    {
        for (int i = 0; i< T1.getlength(); i++)
        {
            textfile << T1.gettab()[i] <<",";
        };
    } 
};