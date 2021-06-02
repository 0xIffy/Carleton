#include <iostream>
#include <sstream>
using namespace std;
#include <string>
#include <iomanip>

#include "Identifiable.h"

Identifiable::Identifiable(int& nextId, string t){
	stringstream ss;

	ss << t << "-" << nextId;
	id = ss.str();
	
	nextId += 1;
}

Identifiable::~Identifiable(){}

string Identifiable::getId(){ return id; }