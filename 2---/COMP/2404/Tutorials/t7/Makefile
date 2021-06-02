t07:	main.o Guest.o Control.o Room.o ResManager.o Hotel.o RoomArray.o
	g++ -o t07 main.o Guest.o Control.o Room.o ResManager.o Hotel.o RoomArray.o

main.o:	main.cc Control.h
	g++ -c main.cc

Guest.o:	Guest.cc Guest.h
	g++ -c Guest.cc

Control.o:	Control.cc Control.h
	g++ -c Control.cc

Room.o:	Room.cc Room.h
	g++ -c Room.cc

ResManager.o:	ResManager.cc ResManager.h Hotel.h
	g++ -c ResManager.cc

Hotel.o:	Hotel.cc Hotel.h ResManager.h Guest.h Room.h RoomArray.h
	g++ -c Hotel.cc

RoomArray.o:	RoomArray.cc RoomArray.h Room.h
	g++ -c RoomArray.cc

# View.o:	View.cc View.h
# 	g++ -c View.cc

# Telco.o:	Telco.cc Telco.h RoomArray.h Hotel.h ResManager.h
# 	g++ -c Telco.cc

clean:
	rm -f *.o t07