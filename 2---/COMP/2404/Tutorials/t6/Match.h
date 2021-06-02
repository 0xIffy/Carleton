#ifndef MATCH_H
#define MATCH_H

#include <string>

#include "Animal.h"
#include "Client.h"

class Match
{
  public:
		Match(Animal *, Client *, float=0);
		float getScore();
		string getClientId();
		void print();

  private:
		Animal *animal;
		Client *client;
		float score;
};

#endif
