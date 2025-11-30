#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include "Image.h"
#include "Niveau.h"

class Personnage
{
    int _pos_x;
    int _pos_y;
    int _skin_x;
    int _skin_y;
    int _direction;
    Image _Image_personnage;
public:
    /// Constructeur vide
    Personnage();
    /// Constructeur de personnage
    Personnage(Image& Image, int x, int y, int sx, int sy, int d);

    ///Get pos X
    int getPos_x() const {return _pos_x;};

    ///Get pos Y
    int getPos_y() const {return _pos_y;};


    /// Dessine l'image du personnage aux coordonnees voulues
    void dessiner() const;

    /// Déplace le personnage d’une case dans la direction droite
    void allerDroite();

    /// Déplace le personnage d’une case dans la direction gauche
    void allerGauche();

    /// Déplace le personnage d’une case dans la direction haut
    void allerHaut();

    /// Déplace le personnage d’une case dans la direction bas
    void allerBas();

    /// Teste si une case est au bord
    bool bordAtteint(int x, int y) const;

    /// Choisit le bon rectangle (skin) selon la direction
    void mettreAJourDirection();

    /// Fait avancer l’ennemi dans sa direction courante
    void avancer(const Niveau& niveau);

    /// Teste si le personnage cible touche le personnage paramètre
    bool touche(const Personnage& ennemi) const;
};

#endif
