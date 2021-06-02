t03:	main.o Time.o Control.o Date.o Call.o
	g++ -o t03 main.o Time.o Control.o Date.o Call.o

main.o:	main.cc Time.h Control.h Date.h Call.h
	g++ -c main.cc

Time.o:	Time.cc Time.h
	g++ -c Time.cc

Control.o:	Control.cc Call.h Control.h
	g++ -c Control.cc

Date.o:	Date.cc Date.h
	g++ -c Date.cc

Call.o:	Call.cc Call.h Date.h Time.h
	g++ -c Call.cc

clean:
	rm -f *.o t03