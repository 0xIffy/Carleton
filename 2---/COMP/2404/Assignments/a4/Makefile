a4:	main.o Guest.o Control.o Room.o ResManager.o Hotel.o RoomArray.o View.o Reservation.o Recorder.o Date.o
	g++ -o a4 main.o Guest.o Control.o Room.o ResManager.o Hotel.o RoomArray.o View.o Reservation.o Recorder.o Date.o

main.o:	main.cc Control.h
	g++ -c main.cc

Date.o:	Date.cc Date.h
	g++ -c Date.cc

Guest.o:	Guest.cc Guest.h
	g++ -c Guest.cc

Control.o:	Control.cc Control.h ResManager.h Hotel.h View.h Recorder.h
	g++ -c Control.cc

Room.o:	Room.cc Room.h
	g++ -c Room.cc

ResManager.o:	ResManager.cc ResManager.h Hotel.h Reservation.h Room.h Guest.h Recorder.h defs.h Date.h
	g++ -c ResManager.cc

Hotel.o:	Hotel.cc Hotel.h ResManager.h Guest.h Room.h RoomArray.h defs.h
	g++ -c Hotel.cc

RoomArray.o:	RoomArray.cc RoomArray.h Room.h
	g++ -c RoomArray.cc

Reservation.o: Reservation.cc Reservation.h Date.h Guest.h Room.h
	g++ -c Reservation.cc

Recorder.o:	Recorder.cc Recorder.h Reservation.h
	g++ -c Recorder.cc

View.o:	View.cc View.h
	g++ -c View.cc

clean:
	rm -f *.o a4