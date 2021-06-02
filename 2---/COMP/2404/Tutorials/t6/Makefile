t06:	main.o random.o Animal.o Control.o Client.o Criteria.o CriteriaArray.o Identifiable.o Match.o MatchList.o MatchListByClient.o MatchListByScore.o defs.h
	g++ -o t06 main.o random.o Animal.o Control.o Client.o Criteria.o CriteriaArray.o Identifiable.o Match.o MatchList.o MatchListByClient.o MatchListByScore.o

main.o:	main.cc Control.h
	g++ -c main.cc

random.o: random.cc defs.h
	g++ -c random.cc

Animal.o:	Animal.cc Animal.h Identifiable.h defs.h
	g++ -c Animal.cc

Control.o:	Control.cc Control.h Client.h Animal.h MatchListByClient.h MatchListByScore.h defs.h
	g++ -c Control.cc

Client.o:	Client.cc Client.h Identifiable.h Criteria.h CriteriaArray.h
	g++ -c Client.cc

Identifiable.o:	Identifiable.cc Identifiable.h
	g++ -c Identifiable.cc

Criteria.o:	Criteria.cc Criteria.h
	g++ -c Criteria.cc

CriteriaArray.o:	CriteriaArray.cc CriteriaArray.h Criteria.h
	g++ -c CriteriaArray.cc

Match.o:	Match.cc Match.h Client.h Animal.h
	g++ -c Match.cc

MatchList.o:	MatchList.cc MatchList.h Match.h
	g++ -c MatchList.cc

MatchListByClient.o:	MatchListByClient.cc MatchListByClient.h MatchList.h
	g++ -c MatchListByClient.cc

MatchListByScore.o:	MatchListByScore.cc MatchListByScore.h MatchList.h
	g++ -c MatchListByScore.cc

clean:
	rm -f *.o t06