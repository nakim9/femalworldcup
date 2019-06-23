#include <string.h>
#include <stdlib.h>
#include "fileio.h"

#ifndef SEPARATOR
#define SEPARATOR ";"
#endif

/* Sauvegarde sur le disque / Ecriture fichier */
void save(EQUIPE * equipe, char * nomFic){
  FILE * file = NULL;
  file = fopen(nomFic,"w");
  if(file == NULL) exit(0);

  EQUIPE * courant = equipe;
  unsigned char nbJoueuseToWrite;
  JOUEUSE * joueuseCourant = NULL;
  unsigned char nbEtoileToWrite;
  ETOILE * etoileCourant = NULL;

  while(courant != NULL){
    writeEquipe(courant,file);

    joueuseCourant = courant->joueuse;
    nbJoueuseToWrite = countJoueuse(joueuseCourant);
    fprintf(file, "%hhu\n", nbJoueuseToWrite);
    while (joueuseCourant != NULL) {
      writeJoueuse(joueuseCourant,file);
      joueuseCourant = joueuseCourant->suivant;
    }

    etoileCourant = courant->etoile;
    nbEtoileToWrite = countEtoile(etoileCourant);
    fprintf(file, "%hhu\n", nbEtoileToWrite);
    while (etoileCourant != NULL) {
      writeEtoile(etoileCourant,file);
      etoileCourant = etoileCourant->suivant;
    }

    courant = courant->suivant;
  }

  fclose(file);
}

void writeEquipe(EQUIPE * equipe, FILE * file){
  fprintf(file, "%s;%s;%s;%hu\n", equipe->nom, equipe->continent, equipe->selectionneur, equipe->fifa);
}

void writeJoueuse(JOUEUSE * joueuse, FILE * file){
  fprintf(file, "%s;%s;%hhu;%s;%hhu;%hhu\n", joueuse->nom,joueuse->prenom,joueuse->numero,joueuse->position,joueuse->selection,joueuse->titulaire);
}

void writeEtoile(ETOILE * etoile, FILE * file){
  fprintf(file, "%hu\n", etoile->annee);
}

/* Chargement en mémoire / Lecture du fichier */
EQUIPE * load(char * nomFic){
  FILE * file = NULL;
  file = fopen(nomFic,"r");
  if(file == NULL) return NULL;

  EQUIPE * result = NULL;
  EQUIPE * courant = NULL;
  unsigned char nbJoueuseToRead = 0;
  unsigned char nbEtoileToRead = 0;
  char * buf;
  size_t bufsize = sizeof(buf)*4;
  buf = malloc(bufsize);
  if(buf == NULL) return NULL;
  if(getline(&buf,&bufsize,file) == EOF) return NULL;
  fseek(file,0,SEEK_SET);
  while(!feof(file)){
    fseek(file,-1,SEEK_CUR);
    courant = readEquipe(file);
    getline(&buf,&bufsize,file);
    nbJoueuseToRead = (unsigned char) atoi(buf);
    for (unsigned char i = 0; i < nbJoueuseToRead; i++) {
      ajouterJoueuse(readJoueuse(file),courant);
    }
    getline(&buf,&bufsize,file);
    nbEtoileToRead = (unsigned char) atoi(buf);
    for (unsigned char i = 0; i < nbEtoileToRead; i++) {
      ajouterEtoile(readEtoile(file),courant);
    }
    result = ajouterEquipeFIFA(result,courant);
    courant = NULL;
    fgetc(file);
  }
  fclose(file);
  return result;
}
EQUIPE * readEquipe(FILE * file){
  char * buf;
  size_t bufsize = sizeof(buf)*256;
  buf = malloc(bufsize);
  if(buf == NULL) return NULL;
  char * nom;
  char * continent;
  char * selectionneur;
  char * fifa;
  getline(&buf,&bufsize,file);
  nom = strtok(buf,SEPARATOR);
  continent = strtok(NULL,SEPARATOR);
  selectionneur = strtok(NULL,SEPARATOR);
  fifa = strtok(NULL,SEPARATOR);

  EQUIPE * equipe = NULL;
  equipe = creerEquipe(nom,continent,selectionneur,NULL,atoi(fifa),NULL);
  return equipe;
}
JOUEUSE * readJoueuse(FILE * file){
  char * buf;
  size_t bufsize = sizeof(buf)*256;
  buf = malloc(bufsize);
  if(buf == NULL) return NULL;
  char * nom;
  char * prenom;
  char * numero;
  char * position;
  char * selection;
  char * titulaire;

  getline(&buf,&bufsize,file);
  nom = strtok(buf,SEPARATOR);
  prenom = strtok(NULL,SEPARATOR);
  numero = strtok(NULL,SEPARATOR);
  position = strtok(NULL,SEPARATOR);
  selection = strtok(NULL,SEPARATOR);
  titulaire = strtok(NULL,SEPARATOR);

  JOUEUSE * joueuse = NULL;
  joueuse = creerJoueuse(nom,prenom,(unsigned char) atoi(numero),position,(unsigned char) atoi(selection),(unsigned char) atoi(titulaire));
  return joueuse;
}
ETOILE * readEtoile(FILE * file){
  char * buf;
  char * annee;
  size_t bufsize = sizeof(buf)*256;
  buf = malloc(bufsize);
  if(buf == NULL) return NULL;
  getline(&buf,&bufsize,file);
  annee = strtok(buf,SEPARATOR);

  ETOILE * etoile = NULL;
  etoile = creerEtoile(atoi(annee));
  return etoile;
}
