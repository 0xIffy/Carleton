#ifndef CONTROL_H
#define CONTROL_H

/*
	Purpose: A control class that initializes the data and implements the main control flow for the program
*/

#include "Telco.h"
#include "View.h"

class Control
{
  public:
		Control(string="");
		~Control();
		void launch();

  private:
		View view;
		Telco *telco;
		void initData(Telco*);
		void initSubscribers(Telco*);
		void initCalls(Telco*);
};

#endif
