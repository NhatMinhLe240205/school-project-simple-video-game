#include "Niveau.h"
#include <iostream>
#include <fstream>

using namespace std;

void Niveau::display() const
{
    cout << _nbObNiveau << endl;
    cout << _vecObjets.size() << endl;
    for (int i = 1; i < _vecObjets.size(); i++) cout << i << _vecObjets[i].getName() << endl;
}


Niveau::Niveau(const Image& Image, const string& nom_de_fichier, Dictionnaire& Dictionnaire)
{

    int nbObNiveau, i;
    i = 0;
    ifstream input;
    _nbBonus = 0;
    input.open(nom_de_fichier);
    if(!(input.is_open())) throw string ("Failure while opening file : " + nom_de_fichier);
    input >> nbObNiveau;
    _nbObNiveau = nbObNiveau;
    while(i < nbObNiveau)
    {
        string nom;
        int posx, posy;
        input >> nom;
        input >> posx;
        input >> posy;
        if (Objet(Image, nom, Dictionnaire, posx, posy).getProperty() == "bonus") _nbBonus ++;
        _vecObjets.push_back(Objet(Image, nom, Dictionnaire, posx, posy));
        i++;
    }
    input.close();
    if (_vecObjets.size()!= nbObNiveau) throw invalid_argument("Failure while loading the objects of file : " + nom_de_fichier);
}

void Niveau::dessiner() const
{

    for (int i=0; i<_vecObjets.size(); i++)
    {

        if (_vecObjets[i].getProperty()!="cache")
            _vecObjets[i].dessiner();
    }
}

bool Niveau::caseEstLibre(int x, int y)
{
    int i = _vecObjets.size();
    bool found = false;
    while (i >0 && !found )
    {
        i--;
        found = _vecObjets[i].getPosOb_x() == x && _vecObjets[i].getPosOb_y() == y;
    }
    if (found && _vecObjets[i].getProperty() == "solide" )
    {
        return false;
    }
    else
    {cout << _vecObjets[i].getName(); return true; }
}

bool Niveau::testerBonusEtPrendre(int x, int y)
{
    int i = _vecObjets.size();
    bool found = false;
    while (i >0 && !found )
    {
        i--;
        found = _vecObjets[i].getPosOb_x() == x && _vecObjets[i].getPosOb_y() == y;
    }
    if (found && _vecObjets[i].getProperty() == "bonus" )
    {
        _nbBonus --;
        _vecObjets[i].cacher();
    }
    else
    { return false; }
}

bool Niveau::gagne()
{
    if (_nbBonus == 0) return true;
    else return false;
}
