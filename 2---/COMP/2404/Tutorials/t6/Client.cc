#include <iostream>
using namespace std;
#include <string>
#include "Client.h"

int Client::nextId = 2001;

Client::Client(string n)
	: Identifiable(nextId, "C"), name(n), criteria(new CriteriaArray())
{}

void Client::addCriteria(Criteria *c){
	criteria->add(c);
}

string Client::getName(){ return name; }

CriteriaArray& Client::getCriteria(){ return *criteria; }

void Client::print(){
	cout << id << endl;
}