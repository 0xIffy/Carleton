#ifndef RESMANAGER_H
#define RESMANAGER_H

#include <string>
#include "defs.h"

class Hotel;

class ResManager
{
	public:
		ResManager(Hotel*);
		void setHotel(Hotel*);
		void addReservation(string, int, int, int, int, ReqRoomType);

	private:
		Hotel *hotel;
};

#endif
