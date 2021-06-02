#include <iostream>
#include <iomanip>
using namespace std;
#include <string>
#include "Client.h"

int Client::nextId = 7001;

Client::Client(string n)
	: Identifiable(nextId, "C"), name(n), criteria(new CriteriaArray())
{}

Client::~Client(){
	delete criteria;
}

void Client::addCriteria(Criteria *c){
	criteria->add(c);
}

string Client::getName(){ return name; }

CriteriaArray& Client::getCriteria(){ return *criteria; }

void Client::print(){
	cout << left << setfill(' ') << setw(8) << id 
	<< left << setfill(' ') << setw(20) << name << endl;

	criteria->print();
}