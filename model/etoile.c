#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "etoile.h"

ETOILE * creerEtoile (unsigned short annee){
  ETOILE * etoile = NULL;
  etoile = malloc(sizeof(ETOILE));
  if(etoile == NULL) return NULL;

  etoile->annee   = annee;
  etoile->suivant = NULL;

  return etoile; //etoile ne peut pas être NULL
}

ETOILE * saisirEtoile  (void){
  puts("Saisir l'année de l'étoile : ");
  char buf[5];
  unsigned short annee;
  scanf("%s", buf);
  annee = atoi(buf);

  ETOILE * etoile = NULL;
  etoile = creerEtoile(annee);

  return etoile; //etoile peut être NULL;
}

unsigned char countEtoile(ETOILE * etoile){
  unsigned char count = 0;

  ETOILE * courant = etoile;

  while (courant != NULL) {
    count++;
    courant = courant->suivant;
  }

  return count;
}


ETOILE * ajouterEtoileDebut(ETOILE * tete, ETOILE * new){
  if(new == NULL) return tete;
  if(tete == NULL) return new;

  new->suivant = tete;

  return new;
}
ETOILE * ajouterEtoileFin(ETOILE * tete, ETOILE * new){
  if(new == NULL) return tete;
  if(tete == NULL) return new;

  ETOILE * courant = NULL;
  courant = tete;

  while(courant->suivant != NULL){
    courant = courant->suivant;
  }

  courant->suivant = new;

  return tete;
}
ETOILE * ajouterEtoileEntre(ETOILE * tete, ETOILE * new){
  if(new == NULL) return tete;
  if(tete == NULL) return new;

  ETOILE * suivant = tete->suivant;
  tete->suivant = new;
  new->suivant = suivant;

  return tete;
}
