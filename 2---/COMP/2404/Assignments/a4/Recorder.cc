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
	cout<<"Records for " << name << ":" <<endl;
	for(int i = 0; i < records.size(); i++){
		cout<< name << ": " << records[i];
	}
}


StayRecorder::StayRecorder(string n)
	: Recorder(n)
{}

void StayRecorder::update(Reservation *r){
	stringstream ss;

	if(r->getStay() > 3){
		ss<< "Guest: " << setfill(' ') << setw(10) << r->getGuest()->getName() 
			<< ", " << setw(2) << r->getStay() << " nights" << endl;
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
		ss << "Premium guest offer for " << g->getName() << endl;
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
		ss << "Guest: " << setfill(' ') << setw(10) << r->getGuest()->getName() << "; Charged: $" 
		<< setfill(' ') << setw(6) << fixed << setprecision(2) << r->getCost() << endl;
		
		records.push_back(ss.str());
	}
}