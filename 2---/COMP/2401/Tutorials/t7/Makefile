myExec:	person.o main.o mystat.o
	gcc -o myExec main.o person.o mystat.o

main.o: person.h
	gcc -c main.c

person.o:	person.c person.h mystat.h
	gcc -c person.c

mystat.o:	mystat.h
	gcc -c mystat.c

clean:	
	rm -f *.o myExec