#ifndef INDENTIFIABLE_H
#define INDENTIFIABLE_H

/*
	Purpose: An entity class. Serves as base class for all identifiable objects
*/

#include <string>

class Identifiable
{
  public:
		Identifiable(int&, string="");
		~Identifiable();
		string getId();

	protected:
		string id;
};

#endif
