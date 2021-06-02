a2:	main.o Time.o Control.o Date.o Call.o Subscriber.o Array.o View.o Telco.o
	g++ -o a2 main.o Time.o Control.o Date.o Call.o Subscriber.o Array.o View.o Telco.o

main.o:	main.cc Control.h
	g++ -c main.cc

Time.o:	Time.cc Time.h
	g++ -c Time.cc

Control.o:	Control.cc Telco.h Control.h View.h
	g++ -c Control.cc

Date.o:	Date.cc Date.h
	g++ -c Date.cc

Call.o:	Call.cc Call.h Date.h Time.h
	g++ -c Call.cc

Subscriber.o:	Subscriber.cc Subscriber.h Array.h
	g++ -c Subscriber.cc

Array.o:	Array.cc Array.h Call.h
	g++ -c Array.cc

View.o:	View.cc View.h
	g++ -c View.cc

Telco.o:	Telco.cc Telco.h Array.h Subscriber.h Call.h
	g++ -c Telco.cc

clean:
	rm -f *.o a2