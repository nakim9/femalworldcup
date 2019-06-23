#ifndef EQUIPE_H
#define EQUIPE_H

#include "etoile.h"
#include "joueuse.h"

typedef struct equipe{
  char * nom;
  char * continent;
  char * selectionneur;
  ETOILE * etoile;
  unsigned short fifa;
  unsigned char nbjoueuse;
  JOUEUSE * joueuse;
  struct equipe * suivant;
}EQUIPE;


EQUIPE * creerEquipe  (char * nom, char * continent, char * selectionneur, ETOILE * etoile, unsigned short fifa, JOUEUSE * equipe);
EQUIPE * saisirEquipe (void);
/* Insertion par classement fifa */
EQUIPE * trierEquipeFIFA  (EQUIPE * tete);
EQUIPE * ajouterEquipeFIFA(EQUIPE * tete, EQUIPE * new);
/* Tri par numero de maillot */
JOUEUSE * ajouterJoueuse(JOUEUSE * joueuse, EQUIPE * equipe);
/* Tri par année */
ETOILE * ajouterEtoile(ETOILE * etoile, EQUIPE * equipe);

EQUIPE * trierEquipeEtoile(EQUIPE * tete);
EQUIPE * ajouterEquipeEtoile(EQUIPE * tete, EQUIPE * new);

unsigned char statistique(EQUIPE * equipe1, EQUIPE * equipe2);

/* Traitements sur l'ensemble des joueuses
  * Fait ici car on ne garde pas une liste entière de chaque joueuses donc recupère celle de chaque equipes
 */

JOUEUSE * classementJoueuseSelection(EQUIPE * tete);

/* Utilitaire pour la manipulation de la liste chainée*/

EQUIPE * ajouterEquipeDebut (EQUIPE * tete, EQUIPE * new);
EQUIPE * ajouterEquipeFin   (EQUIPE * tete, EQUIPE * new);
EQUIPE * ajouterEquipeEntre (EQUIPE * tete, EQUIPE * new);

#endif
