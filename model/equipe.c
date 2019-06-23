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
    char * nom = malloc(sizeof(char)*32);
    char * continent = malloc(sizeof(char)*32);
    char * selectionneur = malloc(sizeof(char)*32);
    unsigned char nbetoile;
    unsigned short fifa;
    unsigned char nbJoueuse;
    char buf[32];

    printf("Nom de l'équipe : ");
    scanf("%s", buf);
    strcpy(nom,buf);

    printf("Continent : ");
    scanf("%s", buf);
    strcpy(continent,buf);

    printf("Nom du selectionneur : ");
    scanf("%s", buf);
    strcpy(selectionneur,buf);

    printf("Quel est le score FIFA ? : ");
    scanf("%s", buf);
    fifa = atoi(buf);

    printf("Combien de coupe du monde as t elle gagnée ? : ");
    scanf("%s", buf);
    nbetoile = atoi(buf);

    EQUIPE * equipe = creerEquipe(nom,continent,selectionneur,NULL,fifa,NULL);

    for (unsigned char i = 0; i < nbetoile; i++) {
      ajouterEtoile(saisirEtoile(),equipe);
    }

    printf("Combien de joueuse il y a-t-il dans cette equipe ? : ");
    scanf("%s", buf);
    nbJoueuse = atoi(buf);

    printf("Veuillez inserez les joueuses : \n");
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

        if(courant->annee > etoile->annee){
          precedant = ajouterEtoileEntre(precedant,etoile); //cas où l'étoile entrée est plus ancienne que toutes les autres
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

      if(courant->numero > joueuse->numero){
        precedant = ajouterJoueuseEntre(precedant,joueuse); //cas où la position entrée est plus grande à toutes les autres
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

EQUIPE * trierEquipeFIFA  (EQUIPE * tete){
  if(tete != NULL && tete->suivant != NULL){
    EQUIPE * precedant = tete;
    EQUIPE * courant = tete->suivant;

    while(courant != NULL){
      if(precedant->fifa < courant->fifa){
        precedant->suivant = courant->suivant;
        courant->suivant = NULL;
        tete = ajouterEquipeFIFA(tete,courant);
        courant = tete;
      }
      courant = courant->suivant;
    }
  }
  return tete;
}

EQUIPE * ajouterEquipeFIFA  (EQUIPE * tete, EQUIPE * new){
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

      if(courant->fifa < new->fifa){
        precedant = ajouterEquipeEntre(precedant,new);
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

EQUIPE * trierEquipeEtoile  (EQUIPE * tete){
  if(tete != NULL && tete->suivant != NULL){//Si la liste est vide ou contient qu'un élément on cosidère qu'elle est triée
    EQUIPE * precedant = tete;
    EQUIPE * courant = tete->suivant;
    //Lo'bjectif est de replacer dans la liste les éléments non triés en les enlevant et en les remplacants à l'aide de la fonction ajout
    while(courant != NULL){
      if(countEtoile(precedant->etoile) < countEtoile(courant->etoile)){//Si le nombre d'étoile n'est pas cohérent avec l'ordre
        precedant->suivant = courant->suivant; //On dissocie l'élément que l'on veut trier de la liste
        courant->suivant = NULL;
        tete = ajouterEquipeEtoile(tete,courant); //On ajoute l'élément en prenant en compte l'ordre désiré
        courant = tete; //On repart du début
      }
      courant = courant->suivant;
    } // On quitte uniquement si la liste est triée
  }
  return tete;
}

EQUIPE * ajouterEquipeEtoile (EQUIPE * tete, EQUIPE * new){
  if(tete == NULL){
    tete = new;
  }
  else{
    EQUIPE * precedant = tete;
    EQUIPE * courant = tete->suivant;

    if(courant == NULL){ //true quand il n'y a qu'un element dans la liste tete
      if(countEtoile(precedant->etoile) > countEtoile(new->etoile)){
        tete = ajouterEquipeFin(precedant,new);
      }
      else{
        tete = ajouterEquipeDebut(precedant,new);
      }
    }

    else{//cas où il y a 2 elem ou plus
      while(courant->suivant != NULL && countEtoile(courant->etoile) > countEtoile(new->etoile)){
        precedant = courant;
        courant = courant->suivant;
      }

      if(countEtoile(precedant->etoile) < countEtoile(new->etoile)){
        tete = ajouterEquipeDebut(precedant,new);
      }

      if(countEtoile(courant->etoile) < countEtoile(new->etoile)){
        precedant = ajouterEquipeEntre(precedant,new);
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

JOUEUSE * classementJoueuseSelection(EQUIPE * tete){
  JOUEUSE * joueuses = NULL;
  EQUIPE * equipeCourant = tete;
  JOUEUSE * joueuseCourant = NULL;
  while (equipeCourant != NULL) {
    joueuseCourant = equipeCourant->joueuse;
    while (joueuseCourant != NULL) {
      joueuses = ajouterJoueuseSelection(joueuses,copieJoueuse(joueuseCourant));
      joueuseCourant = joueuseCourant->suivant;
    }
    equipeCourant = equipeCourant->suivant;
  }

  return joueuses;
}

unsigned char statistique(EQUIPE * equipe1, EQUIPE * equipe2){
  switch (abs((int) (equipe1->fifa-equipe2->fifa))%5) {
    case 0:
    return 50;

    case 1:
    return 60;

    case 2:
    return 75;

    default:
    return 90;
  }
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
