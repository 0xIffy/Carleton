#ifndef AGENDA_H
#define AGENDA_H

/*
	Purpose: Allow user to manage a collection of calendar's for the user
*/

#include <string>
#include "Calendar.h"
#include "Date.h"

#define MAX_ARR 64

class Agenda
{
  public:
		Agenda(string="");
		~Agenda();
		string getName();
		bool add(Calendar*);
		bool add(Date*, string);
		bool find(string, Calendar**);
		void print();
	
	private:
		string name;
		Calendar *cdars[MAX_ARR];
		int numCdars;
};

#endif
