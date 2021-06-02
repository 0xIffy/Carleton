#ifndef ROOM_H
#define ROOM_H

/*
	Purpose: An entity class. Handles room data and interactions with other classes
*/

#include <string>
#include "defs.h"

class Room
{
	public:
		Room(ReqRoomType, int=0, float=0);
		ReqRoomType getType();
		int getNum();
		float getRate();
		void print();
		void computePoints(int&);
		string getRoomName();

	private:
		ReqRoomType type;
		int number;
		float rate;

};

#endif
