#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

#include "Recorder.h"

Recorder::Recorder(string n)
	: name(n)
{}

void Recorder::printRecords(){
	cout<<"Remains to be seen"<<endl;
}


StayRecorder::StayRecorder(string n)
	: Recorder(n)
{}

void StayRecorder::update(Reservation *r){
	stringstream ss;

	if(r->getStay() > 3){
		ss << r->getGuest()->getName() << ": " << r->getStay() << "days" << endl;
		records.push_back(ss.str());
	}
}


GuestRecorder::GuestRecorder(string n)
	: Recorder(n)
{}

void GuestRecorder::update(Reservation *r){
	stringstream ss;
	Guest *g = r->getGuest();
	Room *rm = r->getRoom();

	if(!g->getPremStat() && (rm->getType() == C_PREM || rm->getType() == C_SUITE)){
		ss << g->getName() << "; room #: " << rm->getNum() << endl;
		records.push_back(ss.str());
	}
}


UpgradeRecorder::UpgradeRecorder(string n)
	: Recorder(n)
{}

void UpgradeRecorder::update(Reservation *r){
	stringstream ss;
	Guest *g = r->getGuest();
	Room *rm = r->getRoom();

	if(!g->getPremStat() && r->getCost() > 1500){
		ss << r->getGuest()->getName() << "; Charged: $" 
		<< setfill(' ') << setw(6) << fixed << setprecision(2) << r->getCost() << "days" 
		<< endl;
		
		records.push_back(ss.str());
	}
}