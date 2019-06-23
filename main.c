#include <stdio.h>
#include <stdlib.h>
#include "model/equipe.h"
#include "affichage/a_equipe.h"
#include "model/fileio.h"

EQUIPE * menuAffichage(EQUIPE * equipes);
EQUIPE * menuEquipe(EQUIPE * equipes);
EQUIPE * menuModification(EQUIPE * equipe);
EQUIPE * selectionnerEquipe(EQUIPE * tete, unsigned char id);
EQUIPE * equipesFictive(void);

int main(int argc, char const *argv[]) {
  EQUIPE * monequipe = load("MONDIAL2019.txt");
  char input;
  unsigned char idEquipe1;
  unsigned char idEquipe2;
  EQUIPE * equipe1;
  EQUIPE * equipe2;
  unsigned char stat;
  do{
    input = '9';
    puts("________________");
    puts("|     MENU     |");
    puts("|______________|");
    puts("Veuillez choisir une fonctionnalité à executer en inscrivant le numéro correspondant");
    puts("1. Afficher les equipes");
    puts("2. Modifier les équipes");
    puts("3. Afficher le classement des joueuses");
    puts("4. Calculer les probabilitées d'un match");
    puts("5. Créer des equipes fictives");
    puts("0. Quitter l'application");
    scanf("%s", &input);

    switch (input) {
      case '1':
        monequipe = menuAffichage(monequipe);
        break;

      case '2':
        monequipe = menuEquipe(monequipe);
        break;

      case '3':
        afficheListeJoueuseEquipe(classementJoueuseSelection(monequipe),monequipe);
        break;

      case '4':
        puts("Selectionnez les deux equipes qui s'affrontent (inserez le numero correspondant à l'ordre d'apparition d'apparition)");
        afficheListeEquipeStrict(monequipe);
        puts("(0 pour quitter)");
        puts("Première équipe :");
        scanf("%hhu", &idEquipe1);
        if(idEquipe1 == 0) break;
        puts("Deuxième équipe :");
        scanf("%hhu", &idEquipe2);
        if(idEquipe2 == 0) break;
        equipe1 = selectionnerEquipe(monequipe,idEquipe1);
        equipe2 = selectionnerEquipe(monequipe,idEquipe2);

        stat = statistique(equipe1,equipe2);
        puts("Voici nos prédictions :");
        if(equipe1->fifa >= equipe2->fifa){
          printf("%s %hhu%%/%hhu%% %s\n", equipe1->nom, stat, (unsigned char) 100-stat, equipe2->nom);
        }
        else{
          printf("%s %hhu%%/%hhu%% %s\n", equipe1->nom, (unsigned char) 100-stat, stat, equipe2->nom);
        }
        break;

      case '5':
        monequipe = equipesFictive();
        break;

      default:
        break;
    }
  }while(input!='0');
  save(monequipe, "MONDIAL2019.txt");
  return 0;
}


EQUIPE * menuAffichage(EQUIPE * equipes){
  char input;
  do{
    puts(" ");
    puts("Vous avez choisi \"Afficher les équipes\"");
    puts("1. Afficher les equipes par score FIFA");
    puts("2. Afficher les équipes par nombre d'étoiles");
    puts("0. Retour au menu principal");
    scanf("%c", &input);

    switch (input) {
      case '1':
        equipes = trierEquipeFIFA(equipes);
        afficheListeEquipe(equipes);
        break;

      case '2':
        equipes = trierEquipeEtoile(equipes);
        afficheListeEquipe(equipes);
        break;

      default :
        break;
    }
  }while(input!='0');

  return equipes;
}

EQUIPE * menuEquipe(EQUIPE * equipes){
  char input;
  unsigned char id;
  EQUIPE * equipe;
  do{
    puts(" ");
    puts("Vous avez choisi \"Modifier les équipes\"");
    puts("1. Créer/Ajouter une nouvelle équipe");
    puts("2. Modifier une équipe déjà existante");
    puts("0. Retour au menu principal");
    scanf("%c", &input);

    switch (input) {
      case '1':
        ajouterEquipeFIFA(equipes,saisirEquipe());
        break;

      case '2':
        puts("Selectionnez l'équipe à modifier (inserez le numero correspondant à l'ordre d'apparition d'apparition)");
        afficheListeEquipeStrict(equipes);
        puts("(0 pour quitter)");
        scanf("%hhu", &id);
        if(id == 0) break;
        equipe = selectionnerEquipe(equipes,id);
        equipe = menuModification(equipe);
        break;

      default :
        break;
    }
  }while(input!='0');

  return equipes;
}

EQUIPE * menuModification(EQUIPE * equipe){
  char input;
  do{
    puts(" ");
    afficheEquipeStrict(equipe);
    puts("Que voulez vous faire ?");
    puts("1. Ajouter une joueuse");
    puts("2. Ajouter une étoile");
    puts("0. Retour au menu précédant");
    scanf("%c", &input);

    switch (input) {
      case '1':
        ajouterJoueuse(saisirJoueuse(),equipe);
        break;

      case '2':
        ajouterEtoile(saisirEtoile(),equipe);
        break;

      default :
        break;
    }
  }while(input!='0');

  return equipe;
}

EQUIPE * selectionnerEquipe(EQUIPE * tete, unsigned char id){
  EQUIPE * courant = tete;
  unsigned char cmpt = 1;
  while (courant != NULL && cmpt == id) {
    courant = courant->suivant;
    cmpt++;
  }

  return courant;
}

EQUIPE * equipesFictive(void){
  EQUIPE * monequipe = NULL;
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
  monequipe = ajouterEquipeFIFA(monequipe,premiere);
  puts("seconde");
  /* Second Team */
  EQUIPE * second = creerEquipe("Canada","America","Jason",NULL,15,NULL);

  ajouterJoueuse(creerJoueuse("Leborgne","Laury",11,"goal",1,0),second);
  ajouterJoueuse(creerJoueuse("Greck","Lucas",7,"defenseur",2,1),second);
  ajouterJoueuse(creerJoueuse("Petit","Nicolas",6,"centre",4,1),second);

  ajouterEtoile(creerEtoile(1994), second);
  ajouterEtoile(creerEtoile(2006),second);
  ajouterEtoile(creerEtoile(2018),second);

  monequipe = ajouterEquipeFIFA(monequipe,second);

  return monequipe;
}
