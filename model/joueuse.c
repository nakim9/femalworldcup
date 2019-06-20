#include "joueuse.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

JOUEUSE * creerJoueuse(char * nom, char * prenom, unsigned char numero,  char * position, unsigned char selection, unsigned char titulaire){
  JOUEUSE * joueuse = NULL;
  joueuse = malloc(sizeof(JOUEUSE));
  if(joueuse == NULL) return NULL;

  joueuse->nom = nom;
  joueuse->prenom= prenom;
  joueuse->numero = numero;
  joueuse->position = position;
  joueuse->selection = selection;
  joueuse->titulaire = titulaire;

  return joueuse;
}

JOUEUSE * saisirJoueuse (void){
  char buf[32];
  char nom[32];
  char prenom[32];
  unsigned char numero;
  char position[32];
  unsigned char selection;
  unsigned char titulaire;

  puts("Saisir : \n");
  puts("Nom de la joueuse : ");
  scanf("%s\n", buf);
  strcpy(nom,buf);

  puts("Prénom de la joueuse : ");
  scanf("%s\n", buf);
  strcpy(prenom,buf);

  puts("Numéro de maillot : ");
  scanf("%s\n", buf);
  numero = atoi(buf);

  puts("Position sur le terrain : ");
  scanf("%s\n", buf);
  strcpy(position,buf);

  puts("Combien de fois cette joueuse a été selectionnée ? : ");
  scanf("%s\n", buf);
  selection = atoi(buf);

  puts("Est-elle titulaire ? (o/n) : ");
  scanf("%s\n", buf);
  if(strcmp(buf,"o") == 0){
    titulaire = 1;//elle est titulaire
  }
  else{
    titulaire = 0; //elle est remplacante
  }

  JOUEUSE * joueuse = NULL;
  joueuse = creerJoueuse(nom, prenom, numero, position, selection, titulaire);
  if(joueuse == NULL) return NULL;

  return joueuse;
}


JOUEUSE * ajouterJoueuseDebut(JOUEUSE * tete, JOUEUSE * new){
  if(new == NULL) return tete;
  if(tete == NULL) return new;

  new->suivant = tete;

  return new;
}
JOUEUSE * ajouterJoueuseFin(JOUEUSE * tete, JOUEUSE * new){
  if(new == NULL) return tete;
  if(tete == NULL) return new;

  JOUEUSE * courant = NULL;
  courant = tete;

  while(courant->suivant != NULL){
    courant = courant->suivant;
  }

  courant->suivant = new;

  return tete;
}
JOUEUSE * ajouterJoueuseEntre(JOUEUSE * tete, JOUEUSE * new){
  if(new == NULL) return tete;
  if(tete == NULL) return new;

  JOUEUSE * suivant = tete->suivant;
  tete->suivant = new;
  new->suivant = suivant;

  return tete;
}

unsigned char countJoueuse(JOUEUSE * joueuse){
  unsigned char count = 0;

  JOUEUSE * courant = joueuse;

  while (courant != NULL) {
    count++;
    courant = courant->suivant;
  }

  return count;
}
