#ifndef TELCO_H
#define TELCO_H

/*
	Purpose: An entity class with some with some attributes of a control class. It stores and manages
				 	 subscribers and all their calls. Also able to do some calculations based on this data
*/

#include "Subscriber.h"
#include "Array.h"
#include "Call.h"

#define MAX_ARR 64

class Telco
{
  public:
		Telco(string="");
		~Telco();
		void addSub(Subscriber*);
		void addCall(string, string, int, int, int, int, int, int);
		void computeFreqCaller(string);
		void computeFreqCalled(string);
		void print();
	
	private:
		string name;
		int numSubs;
		Array *allCalls;
		Subscriber *subs[MAX_ARR];
		void findSubNum(string, Subscriber**);
		void calcFreq(Array&, string (Call::*getNum)(), string);
};

#endif
