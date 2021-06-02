OBJ = graphics.o init.o main.o entity.o
LIBS = -lncurses -lpthread

a4:	$(OBJ)
	gcc -o a4 $(OBJ) $(LIBS)

graphics.o: defs.h graphics.c
	gcc -c graphics.c

init.o:	defs.h init.c
	gcc -c init.c

main.o: defs.h	main.c
	gcc -c main.c

entity.o: entity.c defs.h
	gcc -c entity.c

clean:
	rm -rf *.o a4