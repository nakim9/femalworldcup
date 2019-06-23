#ifndef ETOILE_H
#define ETOILE_H

typedef struct etoile{
  unsigned short annee;
  struct etoile * suivant;
}ETOILE;

ETOILE * creerEtoile (unsigned short annee);
ETOILE * saisirEtoile  (void);

unsigned char countEtoile(ETOILE * etoile);

/* Fonctions utils pour le bon fonctionnement de la liste */
ETOILE * ajouterEtoileDebut(ETOILE * tete, ETOILE * new);
ETOILE * ajouterEtoileFin(ETOILE * tete, ETOILE * new);
ETOILE * ajouterEtoileEntre(ETOILE * tete, ETOILE * new);

#endif
