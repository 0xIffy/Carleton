#include <iostream>
using namespace std;
#include <string>

#include "ResManager.h"
#include "Hotel.h"

ResManager::ResManager(Hotel *h)
	: hotel(h)
{}

void ResManager::setHotel(Hotel *h){
	hotel = h;
}


void ResManager::addReservation(string n, int y, int m, int d, int sty, ReqRoomType req){
	Room *r;
	Guest *g;

	for(int i = 0; i < hotel->getRooms().getSize(); i++){
		r = hotel->getRooms().get(i);
		if(r->getType() == req){
			if(!hotel->findGuest(n, &g))
				return;

			g->print();
			r->print();
		}
	}

	return;
}