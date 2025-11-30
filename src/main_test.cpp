#include <iostream>
#include <fstream>
#include <vector>



#include "Dictionnaire.h"
#include "tuile.h"

using namespace std;

int main()
{

    Dictionnaire dictionnaire("assets/dictionnaire.txt");
    dictionnaire.afficher();

    Tuile object;
    if(dictionnaire.recherche("Arbre_2",object))
    {
        cout << "Found" << endl;
        object.afficher();
    }
    else
    {
        cout << "Not found" << endl;
        object.afficher();
    }


    if(dictionnaire.recherche("Arbre_10",object)) //object non existant
    {
        cout << "Found" << endl;
        object.afficher();
    }
    else
    {
        cout << "Not found" << endl;
        object.afficher();
    }
    return 0;
}
