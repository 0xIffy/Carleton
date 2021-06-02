#ifndef GUEST_H
#define GUEST_H

/*
	Purpose: An entity class. Handles guest data and interactions with other classes
*/

#include <string>

class Guest
{
	public:
		Guest(string="", bool=false);
		string getName();
		bool getPremStat();
		void print();
		void addPts(int);

	private:
		string name;
		bool premium;
		int pnts;
};

#endif
