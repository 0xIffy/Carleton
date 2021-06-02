p:	main.o Record.o ReportGenerator.o Control.o AnimalRepGen.o View.o RegionRepGen.o YearRepGen.o
	g++ -o p main.o Record.o ReportGenerator.o Control.o AnimalRepGen.o View.o RegionRepGen.o YearRepGen.o

main.o:	main.cc Control.h
	g++ -c main.cc

Record.o:	Record.cc Record.h
	g++ -c Record.cc

ReportGenerator.o:	ReportGenerator.cc ReportGenerator.h Record.h Map.h
	g++ -c ReportGenerator.cc

Control.o:	Control.cc Control.h ReportGenerator.h
	g++ -c Control.cc

AnimalRepGen.o:	AnimalRepGen.cc AnimalRepGen.h Record.o ReportGenerator.o ReportData.h Map.h
	g++ -c AnimalRepGen.cc

RegionRepGen.o: RegionRepGen.cc RegionRepGen.h Record.o ReportGenerator.o ReportData.h Map.h
	g++ -c RegionRepGen.cc

YearRepGen.o:	YearRepGen.cc YearRepGen.h Record.o ReportGenerator.o ReportData.h Map.h
	g++ -c YearRepGen.cc

View.o:	View.cc View.h
	g++ -c View.cc


clean:
	rm -f *.o p *.out