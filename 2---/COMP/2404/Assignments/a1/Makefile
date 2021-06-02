t07:	main.o Date.o Calendar.o Agenda.o
	g++ -o t07 *.o

main.o:	main.cc Date.h Agenda.h Calendar.h defs.h
	g++ -c main.cc

Date.o:	Date.cc Date.h
	g++ -c Date.cc

Calendar.o:	Calendar.cc Calendar.h Date.h
	g++ -c Calendar.cc

Agenda.o:	Agenda.cc Agenda.h Calendar.h Date.h
	g++ -c Agenda.cc

clean:
	rm -f *.o t07
