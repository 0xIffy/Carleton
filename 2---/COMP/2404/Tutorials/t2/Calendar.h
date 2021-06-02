#include <string>
#include "Date.h"

#define MAX_ARR 64

#ifndef CALENDAR_H
#define CALENDAR_H

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
