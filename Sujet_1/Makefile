exec: main.o distance.o tableau.o
	gcc -o exec main.o distance.o tableau.o -lm

distance.o: distance.c 
	gcc -c -Wall distance.c  -lm

tableau.o: tableau.c
	gcc -c -Wall tableau.c 

main.o: main.c
	gcc -c -Wall main.c -o main.o 


clean : 
	rm -f exec *.o