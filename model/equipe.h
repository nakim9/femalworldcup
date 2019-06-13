enum continent {AMERIQUE NORD, AMERIQUE SUD, EUROPE, AFRIQUE, ASIE, OCEANIE, ANTARTIQUE};

typedef struct etoile{
  unsigned short annee;
  struct etoile * suivant;
}ETOILE;

typedef struct joueuse{
  char * nom;
  char * prenom;
  unsigned char numero;
  char * position;
  unsigned char selection;
  unsigned char titulaire;
  struct joueuse * suivant;
}JOUEUSE;

typedef struct equipe{
  char * nom;
  continent continent;
  char * selectionneur;
  ETOILE * etoile;
  unsigned char fifa;
  JOUEUSE * joueuse;
}EQUIPE;

ETOILE  creerEtoile (unsigned short annee, ETOILE * suivant);
JOUEUSE creerJoueuse(char * nom, char * prenom, unsigned char numero, char * position, unsigned char titulaire, JOUEUSE * suivant);
EQUIPE  creerEquipe (char * nom, continent continent, char * selectionneur, ETOILE * etoile, unsigned char fifa, JOUEUSE * equipe);

ETOILE  saisirEtoile  (void);
JOUEUSE saisirJoueuse (void);
EQUIPE  saisirEquipe  (void);

int ajouterJoueuse(JOUEUSE * joueuse, EQUIPE * equipe);
