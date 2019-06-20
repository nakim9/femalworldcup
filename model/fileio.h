#ifndef FILEIO_H
#define FILEIO_H

#include <stdio.h>
#include "equipe.h"
/* Sauvegarde sur le disque / Ecriture fichier */
void save(EQUIPE * equipe, char * nomFic);
void writeEquipe(EQUIPE * equipe, FILE * file);
void writeJoueuse(JOUEUSE * joueuse, FILE * file);
void writeEtoile(ETOILE * etoile, FILE * file);

/* Chargement en mémoire / Lecture du fichier */
EQUIPE * load(char * nomFic);
EQUIPE * readEquipe(FILE * file);
JOUEUSE * readJoueuse(FILE * file);
ETOILE * readEtoile(FILE * file);
#endif
