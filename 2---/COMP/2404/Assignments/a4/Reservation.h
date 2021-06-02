#ifndef RESERVATION_H
#define RESERVATION_H

/*
	Purpose: An entity class. Handles reservation data and interactions with other classes
*/

#include <string>
#include "Date.h"
#include "Guest.h"
#include "Room.h"

class Reservation
{
	public:
		Reservation(Guest*,Room*,Date*,int=0);
		~Reservation();
		bool lessThan(Reservation *);
		void print();
		int getStay();
		Guest* getGuest();
		Room* getRoom();
		Date* getDate();
		float getCost();

	private:
		Guest *guest;
		Date *arrival;
		int stay;
		Room *room;
		float cost;
};

#endif
