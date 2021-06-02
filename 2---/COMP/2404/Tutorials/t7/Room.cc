#include <iostream>
using namespace std;
#include <string>

#include "Room.h"

Room::Room(ReqRoomType t, int n, float r)
	: type(t), number(n), rate(r)
{}

ReqRoomType Room::getType(){ return type; }

int Room::getNum(){ return number; }

float Room::getRate(){ return rate; }

void Room::print(){
	cout<<number<<endl;
}