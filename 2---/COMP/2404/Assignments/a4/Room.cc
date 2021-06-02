#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

#include "Room.h"

Room::Room(ReqRoomType t, int n, float r)
	: type(t), number(n), rate(r)
{}

void Room::computePoints(int& p){
	float pct;
	
	if(type == C_SUITE)
		pct = 0.2;
	else if(type == C_PREM)
		pct = 0.15;
	else if(type == C_REG)
		pct = 0.1;

	p = pct * rate;
}

string Room::getRoomName(){
	string s;

	switch(type){
		case C_SUITE:
			s = "Suite";
			break;
		case C_PREM:
			s = "Premium";
			break;
		case C_REG:
			s = "Regular";
			break;
		default:
			s = "Undefined";
	}

	return s;
}

ReqRoomType Room::getType(){ return type; }

int Room::getNum(){ return number; }

float Room::getRate(){ return rate; }

void Room::print(){
	cout<< "-- " << number << "  " << setfill(' ') << setw(8) << left << getRoomName() 
			<< " room: $" << setw(7) << fixed << setprecision(2) << right 
			<< rate << " per night" <<endl;
}