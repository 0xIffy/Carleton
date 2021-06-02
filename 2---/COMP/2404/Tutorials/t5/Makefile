t05:	main.o Animal.o Control.o Client.o Criteria.o CriteriaArray.o Identifiable.o defs.h
	g++ -o t05 main.o Animal.o Control.o Client.o Criteria.o CriteriaArray.o Identifiable.o

main.o:	main.cc Control.h
	g++ -c main.cc

Animal.o:	Animal.cc Animal.h Identifiable.h defs.h
	g++ -c Animal.cc

Control.o:	Control.cc Control.h Client.h Animal.h
	g++ -c Control.cc

Client.o:	Client.cc Client.h Identifiable.h Criteria.h CriteriaArray.h
	g++ -c Client.cc

Criteria.o:	Criteria.cc Criteria.h
	g++ -c Criteria.cc

CriteriaArray.o:	CriteriaArray.cc CriteriaArray.h Criteria.h
	g++ -c CriteriaArray.cc

Identifiable.o:	Identifiable.cc Identifiable.h
	g++ -c Identifiable.cc

clean:
	rm -f *.o t05