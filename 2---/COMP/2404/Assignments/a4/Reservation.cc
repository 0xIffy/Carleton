#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Reservation.h"

Reservation::Reservation(Guest *g, Room *r, Date *d, int s)
	: guest(g), room(r), arrival(d), stay(s)
{
	cost = s * room->getRate();
}

Reservation::~Reservation(){
	delete arrival;
}

bool Reservation::lessThan(Reservation *r){
	return arrival->lessThan(*(r->arrival));
}

void Reservation::print(){
	cout<< "-- Guest:" << setfill(' ') << setw(10) << guest->getName() 
			<< "; Room: " << room->getNum() << "; Arrival: ";
	arrival->print();
	cout<< "; Stay: " << setfill(' ') << setw(2) << stay << "; Total: $" << setw(7)
			<< right << fixed << setprecision(2) << cost << endl;
}

int Reservation::getStay(){ return stay; }

float Reservation::getCost(){ return cost; }

Guest* Reservation::getGuest(){ return guest; }

Date* Reservation::getDate(){ return arrival; }

Room* Reservation::getRoom(){ return room; }
