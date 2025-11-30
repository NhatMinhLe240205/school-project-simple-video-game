#include <iostream>
#include "Moteur.h"
#include "Image.h"
#include "Personnage.h"
#include "Tuile.h"
#include "Dictionnaire.h"
#include "Objet.h"
#include "Niveau.h"

using namespace std;

int main()
{
    Dictionnaire dictionnaire("assets/dictionnaire.txt");
    dictionnaire.afficher();
    cout << endl;

    Tuile resultat;

    if(dictionnaire.recherche("Arbre_1", resultat))
    {
        cout << "Ok, objet trouvé: " << endl;
        resultat.afficher();
    }
    else
        cout << "Error" << endl;

    if(dictionnaire.recherche("Briques_vermoulues", resultat))
    {
        cout << "Ok, objet trouvé: " << endl;
        resultat.afficher();
    }
    else
        cout << "Error" << endl;

    if(dictionnaire.recherche("JEHBFJQSV", resultat))
    {
        cout << "Error" << endl;
        resultat.afficher();
    }
    else
        cout << "Ok: l'objet n'existe pas" << endl;

    return 0;
}

