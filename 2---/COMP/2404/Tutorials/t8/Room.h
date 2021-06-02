#ifndef ROOM_H
#define ROOM_H

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

	private:
		ReqRoomType type;
		int number;
		float rate;

};

#endif
