#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "a_equipe.h"

void  afficheEtoile  (ETOILE * etoile){
  printf("%hu ", etoile->annee);
}

void  afficheListeEtoile  (ETOILE * etoile){
  if(etoile == NULL){
    puts("Cette equipe n'a pas encore gagné de coupe du monde");
  }
  else{
    ETOILE * courant = etoile;
    if(etoile->suivant != NULL){
      puts("Voici les années d'obtention des étoiles");
    }
    else{
      puts("Voici l'année d'obtention de l'étoile");
    }
    printf("  ");
    while(courant != NULL){
        afficheEtoile(courant);
        courant = courant->suivant;
    }
  }
  puts("\n");
}

void  afficheJoueuse (JOUEUSE * joueuse){
  printf("%s %s %hhu\n", joueuse->nom, joueuse->prenom, joueuse->numero);
  printf("Poste : %s\n", joueuse->position);
  printf("Elle a été séléctionnée %hhu fois\n", joueuse->selection);
  if (joueuse->titulaire > 0) {
    puts("Elle est titulaire !");
  }
  else{
    puts("Elle n'est pas titulaire");
  }
  printf("\n");
}

void  afficheListeJoueuse (JOUEUSE * joueuse){
  if(joueuse == NULL){
    puts("Cette equipe n'a pas de joueuse");
  }
  else{
    puts("Voici la liste des joueuses :");
    JOUEUSE * courant = joueuse;
    while (courant != NULL) {
      afficheJoueuse(courant);
      courant = courant->suivant;
    }
  }
}

void  afficheEquipe  (EQUIPE * equipe){
  printf("%s (%s)\n", equipe->nom, equipe->continent);
  printf("%s\n", equipe->selectionneur);
  afficheListeEtoile(equipe->etoile);
  printf("Score FIFA : %hu\n", equipe->fifa);
  afficheListeJoueuse(equipe->joueuse);
}

void  afficheListeEquipe  (EQUIPE * equipe){
  EQUIPE * courant = equipe;
  while (courant != NULL) {
    afficheEquipe(courant);
    if(courant->suivant != NULL) puts("|--------------------------------------------|\n");
    courant = courant->suivant;
  }
  printf("\n");
}
