a3: main.o init.o print.o data.o
	gcc -o a3 main.o print.o init.o data.o

main.o: defs.h main.c
	gcc -c main.c

print.o: defs.h print.c
	gcc -c print.c

init.o: defs.h init.c
	gcc -c init.c

data.o: defs.h data.c
	gcc -c data.c

clean:
	rm -f *.o a3