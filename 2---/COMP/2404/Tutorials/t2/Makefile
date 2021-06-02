t02:	main.o Date.o Calendar.o
	g++ -o t02 *.o

main.o:	main.cc Date.h Calendar.h
	g++ -c main.cc

Date.o:	Date.cc Date.h
	g++ -c Date.cc

Calendar.o:	Calendar.cc Calendar.h
	g++ -c Calendar.cc

clean:
	rm -f *.o t02
