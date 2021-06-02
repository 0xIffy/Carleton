#ifndef CONTROL_H
#define CONTROL_H

#include "Array.h"
#include "Subscriber.h"
#include "Call.h"

class Control
{
  public:
		Control();
		~Control();
		void launch();

  private:
		int numSubs;
		Array *allCalls;
		Subscriber *subs[MAX_ARR];
		void print();
		void findSubNum(string, Subscriber**);
		void initSubscribersTemp();
		void initCallsTemp();
		void addSub(string);
		void addCall(string,string,int,int,int,int,int,int);
};

#endif
