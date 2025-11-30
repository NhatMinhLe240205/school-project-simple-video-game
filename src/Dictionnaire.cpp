#include "Dictionnaire.h"
#include <iostream>
#include <fstream>

using namespace std;

Dictionnaire::Dictionnaire(const string& fichier)
{
    int nbObjet, i;
    i = 0;
    ifstream input;
    input.open(fichier);
    if(!(input.is_open())) throw string ("Failure while opening file : " + fichier);
    input >> nbObjet;
    while(i < nbObjet)
    {
        string nom, property;
        int posx, posy;
        input >> nom;
        input >> posx;
        input >> posy;
        input >> property;
        _vecTuile.push_back(Tuile(nom, posx, posy, property));
        i++;
    }
    input.close();
    if (_vecTuile.size()!= nbObjet) throw invalid_argument("Failure while loading the objects of file : " + fichier);
}

void Dictionnaire::afficher() const
{
    for (int i=0; i<_vecTuile.size(); i++)
    {
        _vecTuile[i].afficher();
    }
}

bool Dictionnaire::recherche(const string& nom, Tuile& resultat)
{
    int middle, start, last, ind;
    bool found;
    start = 0;
    last = _vecTuile.size() - 1;
    ind = -1;
    found = false;
    while (!found && start <= last)
    {
        middle = (start + last) / 2;
        found = _vecTuile[middle].getName() == nom;
        if (found) ind = middle;
        else
        {
            if (_vecTuile[middle].getName() < nom) start = middle + 1;
            else last = middle - 1;
        }
    }
    if (found)
        resultat = _vecTuile[ind];
    return (found);
}
