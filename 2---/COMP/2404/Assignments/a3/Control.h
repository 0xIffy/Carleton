#ifndef CONTROL_H
#define CONTROL_H

/*
	Purpose: An control class. Handle the overall control flow for the program
*/

#include "View.h"
#include "Animal.h"
#include "Client.h"
#include "Shelter.h"
#include "Criteria.h"

class Control
{
  public:
		Control(string="");
		~Control();
		void launch();

  private:
		Shelter *shelter;
		View *view;
		void initShelter();
		void initAnimals();
		void initClients();

};

#endif
