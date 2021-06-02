#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

#include "Guest.h"

Guest::Guest(string n, bool p)
	: name(n), premium(p), pnts(0)
{}

void Guest::addPts(int p){
	pnts += p;
}

string Guest::getName(){ return name; }

bool Guest::getPremStat(){ return premium; }

void Guest::print(){
	string s;

	if(premium)
		s = "Premium";
	else
		s = "Regular";

	cout << "-- " << setfill(' ') << setw(10) << left << name 
	<< s << " guest:" << setw(6) << right << pnts << " pts" << endl;
}