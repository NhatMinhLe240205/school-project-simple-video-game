#include <vector>

#include "Moteur.h"
#include "Image.h"
#include "Personnage.h"
#include "Tuile.h"
#include "Dictionnaire.h"
#include "Objet.h"
#include "Niveau.h"

using namespace std;

int main(int, char**) // Version special du main, ne pas modifier
{
    /*int coffreX, coffreY;
    coffreX = coffreY = 0;
    bool coffre;
    coffre = false;*/
  // Initialisation du jeu
  Moteur moteur("Mon super jeu vidéo");

  // TODO: charger images, creer personnages, etc.
    try
    {
    Dictionnaire dictionnaire("assets/dictionnaire.txt");
    Personnage Heros;
    Personnage ennemi1;
    Personnage ennemi2;
    Image fond;
    Image P_Image;
    Image Objets;
    Image Bravo;
    Image Over;
    Niveau Test (Objets, "assets/niveau1.txt", dictionnaire);
    }
        catch (exception e){cout << e.what();}

    Dictionnaire dictionnaire("assets/dictionnaire.txt");
    Image fond (moteur, "assets/fond.png");
    Image P_Image (moteur, "assets/personnages.png");
    Image Objets (moteur, "assets/objets.png");
    Image Bravo (moteur, "assets/bravo.png");
    Image Over (moteur, "assets/gameover.png");
    Personnage Heros (P_Image, TAILLE_CASE, 2*TAILLE_CASE, 6, 0, 0);
    Personnage ennemi1 (P_Image, 5*TAILLE_CASE, TAILLE_CASE, 0, 0, 0);
    Personnage ennemi2 (P_Image, TAILLE_CASE, 5*TAILLE_CASE, 6, 4, 2);
    Niveau Test (Objets, "assets/niveau1.txt", dictionnaire);
    Test = Niveau(Objets, "assets/niveau1.txt", dictionnaire);

    /*Image coffre_ferme;
    try {
       coffre_ferme = Image(moteur, "assets/coffre_ferme.png");
    }
    catch(runtime_error){
    }
    Image coffre_ouvert;
    try {
       coffre_ouvert = Image(moteur, "assets/coffre_ouvert.png");
    }
    catch(runtime_error){
    }*/
    // (... et le catch pour traiter l'exception)

  bool quitter = false;

  // Boucle de jeu, appelee a chaque fois que l'ecran doit etre mis a jour
  // (en general, 60 fois par seconde)
  while (!quitter)
  {
    // I. Gestion des evenements
    Evenement evenement = moteur.evenementRecu();
    while (evenement != AUCUN)
    {
      switch (evenement)
      {
        // QUITTER = croix de la fenetre ou Echap
        case QUITTER_APPUYE:
          quitter = true;
          break;
        /*case ESPACE_APPUYE:
            coffre = !coffre;
            break;*/
        case GAUCHE_APPUYE:
            /*coffreX = coffreX - 16;*/
            if (Test.caseEstLibre(Heros.getPos_x() - TAILLE_CASE, Heros.getPos_y()))
            Heros.allerGauche();
            break;
        case DROITE_APPUYE:
            /*coffreX = coffreX + 16;*/
            if (Test.caseEstLibre(Heros.getPos_x() + TAILLE_CASE, Heros.getPos_y()))
            Heros.allerDroite();
            break;
        case HAUT_APPUYE:
            /*coffreY = coffreY - 16;*/
            if (Test.caseEstLibre(Heros.getPos_x(), Heros.getPos_y() - TAILLE_CASE))
            Heros.allerHaut();
            break;
        case BAS_APPUYE:
            /*coffreY = coffreY + 16;*/
            if (Test.caseEstLibre(Heros.getPos_x(), Heros.getPos_y() + TAILLE_CASE))
            Heros.allerBas();
            break;
        // TODO: gerer les autres evenements
        default:
          break;
      }

      evenement = moteur.evenementRecu();
    }

    // II. Mise à jour de l'état du jeu
    Test.testerBonusEtPrendre(Heros.getPos_x(), Heros.getPos_y());

    if (moteur.animationsAmettreAjour())
    {
      ennemi1.avancer(Test);
      ennemi2.avancer(Test);
    }
    quitter = ((Heros.touche(ennemi1) || Heros.touche(ennemi2)) || Test.gagne());


    // TODO: faire bouger vos personnages, etc.

    // III. Generation de l'image à afficher

    moteur.initialiserRendu(); // efface ce qui avait ete affiche precedemment et reinitalise en ecran noir
    fond.dessiner(0, 0);
    Test.dessiner();
    Heros.dessiner();
    ennemi1.dessiner();
    ennemi2.dessiner();

    if (Test.gagne()) Bravo.dessiner(2 * TAILLE_CASE, 3*TAILLE_CASE) ;
    else if (quitter) Over.dessiner(2 * TAILLE_CASE, 3 *TAILLE_CASE);

    //objet.dessiner();
    /*if (coffre) {coffre_ouvert.dessiner(coffreX, coffreY);}
    if (!coffre) {coffre_ferme.dessiner(coffreX, coffreY);}*/

    // TODO: afficher vos personnages, objets, etc.

    /*
      Affiche l'image en se cadencant sur la frequence de
      rafraichissement de l'ecran (donc va en general mettre le
      programme en pause jusqu'a ce que l'ecran soit rafraichi). En
      general, 60 images fois par seconde, mais ca peut dependre du
      materiel
    */
    moteur.finaliserRendu();
    if (quitter)
    {
        moteur.attendre(2);
    }
  }

  return 0;
}
