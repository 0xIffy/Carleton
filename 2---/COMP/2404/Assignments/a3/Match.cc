#include <iostream>
#include <iomanip>
using namespace std;
#include <string>
#include <cmath>

#include "Match.h"

Match::Match(Animal *a, Client *c, float s)
	: animal(a), client(c), score(s)
{}

float Match::getScore(){
	return score;
}

string Match::getClientId(){
	return client->getId();
}

void Match::print(){
	cout << left << setfill(' ') << setw(8) << client->getId()
	<< left << setfill(' ') << setw(15) << client->getName()
	<< " : " << left << setfill(' ') << setw(8) << animal->getId()
	<< left << setfill(' ') << setw(15) << animal->getName()
	<< " : " << right << setfill(' ') << setw(4) << fixed << setprecision(1) << score
	<< "(" << right << setfill(' ') << setw(3) << (int) round(score / 20 * 100) << "%)"
	<< endl;
}