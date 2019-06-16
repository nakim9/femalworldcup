#include <string.h>

ETOILE  creerEtoile (unsigned short annee, ETOILE * suivant){
  ETOILE * etoile = NULL;
  etoile = malloc(sizeof(ETOILE));
  if(etoile == NULL) return NULL;

  etoile->annee   = annee;
  etoile->suivant = suivant;

  return etoile;
}

JOUEUSE creerJoueuse(char * nom, char * prenom, unsigned char numero, char * position, unsigned char selection, unsigned char titulaire, JOUEUSE * suivant){
  JOUEUSE * joueuse = NULL;
  joueuse = malloc(sizeof(JOUEUSE));
  if(joueuse == NULL) return NULL;

  strcpy(joueuse->nom,nom);
  strcpy(joueuse->prenom,prenom);
  joueuse->numero = numero;
  strcpy(joueuse->position,position);
  joueuse->selection = selection;
  joueuse->titulaire = titulaire;
  joueuse->suivant = suivant;

  return joueuse;
}

EQUIPE  creerEquipe (char * nom, char *  continent, char * selectionneur, ETOILE * etoile, unsigned char fifa, JOUEUSE * equipe){
  EQUIPE * equipe = NULL;
  equipe = malloc(sizeof(EQUIPE));
  if(equipe == NULL) return NULL;

  strcpy(equipe->nom, nom);
  equipe->continent = continent;
  strcpy(equipe->selectionneur, selectionneur);
  equipe->etoile = etoile;
  equipe->fifa = fifa;
  equipe->joueuse = joueuse;

  return equipe;
}
ETOILE  saisirEtoile  (void){
  puts("Saisir l'année de l'étoile : ");
  char buf[5];
  unsigned short annee;
  scanf("%s\n", buf);
  atoi(annee,buf);

  ETOILE etoile = NULL;
  etoile = creerEtoile(annee,NULL);
  if(etoile == NULL) return NULL;

  return etoile;
}
JOUEUSE saisirJoueuse (void){
  char buf[32];
  char nom[32];
  char prenom[32];
  unsigned char numero;
  char position[32];
  unsigned char titulaire;

  puts("Saisir : \n");
  puts("Nom de la joueuse : ");
  scanf("%s\n", buf);
  strcpy(nom,buf);

  puts("Prénom de la joueuse : ");
  scanf("%s\n", buf);
  strcpy(prenom,buf);

  puts("Numéro de maillot : ");
  scanf("%s\n", buf);
  atoi(numero,buf);

  puts("Position sur le terrain : ");
  scanf("%s\n", buf);
  strcpy(position,buf);

  puts("Est-elle titulaire ? (o/n) : ");
  scanf("%s\n", buf);
  if(strcmp(buf,'o') == 0){
    titulaire = 1;//elle est titulaire
  }
  else{
    titulaire = 0; //elle est remplacante
  }

  JOUEUSE joueuse = NULL;
  joueuse = creerJoueuse(nom, prenom, numero, position, titulaire, NULL);
  if(joueuse == NULL) return NULL;

  retrun joueuse;
}

EQUIPE  saisirEquipe  (void){
    char buf nom[32];
    char continent[32];
    char selectionneur[32];
    unsigned char nbetoile;
    ETOILE * etoile;
    unsigned char fifa;
    JOUEUSE * equipe;
    char buf[32];

    puts("Nom de l'équipe : ");
    scanf("%s\n", buf);
    strcpy(nom,buf);

    puts("Continent : ");
    scanf("%s\n", buf);
    strcpy(continent,buf);

    puts("Quel est le score FIFA ? : ");
    scanf("%s\n", buf);
    atoi(fifa,buf);

    puts("Combien de coupe du monde as t elle gagnée ? : ");
    scanf("%s\n", buf);
    atoi(nbetoile,buf);

    for (unsigned char i = 0; i < nbetoile; i++) {
      saisirEtoile();
    }

    puts("Veuillez inserez les joueuses : \n");
}
