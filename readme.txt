ROBIN Tangui ITII1 TOULON 23/06/2019

Voici le code source du DM sur la coupe du monde de football féminine réalisé par Tangui ROBIN

Voici les fonctionnalitées implantées dans le programme
  - Affichage
    - Equipes par score FIFA (Tri à améliorer : l'algorithme de tri peut casser la liste des equipes)
    - Equipes par nombre d'étoiles obtenues (Tri à améliorer : l'algorithme de tri peut casser la liste des equipes)
    - Joueuses par nombres de selections
  - Ajout
    - d'une nouvelle equipe avec joueuses et années d'obtentions des étoiles
    - d'une joueuse dans une equipe déjà existante
    - d'une étoile pour une equipe déjà existante
  - Statistique de matchs
  - Sauvegarde dans un afficheListeEquipeStrict

Structure du fichier de sauvegarde

[NOM;CONTINENT;SELECTIONNEUR;NUMEROFIFA
NBJOUEUSE
[NOMJOUEUSE;PRENOMJOUEUSE;NUMEROJOUEUR;POSTEJOUEUR;NOMBREDESELECTION;0|1]
...
NBETOILE
[ANNEEETOILE]
...]
...

/////INSTALLATION//////

Afin de vous faciliter la tâche, un makefile est mis à votre disposition.
Pour débuter l'experience de ce programme veuillez  :
- ouvrir une console
- positionnez vous dans le repertoire de la racine du code source (là où ce trouve ce readme)
- executer la commande "make"
- puis la commande "./main"

Prerequis :
  - Logiciel Make
  - GNU Compiler Collection


//Autre//
Ce logiciel a été developpé à l'aide de les outils Atom, Git et Github
