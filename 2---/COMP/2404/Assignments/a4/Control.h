#ifndef CONTROL_H
#define CONTROL_H

/*
	Purpose: An control class. Handle the overall control flow for the program
*/

#include <string>
#include "ResManager.h"
#include "Hotel.h"
#include "View.h"
#include "Recorder.h"

class Control
{
	public:
		Control();
		~Control();
		void launch();

	private:
		View *view;
		Hotel *hotel;
		ResManager *resMgr;
		void initHotel();
};

#endif
