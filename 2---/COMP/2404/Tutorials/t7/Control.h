#ifndef CONTROL_H
#define CONTROL_H

#include <string>
#include "ResManager.h"
#include "Hotel.h"

class Control
{
	public:
		Control();
		~Control();
		void launch();

	private:
		Hotel *hotel;
		ResManager *resMgr;
		void initHotel();
};

#endif
