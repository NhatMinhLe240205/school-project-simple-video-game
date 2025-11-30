#include "Personnage.h"


Personnage::Personnage()
{

}

Personnage::Personnage(Image& Image, int x, int y, int sx, int sy, int d)
{
    _pos_x = x;
    _pos_y = y;
    _skin_x = sx;
    _skin_y = sy;
    _Image_personnage = Image;
    _direction = d;
    mettreAJourDirection();
}

void Personnage::dessiner() const
{
    _Image_personnage.dessiner(_pos_x, _pos_y);
}

void Personnage::allerDroite()
{
    if (!(bordAtteint(LARGEUR_FENETRE-TAILLE_CASE, HAUTEUR_FENETRE)))
    {
        _pos_x = _pos_x + TAILLE_CASE;
        _direction = 2;
        mettreAJourDirection();
    }
}

void Personnage::allerGauche()
{
    if (!(bordAtteint(0, -TAILLE_CASE) ))
    {
        _pos_x = _pos_x - TAILLE_CASE;
        _direction = 1;
        mettreAJourDirection();
    }
}

void Personnage::allerHaut()
{
    if (!(bordAtteint(-TAILLE_CASE, 0)))
    {
        _pos_y = _pos_y - TAILLE_CASE;
        _direction = 3;
        mettreAJourDirection();
    }
}

void Personnage::allerBas()
{
    if (!(bordAtteint(LARGEUR_FENETRE, HAUTEUR_FENETRE-TAILLE_CASE)))
    {
        _pos_y = _pos_y + TAILLE_CASE;
        _direction = 0;
        mettreAJourDirection();
    }
}

bool Personnage::bordAtteint(int x, int y) const
{
    bool bord;
    bord = (_pos_x == x || _pos_y  == y);
    return bord;
}

void Personnage::mettreAJourDirection()
{
    switch (_direction)
    {
        case 0: _Image_personnage.selectionnerRectangle((_skin_x+1)*TAILLE_CASE, (_skin_y)*TAILLE_CASE, TAILLE_CASE, TAILLE_CASE); break;
        case 1: _Image_personnage.selectionnerRectangle((_skin_x+1)*TAILLE_CASE, (_skin_y+1)*TAILLE_CASE, TAILLE_CASE, TAILLE_CASE); break;
        case 2: _Image_personnage.selectionnerRectangle((_skin_x+1)*TAILLE_CASE, (_skin_y+2)*TAILLE_CASE, TAILLE_CASE, TAILLE_CASE); break;
        case 3: _Image_personnage.selectionnerRectangle((_skin_x+1)*TAILLE_CASE, (_skin_y+3)*TAILLE_CASE, TAILLE_CASE, TAILLE_CASE); break;
    }
}

void Personnage::avancer(const Niveau& niveau)
{
    Niveau temp = niveau;
    if (_direction == 1 || _direction == 2)
    {
        if (_direction == 1 && temp.caseEstLibre(_pos_x - TAILLE_CASE, _pos_y) )
            _pos_x -= TAILLE_CASE;
        else if (_direction == 2 && temp.caseEstLibre(_pos_x + TAILLE_CASE, _pos_y))
            _pos_x += TAILLE_CASE;
        if (bordAtteint(LARGEUR_FENETRE-TAILLE_CASE, HAUTEUR_FENETRE) || bordAtteint(0, -TAILLE_CASE) || !temp.caseEstLibre(_pos_x - TAILLE_CASE, _pos_y) || !temp.caseEstLibre(_pos_x + TAILLE_CASE, _pos_y))
            {
                    switch (_direction)
                {
                case 1: _direction = 2; _Image_personnage.selectionnerRectangle((_skin_x+1)*TAILLE_CASE, (_skin_y+2)*TAILLE_CASE, TAILLE_CASE, TAILLE_CASE); break;
                case 2: _direction = 1; _Image_personnage.selectionnerRectangle((_skin_x+1)*TAILLE_CASE, (_skin_y+1)*TAILLE_CASE, TAILLE_CASE, TAILLE_CASE); break;
                }
            }
    }
    if(_direction == 0 || _direction == 3)
    {
        if (_direction == 0 && temp.caseEstLibre(_pos_x, _pos_y + TAILLE_CASE))
            _pos_y += TAILLE_CASE;
        else if (_direction == 3 && temp.caseEstLibre(_pos_x, _pos_y - TAILLE_CASE))
            _pos_y -= TAILLE_CASE;
        if (bordAtteint(LARGEUR_FENETRE, HAUTEUR_FENETRE-TAILLE_CASE) || (bordAtteint(-TAILLE_CASE, 0) || !temp.caseEstLibre(_pos_x, _pos_y + TAILLE_CASE) || !temp.caseEstLibre(_pos_x, _pos_y - TAILLE_CASE)))
        {
                    switch (_direction)
                {
                case 0: _direction = 3; _Image_personnage.selectionnerRectangle((_skin_x+1)*TAILLE_CASE, (_skin_y+3)*TAILLE_CASE, TAILLE_CASE, TAILLE_CASE); break;
                case 3: _direction = 0; _Image_personnage.selectionnerRectangle((_skin_x+1)*TAILLE_CASE, (_skin_y)*TAILLE_CASE, TAILLE_CASE, TAILLE_CASE); break;
                }
            }
}
}

bool Personnage::touche(const Personnage& ennemi) const
{
    bool toucher;
    toucher = (_pos_x == ennemi._pos_x && _pos_y == ennemi._pos_y);
    return toucher;
}
