# https://www.youtube.com/watch?v=-riHEHGP2DU	tuto
# <cible> : <dependance>
#	<commande>

#Variables spéciales
# $@ nom cible
# $< nom première dépendance
# $^ liste dépendance
# $? liste dépendance plus récentes que la cible
# $* nom fichier sans son extension

#Pour utiliser une variable on utilise:  $('nomDeLaVariable')

CC = gcc 
RM = rm
EXEC = prog
SRC = $(wildcard *.c) # SRC = player.c main.c
OBJ = $(SRC:.c=.o)	#on remplace l'extension .c des SRC par .o
HEAD = $(wildcard *.h)

.PHONY : all
all : $(EXEC)

%.o : %.c
	$(CC) -o $@ -c $<

$(EXEC) : $(OBJ)
	$(CC) -o $@ $^

.PHONY : clean
clean :
	rm -rf $(OBJ)

cleanall : clean
	rm -rf prog 
