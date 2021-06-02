#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Calendar.h"

Calendar::Calendar(string n){
	name = n;
	dates = new Date*[MAX_ARR];
	numDates = 0;
}

Calendar::~Calendar(){
	for(int i = 0; i < numDates; ++i){
		delete dates[i];
	}

	delete [] dates;
}

string Calendar::getName(){
	return name;
}

bool Calendar::add(Date *d){
	if(!d->isValid() || numDates == MAX_ARR){
		cout<<"ERROR: date could not be added"<<endl;
		delete d;
		return false;
	}

	for(int i = numDates; i >= 0; --i){
		if(i > 0 && d->lessThan(dates[i-1])){
			dates[i] = dates[i-1];
		} else{
			dates[i] = d;
			break;
		}
	}

	numDates += 1;

	return true;
}

void Calendar::merge(Calendar *c){
	Date *d;

	for(int i = 0; i < c->numDates; ++i){
		d = new Date(*(c->dates[i]));
		if(!add(d))
			delete d;
	}
}

void Calendar::printDates(){
	for(int i = 0; i < numDates; ++i){
		cout<<setfill(' ')<<setw(2)<<i+1 << ": ";
		dates[i]->print();
	}
}

void Calendar::print(){
	cout<< "Calendar: " << name << endl;
	printDates();
	cout<<endl;
}