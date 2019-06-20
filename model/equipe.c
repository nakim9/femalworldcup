#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "equipe.h"

EQUIPE * creerEquipe  (char * nom, char * continent, char * selectionneur, ETOILE * etoile, unsigned short fifa, JOUEUSE * joueuse){
  EQUIPE * equipe = NULL;
  equipe = malloc(sizeof(EQUIPE));
  if(equipe == NULL) return NULL;
  equipe->nom = nom;
  equipe->continent = continent;
  equipe->selectionneur = selectionneur;
  equipe->etoile = NULL;
  equipe->fifa = fifa;
  equipe->nbjoueuse = 0;
  equipe->joueuse = NULL;

  return equipe;
}

EQUIPE * saisirEquipe  (void){
    char nom[32];
    char continent[32];
    char selectionneur[32];
    unsigned char nbetoile;
    unsigned short fifa;
    unsigned char nbJoueuse;
    char buf[32];

    puts("Nom de l'équipe : ");
    scanf("%s\n", buf);
    strcpy(nom,buf);

    puts("Continent : ");
    scanf("%s\n", buf);
    strcpy(continent,buf);

    puts("Quel est le score FIFA ? : ");
    scanf("%s\n", buf);
    fifa = atoi(buf);

    puts("Combien de coupe du monde as t elle gagnée ? : ");
    scanf("%s\n", buf);
    nbetoile = atoi(buf);

    EQUIPE * equipe = creerEquipe(nom,continent,selectionneur,NULL,fifa,NULL);

    for (unsigned char i = 0; i < nbetoile; i++) {
      ajouterEtoile(saisirEtoile(),equipe);
    }

    puts("Combien de joueuse il y a-t-il dans cette equipe ? : ");
    scanf("%s\n", buf);
    nbJoueuse = atoi(buf);

    puts("Veuillez inserez les joueuses : \n");
    for (unsigned char i = 0; i < nbJoueuse; i++) {
      ajouterJoueuse(saisirJoueuse(), equipe);
    }

    return equipe;
}

ETOILE * ajouterEtoile(ETOILE * etoile, EQUIPE * equipe){
    if(equipe == NULL) return NULL;

    ETOILE * tete = equipe->etoile;

    if(tete == NULL){
      tete = etoile;
    }
    else{
      ETOILE * precedant = tete;
      ETOILE * courant = tete->suivant;

      if(courant == NULL){ //true quand il n'y a qu'un element dans la liste tete
        if(precedant->annee < etoile->annee){
          tete = ajouterEtoileFin(precedant,etoile);
        }
        else{
          tete = ajouterEtoileDebut(precedant,etoile);
        }
      }

      else{//cas où il y a 2 elem ou plus
        while(courant->suivant != NULL && courant->annee < etoile->annee){
          precedant = courant;
          courant = courant->suivant;
        }

        if(precedant->annee > etoile->annee){

          tete = ajouterEtoileDebut(precedant,etoile); //cas où l'étoile entrée est plus ancienne que toutes les autres
        }
        else{
          if(courant->suivant == NULL){
            courant = ajouterEtoileFin(courant,etoile); //cas où l'étoile est plus récente que toutes les autres
          }
          else{
            courant = ajouterEtoileEntre(courant, etoile); //Cas où l'année de l'étoile est comprise entre deux autres
          }
        }
      }
    }
    equipe->etoile = tete;
    return tete;
}

JOUEUSE * ajouterJoueuse(JOUEUSE * joueuse, EQUIPE * equipe){
  if(equipe == NULL) return NULL;

  JOUEUSE * tete = equipe->joueuse;

  if(tete == NULL){
    tete = joueuse;
  }
  else{
    JOUEUSE * precedant = tete;
    JOUEUSE * courant = tete->suivant;

    if(courant == NULL){ //true quand il n'y a qu'un element dans la liste tete
      if(precedant->numero < joueuse->numero){
        tete = ajouterJoueuseFin(precedant,joueuse);
      }
      else{
        tete = ajouterJoueuseDebut(precedant,joueuse);
      }
    }

    else{//cas où il y a 2 elem ou plus
      while(courant->suivant != NULL && courant->numero < joueuse->numero){
        precedant = courant;
        courant = courant->suivant;
      }

      if(precedant->numero > joueuse->numero){
        tete = ajouterJoueuseDebut(precedant,joueuse); //cas où la position entrée est plus grande à toutes les autres
      }
      else{
        if(courant->suivant == NULL){
          courant = ajouterJoueuseFin(courant,joueuse); //cas où la position est plus petite que toutes les autres
        }
        else{
          courant = ajouterJoueuseEntre(courant,joueuse); //Cas où la position de la joueuse est comprise entre deux autres (ou egale à une autre)
        }
      }
    }
  }
  equipe->nbjoueuse++;
  equipe->joueuse = tete;
  return tete;
}

EQUIPE * ajouterEquipe(EQUIPE * tete, EQUIPE * new){
  if(tete == NULL){
    tete = new;
  }
  else{
    EQUIPE * precedant = tete;
    EQUIPE * courant = tete->suivant;

    if(courant == NULL){ //true quand il n'y a qu'un element dans la liste tete
      if(precedant->fifa > new->fifa){
        tete = ajouterEquipeFin(precedant,new);
      }
      else{
        tete = ajouterEquipeDebut(precedant,new);
      }
    }

    else{//cas où il y a 2 elem ou plus
      while(courant->suivant != NULL && courant->fifa > new->fifa){
        precedant = courant;
        courant = courant->suivant;
      }

      if(precedant->fifa < new->fifa){
        tete = ajouterEquipeDebut(precedant,new);
      }
      else{
        if(courant->suivant == NULL){
          courant = ajouterEquipeFin(courant,new);
        }
        else{
          courant = ajouterEquipeEntre(courant, new);
        }
      }
    }
  }
  return tete;
}

EQUIPE * ajouterEquipeDebut (EQUIPE * tete, EQUIPE * new){
  if(new == NULL) return tete;
  if(tete == NULL) return new;

  new->suivant = tete;

  return new;
}

EQUIPE * ajouterEquipeFin   (EQUIPE * tete, EQUIPE * new){
  if(new == NULL) return tete;
  if(tete == NULL) return new;

  EQUIPE * courant = NULL;
  courant = tete;

  while(courant->suivant != NULL){
    courant = courant->suivant;
  }

  courant->suivant = new;

  return tete;
}

EQUIPE * ajouterEquipeEntre (EQUIPE * tete, EQUIPE * new){
  if(new == NULL) return tete;
  if(tete == NULL) return new;

  EQUIPE * suivant = tete->suivant;
  tete->suivant = new;
  new->suivant = suivant;

  return tete;
}
