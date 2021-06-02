#ifndef CONTROL_H
#define CONTROL_H

#include "defs.h"
#include "Animal.h"
#include "Client.h"

class Control
{
  public:
		Control();
		~Control();
		bool add(Animal *);
		bool add(Client *);
		void printAnimals();
		void printClients();
		void launch();

  private:
		Animal *animals[MAX_SIZE];
		Client *clients[MAX_SIZE];
		int numAnimals;
		int numClients;
		void initAnimalsTemp();
		void initClientsTemp();

};

#endif
