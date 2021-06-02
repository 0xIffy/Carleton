#include <iostream>
using namespace std;
#include <string>

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
	initAnimalsTemp();
	initClientsTemp();

	printAnimals();
	printClients();
}

bool Control::add(Animal *a){
	if(numAnimals >= MAX_SIZE)
		return false;

	animals[numAnimals] = a;
	numAnimals++;
}

bool Control::add(Client *c){
	if(numClients >= MAX_SIZE)
		return false;

	clients[numClients] = c;
	numClients++;
}

void Control::printAnimals(){
	for(int i = 0; i < numAnimals; ++i){
		animals[i]->print();
	}
}

void Control::printClients(){
	for(int i = 0; i < numClients; ++i){
		clients[i]->print();
	}
}

void Control::initClientsTemp()
{
  Client* c;

  c  = new Client("Lee");
  c->addCriteria(new Criteria("Species", "Dog"));
  c->addCriteria(new Criteria("Gender", "F", 8));
  c->addCriteria(new Criteria("Age", "4", 2));
  add(c);

  c = new Client("Kara");
  c->addCriteria(new Criteria("Species", "Other"));
  c->addCriteria(new Criteria("Breed", "Guinea Pig", 9));
  c->addCriteria(new Criteria("Age", "2", 1));
  add(c);

  c = new Client("Laura");
  c->addCriteria(new Criteria("Species", "Cat"));
  c->addCriteria(new Criteria("Breed", "Domestic Short Hair", 2));
  c->addCriteria(new Criteria("Gender", "M", 3));
  c->addCriteria(new Criteria("Age", "1", 5));
  add(c);
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

