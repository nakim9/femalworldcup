#include <stdio.h>
#include <stdlib.h>
#include "model/equipe.h"
#include "affichage/a_equipe.h"
#include "model/fileio.h"

int main(int argc, char const *argv[]) {
  EQUIPE * monequipe = load("MONDIAL2019.txt");
  puts("si vide");
  /*First Team */
  EQUIPE * premiere = creerEquipe("France","Europe","Tangui",NULL,999,NULL);
  puts("first team créée");
  ajouterJoueuse(creerJoueuse("Sigalas","Florian",1,"defenseur",3,1),premiere);
  ajouterJoueuse(creerJoueuse("Callonico","Florian",2,"attaquant",5,1),premiere);
  ajouterJoueuse(creerJoueuse("Sirjean","Clement",5,"centre",1,1),premiere);
  puts("joueurs ajoutés");
  ajouterEtoile(creerEtoile(1998), premiere);
  ajouterEtoile(creerEtoile(2010),premiere);
  ajouterEtoile(creerEtoile(2014),premiere);
  monequipe = ajouterEquipe(monequipe,premiere);
  puts("seconde");
  /* Second Team */
  EQUIPE * second = creerEquipe("Canada","America","Jason",NULL,15,NULL);

  ajouterJoueuse(creerJoueuse("Leborgne","Laury",11,"goal",1,0),second);
  ajouterJoueuse(creerJoueuse("Greck","Lucas",7,"defenseur",2,1),second);
  ajouterJoueuse(creerJoueuse("Petit","Nicolas",6,"centre",4,1),second);

  ajouterEtoile(creerEtoile(1994), second);
  ajouterEtoile(creerEtoile(2006),second);
  ajouterEtoile(creerEtoile(2018),second);

  monequipe = ajouterEquipe(monequipe,second);



  afficheListeEquipe(monequipe);
  save(monequipe, "MONDIAL2019.txt");
  return 0;
}
