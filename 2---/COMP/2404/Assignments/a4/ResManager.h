#ifndef RESMANAGER_H
#define RESMANAGER_H

/*
	Purpose: An entity class with some aspects of a control. Manages reservation data and interactions with other classes
*/

#include <string>
#include "defs.h"
#include "Reservation.h"
#include "Recorder.h"
#include "Guest.h"
#include "Room.h"
#include "Date.h"

class Hotel;

class ResManager
{
	public:
		ResManager(Hotel*);
		~ResManager();
		void setHotel(Hotel*);
		void addReservation(string, int, int, int, int, ReqRoomType);
		void subscribe(Recorder*);
		void print();
		void printRecords();

	private:
		Hotel *hotel;
		Reservation *reservations[MAX_ARR];
		int numRes;
		vector<Recorder*> recorders;
		bool isAvailable(Room*,Date*,int);
		bool add(Reservation*);
		void notify(Reservation*);
};

#endif
