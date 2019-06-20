#ifndef JOUEUSE_H
#define JOUEUSE_H

typedef struct joueuse{
  char * nom;
  char * prenom;
  unsigned char numero;
  char * position;
  unsigned char selection;
  unsigned char titulaire;
  struct joueuse * suivant;
}JOUEUSE;

JOUEUSE * creerJoueuse(char * nom, char * prenom, unsigned char numero,  char * position, unsigned char selection, unsigned char titulaire);
JOUEUSE * saisirJoueuse (void);

JOUEUSE * ajouterJoueuseFin(JOUEUSE * tete, JOUEUSE * new);
JOUEUSE * ajouterJoueuseDebut(JOUEUSE * tete, JOUEUSE * new);
JOUEUSE * ajouterJoueuseEntre(JOUEUSE * tete, JOUEUSE * new);

unsigned char countJoueuse(JOUEUSE * joueuse);

#endif
