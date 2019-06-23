#ifndef JOUEUSE_H
#define JOUEUSE_H

typedef struct joueuse{
  char * nom;
  char * prenom;
  unsigned char numero;
  char * position;
  unsigned char selection;
  unsigned char titulaire; //Pseudo Boolean : 0 -> non titulaire ; 1 -> titulaire
  struct joueuse * suivant;
}JOUEUSE;

JOUEUSE * creerJoueuse(char * nom, char * prenom, unsigned char numero,  char * position, unsigned char selection, unsigned char titulaire);
JOUEUSE * saisirJoueuse (void);
JOUEUSE * copieJoueuse(JOUEUSE * joueuse); //alloue un nouvel espace memoire pour la joueuses (utiles pour ajouter une joueuse dans une autre liste sans la supprimer de cette liste)

JOUEUSE * ajouterJoueuseSelection(JOUEUSE * tete, JOUEUSE * new);
unsigned char countJoueuse(JOUEUSE * joueuse);//retourne le nombre de joueuse dans la liste joueuse

/* Fonctions utils pour le bon fonctionnement de la liste */
JOUEUSE * ajouterJoueuseFin(JOUEUSE * tete, JOUEUSE * new);
JOUEUSE * ajouterJoueuseDebut(JOUEUSE * tete, JOUEUSE * new);
JOUEUSE * ajouterJoueuseEntre(JOUEUSE * tete, JOUEUSE * new);



#endif
