#ifndef CLIENT_H
#define CLIENT_H

/*
	Purpose: An entity class. Handles client data and interactions with other classes
*/

#include <string>

#include "Identifiable.h"
#include "CriteriaArray.h"
#include "Criteria.h"

class Client : public Identifiable
{
  public:
		Client(string="");
		~Client();
		string getName();
		CriteriaArray& getCriteria();
		void addCriteria(Criteria *);
		void print();

  private:
		static int nextId;
		string name;
		CriteriaArray *criteria;

};

#endif
