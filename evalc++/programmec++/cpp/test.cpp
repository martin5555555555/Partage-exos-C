#include "matrix.h"
#include "tests.h"
#include <iostream>
using namespace std;

vector<string> decoupe(const  string & ctab, const int width)
{
    vector<string> res(width);
    int k =0;
    int i =0;
    while(i< ctab.length())
    {
        if(ctab[i] == ',')    { k++;}
        else
        {  
            res[k] += (ctab[i]);
            
        };
        i++;
    };
    return res;
};

void test()
{   
    cout << "définition de votre première matrice"<<endl;
    cout << "choix de la hauteur (int)"<<endl;
    string clength;
    string cwidth;
    cin  >> clength;
    cout << "choix de la largeur (int) "<<endl;
    cin >> cwidth;
    int length = stoi(clength);
    int width = stoi(cwidth);
    
    Matrix Mat_test_1(length, width);
    for (int i=0; i<length; i++)
    {
        cout << "remplir  ligne (on attend une liste de nombre de la longueur d'une ligne séparés par des vigules)"<<endl;
        string  ctab; 
        cin >> ctab;
        vector<string> ctab2 = decoupe(ctab, width);
        for (int j= 0; j< width; j++)
        {
           *Mat_test_1(i,j) = stoi(ctab2[j]);
        };
    };
   Matrix res(length, width);
   cout << "choix opérateur à tester" << endl;
   string operateur;
   cin >> operateur;
   if (operateur ==  "transpose")
   {
        res = Mat_test_1.transpose();

   }
   else {
   if (operateur == "scalaire")
   {
       cout << "choix du scalaire"<< endl;
       double lambda;
       cin >> lambda;
        res = Mat_test_1 * lambda;
   }
   else 
   {
    cout << "définition de votre deuxième matrice"<<endl;
    cout << "choix de la hauteur (int)"<<endl;
    string clength;
    string cwidth;
    cin  >> clength;
    cout << "choix de la largeur (int) "<<endl;
    cin >> cwidth;
    int length = stoi(clength);
    int width = stoi(cwidth);
    
    Matrix Mat_test_2(length, width);
    for (int i=0; i<length; i++)
    {
        cout << "remplir premiere ligne (on attend une liste de nombre de la longueur d'une ligne séparés par des espaces)"<<endl;
         string ctab;
        cin >> ctab;
        vector<string> ctab2 = decoupe(ctab, width);
        for (int j = 0; j< width; j++)
        {
          *Mat_test_2(i,j) =  stoi(ctab2[j]);
        };
    };

    if (operateur == "+") { res = Mat_test_1 + Mat_test_2;}
    if (operateur== "*") { res = Mat_test_1 * Mat_test_2;}

    cout << "affichage du résultat" << endl;
        cout << "mat1 =" << endl;
    for (int i=0; i<length; i++)
    {    cout << "|" << " ";
        for (int j =0; j<width; j++)
        {
            cout <<  *Mat_test_1(i,j)<< " ";
        };
        cout << "|" << endl;
    };
      cout << "mat2 =" << endl;
    for (int i=0; i<length; i++)
    {    cout << "|" << " ";
        for (int j =0; j<width; j++)
        {   
            cout <<  *Mat_test_2(i,j)<< " ";
        };
        cout << "|" << endl;
    
    };
     
    };
        

   };
    
    cout << "res =" << endl;
    for (int i=0; i<length; i++)
    {    cout << "|" << " ";
        for (int j =0; j<width; j++)
        {   
            cout <<  *res(i,j)<< " ";
        };
        cout << "|" << endl;
    };
};
