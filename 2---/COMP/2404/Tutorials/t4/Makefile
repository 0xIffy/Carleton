t04:	main.o Time.o Control.o Date.o Call.o Subscriber.o Array.o
	g++ -o t04 main.o Time.o Control.o Date.o Call.o Subscriber.o Array.o

main.o:	main.cc Control.h
	g++ -c main.cc

Time.o:	Time.cc Time.h
	g++ -c Time.cc

Control.o:	Control.cc Control.h Subscriber.h Array.h Call.h
	g++ -c Control.cc

Date.o:	Date.cc Date.h
	g++ -c Date.cc

Call.o:	Call.cc Call.h Date.h Time.h
	g++ -c Call.cc

Subscriber.o:	Subscriber.cc Subscriber.h Array.h
	g++ -c Subscriber.cc

Array.o:	Array.cc Array.h Call.h
	g++ -c Array.cc

clean:
	rm -f *.o t04