#ifndef CALL_H
#define CALL_H

/*
	Purpose: An entity class that stores information about a call made between two parties and allows comparisons between calls
*/

#include "Date.h"
#include "Time.h"

class Call
{
  public:
    Call(string="", string="", int=0, int=0, int=0, int=0, int=0, int=0);
		~Call();
		bool greaterThan(Call *);
		void print();
		string getSrc();
		string getDest();

  private:
    string src;
		string dest;
		int duration;
		Date *date;
		Time *time;
};

#endif