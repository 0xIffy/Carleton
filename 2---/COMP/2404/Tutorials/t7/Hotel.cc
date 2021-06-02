#include <iostream>
using namespace std;
#include <string>

#include "Hotel.h"

Hotel::Hotel(ResManager *r, string n)
	: name(n), mngr(r), numGuests(0), rooms(new RoomArray())
{}

Hotel::~Hotel(){
	delete rooms;

	for(int i = 0; i < numGuests; i++){
		delete guests[i];
	}

	// delete mngr;
}

RoomArray& Hotel::getRooms(){
	return *rooms;
}

bool Hotel::findGuest(string n, Guest **g){
	for(int i = 0; i < numGuests; i++){
		if(guests[i]->getName() == n){
			*g = guests[i];
			return true;
		}
	}

	return false;
}

void Hotel::addGuest(Guest *g){
	if(numGuests >= MAX_ARR)
		return;

	guests[numGuests++] = g;
}

void Hotel::addRoom(Room *r){
	rooms->add(r);
}

void Hotel::printGuests(){
	cout<<"Guests:"<<endl;
	for(int i = 0; i < numGuests; i++){
		guests[i]->print();
	}
}

void Hotel::printRooms(){
	cout<<"Rooms:"<<endl;
	rooms->print();
}