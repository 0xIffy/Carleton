#ifndef SHELTER_H
#define SHELTER_H

/*
	Purpose: An entity class with some aspects of a control. Handles shelter data and interactions with other classes
*/

#include <string>
#include "defs.h"
#include "Animal.h"
#include "Client.h"
#include "CriteriaArray.h"
#include "Criteria.h"
#include "MatchListByClient.h"
#include "MatchListByScore.h"

class Shelter
{
  public:
		Shelter(string="");
		~Shelter();
		string getName();
		CriteriaArray& getCriteria();
		bool add(Animal*);
		bool add(Client*);
		void printAnimals();
		void printClients();
		void computeMatches(MatchListByScore&, MatchListByClient&);


  private:
		string name;
		Animal *animals[MAX_SIZE];
		Client *clients[MAX_SIZE];
		int numAnimals;
		int numClients;

};

#endif
