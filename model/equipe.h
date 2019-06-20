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
EQUIPE * ajouterEquipe(EQUIPE * tete, EQUIPE * new);
JOUEUSE * ajouterJoueuse(JOUEUSE * joueuse, EQUIPE * equipe);
ETOILE * ajouterEtoile(ETOILE * etoile, EQUIPE * equipe);

EQUIPE * ajouterEquipeDebut (EQUIPE * tete, EQUIPE * new);
EQUIPE * ajouterEquipeFin   (EQUIPE * tete, EQUIPE * new);
EQUIPE * ajouterEquipeEntre (EQUIPE * tete, EQUIPE * new);

#endif
