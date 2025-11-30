#ifndef DICTIONNAIRE_H
#define DICTIONNAIRE_H

#include "Tuile.h"
#include <vector>

using namespace std;

class Dictionnaire
{
    vector<Tuile> _vecTuile;
public:

    /// Constructeur de dictionnaire de tuile
    Dictionnaire(const string& fichier="assets/dictionnaire.txt");

    /// Appelle la méthode afficher de la classe Tuile sur chaque objet dans le vecteur de tuiles
    void afficher() const;

    /// Prends le nom d’une tuile que l’on recherche en paramètre. La méthode renvoie un booléen : true si l’élément a été trouvé, false sinon.
    /// Question 8 : On a utilisé un algorithme de recherche dichotomique.
    bool recherche(const string& nom, Tuile& resultat);
};

#endif
