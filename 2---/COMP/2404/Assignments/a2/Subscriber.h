#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

/*
	Purpose: An entity class that stores data about a single subscriber to the telco. Also
					 stores and manages data about its incoming and outgoing calls
*/

#include "Array.h"

class Subscriber{
	public:
		Subscriber(string="");
		~Subscriber();
		void addIncoming(Call*);
		void addOutgoing(Call*);
		void print();
		string getPhoneNum();
		Array& getOutgoing();
		Array& getIncoming();

	private:
		string phoneNum;
		Array *inCalls;
		Array *outCalls;
};

#endif