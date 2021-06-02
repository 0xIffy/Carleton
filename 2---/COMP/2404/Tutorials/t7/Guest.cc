#include <iostream>
using namespace std;
#include <string>

#include "Guest.h"

Guest::Guest(string n, bool p)
	: name(n), premium(p), lPnts(0)
{}

string Guest::getName(){ return name; }

bool Guest::getPremStat(){ return premium; }

void Guest::print(){
	cout<<name<<endl;
}