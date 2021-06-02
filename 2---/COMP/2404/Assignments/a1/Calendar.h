#ifndef CALENDAR_H
#define CALENDAR_H

/*
	Purpose: allow user to manage a collection of dates related to a specific aspect of the their life
*/

#include <string>
#include "Date.h"

#define MAX_ARR 64

class Calendar
{
  public:
		Calendar(string="");
		~Calendar();
		string getName();
		bool add(Date*);
		void merge(Calendar*);
		void printDates();
		void print();
	
	private:
		string name;
		Date **dates;
		int numDates;
};

#endif
