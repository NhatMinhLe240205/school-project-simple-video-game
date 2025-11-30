#ifndef OBJET_H
#define OBJET_H

#include "Dictionnaire.h"
#include "Image.h"
#include <vector>
#include <string>

using namespace std;

class Objet
{
    Image _image;
    int _posOb_x; ///(dans le niveau pas dans les sprites)
    int _posOb_y; ///(dans le niveau pas dans les sprites)
    string _propriete;
    string _name;
public:

    /// Constructeur d'objet
    Objet(const Image& Image, const string& name, Dictionnaire& Dictionnaire, int posx, int posy);

    /// Dessine l'image de l'objet aux coordonnees voulues
    void dessiner() const;

    /// Retourne propriete
    string getProperty() const {return _propriete;};
    string getName() const {return _name;};
    /// Retourne position X de l'objet
    int getPosOb_x() const {return _posOb_x;};

    /// Retourne position Y de l'objet
    int getPosOb_y() const {return _posOb_y;};

    void cacher();

};

#endif
