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
  joueuse->suivant = NULL;

  return joueuse;
}

JOUEUSE * saisirJoueuse (void){
  char buf[32];
  char * nom = malloc(sizeof(char)*32);
  char * prenom = malloc(sizeof(char)*32);
  unsigned char numero;
  char * position = malloc(sizeof(char)*32);
  unsigned char selection;
  unsigned char titulaire;

  puts("\nSaisir :");
  printf("Nom de la joueuse : ");
  scanf("%s", buf);
  strncpy(nom,buf,32);

  printf("Prénom de la joueuse : ");
  scanf("%s", buf);
  strcpy(prenom,buf);

  printf("Numéro de maillot : ");
  scanf("%s", buf);
  numero = atoi(buf);

  printf("Position sur le terrain : ");
  scanf("%s", buf);
  strcpy(position,buf);

  printf("Combien de fois cette joueuse a été selectionnée ? : ");
  scanf("%s", buf);
  selection = atoi(buf);

  printf("Est-elle titulaire ? (o/n) : ");
  scanf("%s", buf);
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

JOUEUSE * copieJoueuse(JOUEUSE * joueuse){
  return creerJoueuse(joueuse->nom,joueuse->prenom,joueuse->numero,joueuse->position,joueuse->selection,joueuse->titulaire);
}

JOUEUSE * ajouterJoueuseSelection(JOUEUSE * tete, JOUEUSE * new){
  if(tete == NULL){
    tete = new;
  }
  else{
    JOUEUSE * precedant = tete;
    JOUEUSE * courant = tete->suivant;

    if(courant == NULL){ //true quand il n'y a qu'un element dans la liste tete
      if(precedant->selection > new->selection){
        tete = ajouterJoueuseFin(precedant,new);
      }
      else{
        tete = ajouterJoueuseDebut(precedant,new);
      }
    }

    else{//cas où il y a 2 elem ou plus
      while(courant->suivant != NULL && courant->selection > new->selection){
        precedant = courant;
        courant = courant->suivant;
      }

      if(precedant->selection < new->selection){
        tete = ajouterJoueuseDebut(precedant,new);
      }
      if(courant->selection < new->selection){
        courant = ajouterJoueuseEntre(precedant,new);
      }
      else{
        if(courant->suivant == NULL){
          courant = ajouterJoueuseFin(courant,new);
        }
        else{
          courant = ajouterJoueuseEntre(precedant, new);
        }
      }
    }
  }
  return tete;
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
