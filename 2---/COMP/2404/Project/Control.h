#ifndef CONTROL_H
#define CONTROL_H

/*
	Purpose: An control class. Handle the overall control flow for the program.
*/

#include <string>
#include <vector>
#include "ReportGenerator.h"
#include "RegionRepGen.h"
#include "AnimalRepGen.h"
#include "YearRepGen.h"
#include "View.h"

class Control
{
	public:
		Control();
		~Control();
		void launch();

	private:
		vector<ReportGenerator*> repGens;
		View *view;
};

#endif
