#ifndef HOTEL_H
#define HOTEL_H

#include <string>
#include "defs.h"
#include "RoomArray.h"
#include "ResManager.h"
#include "Guest.h"
#include "Room.h"

class Hotel
{
	public:
		Hotel(ResManager*,string="");
		~Hotel();
		RoomArray& getRooms();
		void addGuest(Guest*);
		void addRoom(Room*);
		void printGuests();
		void printRooms();
		bool findGuest(string, Guest**);

	private:
		string name;
		Guest *guests[MAX_ARR];
		int numGuests;
		RoomArray *rooms;
		ResManager *mngr;
};

#endif
