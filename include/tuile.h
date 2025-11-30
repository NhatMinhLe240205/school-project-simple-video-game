#ifndef TUILE_H
#define TUILE_H

#include <string>
#include <iostream>

using namespace std;

class Tuile
{
    string _name;
    int _pos_x;
    int _pos_y;
    string _property;
public:

    /// Constructeur de tuile
    Tuile(const string& nom , int posx , int posy , const string& propriete );

    /// Affiche les attributs d'une tuile
    void afficher() const;

    /// Renvoie le nom d'une tuile
    string getName() const {return _name;};

    /// Renvoie la posx d'une tuile
    int getPosx() const {return _pos_x;};

    /// Renvoie la posy d'une tuile
    int getPosy() const {return _pos_y;};

    /// Renvoie la propriété d'une tuile
    string getProperty() const {return _property;};
};

#endif
