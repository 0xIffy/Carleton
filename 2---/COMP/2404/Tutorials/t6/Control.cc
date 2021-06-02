#include <iostream>
using namespace std;
#include <string>
#include <time.h>
#include <cstdlib>

#include "Control.h"

Control::Control()
	: numClients(0), numAnimals(0)
{}

Control::~Control(){
	for(int i = 0; i < numAnimals; ++i){
		delete animals[i];
	}

	for(int i = 0; i < numClients; ++i){
		delete clients[i];
	}
}

void Control::launch(){
	srand( (unsigned)time( NULL ) );

	initAnimalsTemp();
	initClientsTemp();

	MatchListByClient mlc;
	MatchListByScore mls;

	generateMatches(mls, mlc);

	mls.print();
	cout << endl;
	mlc.print();

	mls.cleanup();
}

bool Control::add(Animal *a){
	if(numAnimals >= MAX_SIZE)
		return false;

	animals[numAnimals] = a;
	numAnimals++;

	return true;
}

bool Control::add(Client *c){
	if(numClients >= MAX_SIZE)
		return false;

	clients[numClients] = c;
	numClients++;

	return true;
}

void Control::generateMatches(MatchListByScore& ms, MatchListByClient& mc){
	float rdm;
	Match *m;

	for(int i = 0; i < numAnimals; i++){
		for(int j = 0; j < numClients; j++){
			rdm = (float) random(20);

			if(rdm != 0){
				m = new Match(animals[i], clients[j], rdm);
				ms.add(m);
				mc.add(m);
			}
		}
	}
}

void Control::initClientsTemp()
{
  add(new Client("Lee"));
  add(new Client("Kara"));
  add(new Client("Laura"));
}

void Control::initAnimalsTemp()
{
  add(new Animal(C_DOG, "Poodle", "White", "Betsy", "F", 5));
  add(new Animal(C_DOG, "Labradoodle", "Tan", "Killer", "F", 3));
  add(new Animal(C_DOG, "German Shepard", "Black/Tan", "Fluffy", "M", 2));
  add(new Animal(C_DOG, "Pug", "Tan", "Leon", "M", 4));
  add(new Animal(C_DOG, "Pug", "Tan", "Lily", "F", 1));
  add(new Animal(C_CAT, "Domestic Short Hair", "Grey", "Lady", "F", 11));
  add(new Animal(C_CAT, "Domestic Short Hair", "Grey", "Shadow", "M", 5));
  add(new Animal(C_CAT, "Domestic Long Hair", "Grey", "Luka", "M", 7));
  add(new Animal(C_CAT, "Domestic Short Hair", "Grey tabby", "Fiona", "F", 8));
  add(new Animal(C_CAT, "Domestic Short Hair", "Brown tabby", "Ruby", "F", 5));
  add(new Animal(C_RABBIT, "Lionhead", "Black", "Ziggy", "F", 3));
  add(new Animal(C_OTHER, "Guinea Pig", "Black", "Quark", "M", 9));
  add(new Animal(C_OTHER, "Guinea Pig", "Brown", "Quasar", "M", 1, 4));
  add(new Animal(C_OTHER, "Mouse", "Tan", "Pecorino", "M", 0, 3));
  add(new Animal(C_OTHER, "Mouse", "Tan", "Gruyere", "M", 0, 3));
  add(new Animal(C_OTHER, "Mouse", "Tan", "Limburger", "M", 0, 3));
}

