CC=gcc
FLAGS= -Wall
EXE=main

all : $(EXE) clean

main: main.o equipe.o joueuse.o etoile.o a_equipe.o fileio.o
	$(CC) -o $@ $^

main.o: main.c
	$(CC) -o $@ -c $< $(FLAGS)

joueuse.o: model/joueuse.c
	$(CC) -o $@ -c $< $(FLAGS)

equipe.o: model/equipe.c joueuse.o etoile.o
	$(CC) -o $@ -c $< $(FLAGS)

etoile.o: model/etoile.c
	$(CC) -o $@ -c $< $(FLAGS)

a_equipe.o: affichage/a_equipe.c equipe.o
	$(CC) -o $@ -c $< $(FLAGS)

fileio.o: model/fileio.c
	$(CC) -o $@ -c $< $(FLAGS)

clean :
	rm -rf *.o
