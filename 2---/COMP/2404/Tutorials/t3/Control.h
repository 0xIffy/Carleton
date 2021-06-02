#ifndef CONTROL_H
#define CONTROL_H

#include "Call.h"
#define MAX_CALLS 64

class Control
{
  public:
		Control();
		~Control();
		void launch();

  private:
		int numCalls;
		Call *calls[MAX_CALLS];
		void initCallsTemp();
		void addCall(Call *);
};

#endif
