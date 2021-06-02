OBJ = init.o main.o data.o print.o

p: $(OBJ)
	gcc -Wall -o p $(OBJ) -lm

init.o: init.c defs.h
	gcc -c init.c

main.o: main.c defs.h
	gcc -c main.c

data.o: data.c defs.h
	gcc -c data.c

print.o: print.c defs.h
	gcc -c print.c

clean: 
	rm -f p *.o