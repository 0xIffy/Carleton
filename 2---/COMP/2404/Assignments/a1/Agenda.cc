#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Agenda.h"

Agenda::Agenda(string n){
	name = n;
	numCdars = 0;
}

Agenda::~Agenda(){
	for(int i = 0; i < numCdars; ++i){
		delete cdars[i];
	}
}

bool Agenda::add(Calendar *c){
	if(numCdars == MAX_ARR)
		return false;

	cdars[numCdars] = c;

	numCdars += 1;

	return true;
}

bool Agenda::add(Date *d, string n){
	Calendar *c;

	if(!find(n, &c)){
		cout<<"ERROR: calendar " << n << " not found"<<endl;
		delete d;
		return false;
	}

	return c->add(d);
}

bool Agenda::find(string n, Calendar **c){
	for(int i = 0; i < numCdars; ++i){
		if(cdars[i]->getName() == n){
			*c = cdars[i];
			return true;
		}
	}

	return false;
}

void Agenda::print(){
	Calendar temp;

	for(int i = 0; i < numCdars; ++i){
		temp.merge(cdars[i]);
	}

	cout<<"Agenda: "<< name<<endl;
	
	temp.printDates();
}