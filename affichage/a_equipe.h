#ifndef A_EQUIPE_H
#define A_EQUIPE_H
#include "../model/equipe.h"

void  afficheEtoile  (ETOILE * etoile);
void  afficheListeEtoile  (ETOILE * etoile);

void  afficheJoueuse (JOUEUSE * joueuse);
void  afficheListeJoueuse (JOUEUSE * joueuse);
void  afficheJoueuseParEquipe (JOUEUSE * joueuse, char * nomequipe);
void afficheListeJoueuseEquipe(JOUEUSE * joueuse, EQUIPE * tete);

void  afficheEquipe  (EQUIPE * equipe);
void  afficheListeEquipe  (EQUIPE * equipe);
void  afficheEquipeStrict  (EQUIPE * equipe);
void  afficheListeEquipeStrict  (EQUIPE * equipe);
#endif
