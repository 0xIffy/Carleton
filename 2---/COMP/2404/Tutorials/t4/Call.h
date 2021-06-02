#ifndef CALL_H
#define CALL_H

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