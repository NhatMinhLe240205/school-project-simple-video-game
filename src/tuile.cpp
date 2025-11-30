#include "Tuile.h"
#include <iostream>

using namespace std;

Tuile::Tuile(const string& nom, int posx, int posy, const string& propriete)
{
    _name = nom;
    _pos_x = posx;
    _pos_y = posy;
    _property = propriete;
}

void Tuile::afficher() const
{
    cout << _name << ": x=" << _pos_x << ", y=" << _pos_y << ", objet " << _property << endl;
}
