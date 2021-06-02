#include <iostream>
using namespace std;
#include <string>

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
	cout << client->getId() << ":" << animal->getId() << endl;;
}