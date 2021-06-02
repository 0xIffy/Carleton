#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

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