#ifndef INDENTIFIABLE_H
#define INDENTIFIABLE_H

#include <string>

class Identifiable
{
  public:
		Identifiable(int&, string="");
		~Identifiable();
		string getId();

	protected:
		string id;

  private:

};

#endif
