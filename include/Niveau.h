#ifndef NIVEAU_H
#define NIVEAU_H

#include <vector>
#include "Objet.h"
#include <string>

using namespace std;

class Niveau
{
    vector<Objet> _vecObjets;
    int _nbBonus;
    int _nbObNiveau;
public:

    /// Constructeur de niveau
    Niveau(const Image& Image, const string& nom_de_fichier, Dictionnaire& Dictionnaire);

    /// Dessine le niveau
    void dessiner() const;

    bool caseEstLibre(int posObx, int posOby);

    bool testerBonusEtPrendre(int posObx, int posOby);

    bool gagne();

    void display() const;
};

#endif
