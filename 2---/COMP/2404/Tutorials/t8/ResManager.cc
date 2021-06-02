#include <iostream>
using namespace std;
#include <string>

#include "ResManager.h"
#include "Hotel.h"

ResManager::ResManager(Hotel *h)
	: hotel(h), numRes(0)
{}

ResManager::~ResManager(){
	for(int i = 0; i < numRes; i++){
		delete reservations[i];
	}

	for(int i = 0; i < recorders.size(); i++){
		delete recorders[i];
	}
}

void ResManager::setHotel(Hotel *h){
	hotel = h;
}

void ResManager::addReservation(string n, int y, int m, int d, int sty, ReqRoomType req){
	Room *r;
	Guest *g;
	Date *date;
	Reservation *res = NULL;
	int pts;

	if(sty < 1 || sty > 31){
		cout<<"ERROR: invalid length of stay"<<endl;
		return;
	}

	date =  new Date(d,m,y);

	for(int i = 0; i < hotel->getRooms().getSize(); i++){
		r = hotel->getRooms().get(i);
		if(r->getType() == req && isAvailable(r,date,sty)){
			if(!hotel->findGuest(n, &g)){
				cout<<"ERROR: Could not find guest: " << n << " in hotel guest list"<< endl;
				delete date;
				return;
			}

			// g->print();
			// r->print();
			res = new Reservation(g, r, date, sty);
			if(add(res)){
				r->computePoints(pts);
				g->addPts(pts*sty);
				notify(res);
			}
		}
	}

	if(res == NULL)
		delete date;

	return;
}

void ResManager::subscribe(Recorder *r){
	recorders.push_back(r);
}

void ResManager::print(){
	cout<<"Reservations:"<<endl;

	for(int i = 0; i < numRes; i++){
		reservations[i]->print();
	}
}

void ResManager::printRecords(){
	cout<<"Records:"<<endl;

	for(int i = 0; i < recorders.size(); ++i){
		recorders[i]->printRecords();
	}
}

void ResManager::notify(Reservation *r){
	for(int i = 0; i < recorders.size(); ++i){
		recorders[i]->update(r);
	}
}

bool ResManager::add(Reservation *r){
	if(numRes >= MAX_ARR){
		cout<<"ERROR: No more room for reservations"<<endl;
		delete r;
		return false;
	}

	for(int i = numRes; i >= 0; i--){
		if(i == 0 || !r->lessThan(reservations[i-1])){
			reservations[i] = r;
			numRes++;
			break;
		} else{
			reservations[i] = reservations[i-1];
		}
	}

	return true;
}

bool ResManager::isAvailable(Room *r, Date *d, int sty){
	Date temp1(*d);

	temp1.add(sty);

	for(int i = 0; i < numRes; i++){
		if(reservations[i]->getRoom()->getNum() == r->getNum()){
			Date temp2 = *(reservations[i]->getDate());
			temp2.add(reservations[i]->getStay());

			if(d->lessThan(temp2) || (reservations[i]->getDate())->lessThan(temp1)){
				// cout<<"ERROR: Room is not available during your specified period."<<endl;
				return false;
			}
		}
	}

	return true;
}