#include <iostream>
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

ReqRoomType Room::getType(){ return type; }

int Room::getNum(){ return number; }

float Room::getRate(){ return rate; }

void Room::print(){
	cout<<number<<endl;
}