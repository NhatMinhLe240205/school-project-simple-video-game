#include "Objet.h"

using namespace std;

Objet::Objet(const Image& Image, const string& name, Dictionnaire& Dictionnaire, int posx, int posy)
{
    _posOb_x = posx *TAILLE_CASE;
    _posOb_y = posy *TAILLE_CASE;
    _name =name;
    Tuile temp ("joyeux",-1,-1,"cache");
    int posTx, posTy;
    Dictionnaire.recherche(name, temp);
    posTx = temp.getPosx() * TAILLE_CASE;
    posTy = temp.getPosy() * TAILLE_CASE;
    _image = Image;
    _image.selectionnerRectangle(posTx, posTy, TAILLE_CASE, TAILLE_CASE);
    _propriete = temp.getProperty();
}

void Objet::dessiner() const
{
    _image.dessiner(_posOb_x , _posOb_y );
}

void Objet::cacher()
{
    _propriete = "cache";
}
