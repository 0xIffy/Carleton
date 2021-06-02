#ifndef c
#define CLIENT_H

#include <string>

#include "Identifiable.h"
#include "CriteriaArray.h"
#include "Criteria.h"

class Client : public Identifiable
{
  public:
		Client(string="");
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
