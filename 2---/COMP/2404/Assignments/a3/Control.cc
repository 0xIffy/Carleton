#include <iostream>
using namespace std;
#include <string>
#include <time.h>
#include <cstdlib>

#include "Control.h"

Control::Control(string n)
	: shelter(new Shelter(n)), view(new View)
{}

Control::~Control(){
	delete shelter;
	delete view;
}

void Control::launch(){
	int choice;
	MatchListByClient *mlc;
	MatchListByScore *mls;

	initShelter();

	do{
		view->showMenu(choice);

		switch(choice){
			case 1:
				mlc = new MatchListByClient();
				mls = new MatchListByScore();

				shelter->computeMatches(*mls, *mlc);

				cout<<endl<<"Matches By Score:"<<endl;
				mls->print();
				cout<<endl<<"Matches By Client:"<<endl;
				mlc->print();

				mlc->cleanup();
				delete mls;
				delete mlc;
				
				break;
			
			case 2:
				shelter->printAnimals();
				break;

			case 3:
				shelter->printClients();
				break;
		}

	} while(choice != 0);
}

void Control::initShelter()
{
  initAnimals();
  initClients();
}

void Control::initClients()
{
  Client*   c;

  c  = new Client("Lee");
  c->addCriteria(new Criteria("Species", "Dog"));
  c->addCriteria(new Criteria("Gender", "F", 8));
  c->addCriteria(new Criteria("Age", "4", 2));
  shelter->add(c);

  c = new Client("Kara");
  c->addCriteria(new Criteria("Species", "Other"));
  c->addCriteria(new Criteria("Breed", "Guinea Pig", 9));
  c->addCriteria(new Criteria("Age", "2", 1));
  shelter->add(c);

  c = new Client("Laura");
  c->addCriteria(new Criteria("Species", "Cat"));
  c->addCriteria(new Criteria("Breed", "Domestic Short Hair", 2));
  c->addCriteria(new Criteria("Gender", "M", 3));
  c->addCriteria(new Criteria("Age", "1", 5));
  shelter->add(c);
}

void Control::initAnimals()
{
  shelter->add(new Animal(C_DOG, "Poodle", "White", "Betsy", "F", 5));
  shelter->add(new Animal(C_DOG, "Labradoodle", "Tan", "Killer", "F", 3));
  shelter->add(new Animal(C_DOG, "German Shepard", "Black/Tan", "Fluffy", "M", 2));
  shelter->add(new Animal(C_DOG, "Pug", "Tan", "Leon", "M", 4));
  shelter->add(new Animal(C_DOG, "Pug", "Tan", "Lily", "F", 1));
  shelter->add(new Animal(C_CAT, "Domestic Short Hair", "Grey", "Lady", "F", 11));
  shelter->add(new Animal(C_CAT, "Domestic Short Hair", "Grey", "Shadow", "M", 5));
  shelter->add(new Animal(C_CAT, "Domestic Long Hair", "Grey", "Luka", "M", 7));
  shelter->add(new Animal(C_CAT, "Domestic Short Hair", "Grey tabby", "Fiona", "F", 8));
  shelter->add(new Animal(C_CAT, "Domestic Short Hair", "Brown tabby", "Ruby", "F", 5));
  shelter->add(new Animal(C_RABBIT, "Lionhead", "Black", "Ziggy", "F", 3));
  shelter->add(new Animal(C_OTHER, "Guinea Pig", "Black", "Quark", "M", 9));
  shelter->add(new Animal(C_OTHER, "Guinea Pig", "Brown", "Quasar", "M", 1, 4));
  shelter->add(new Animal(C_OTHER, "Mouse", "Tan", "Pecorino", "M", 0, 3));
  shelter->add(new Animal(C_OTHER, "Mouse", "Tan", "Gruyere", "M", 0, 3));
  shelter->add(new Animal(C_OTHER, "Mouse", "Tan", "Limburger", "M", 0, 3));
}

