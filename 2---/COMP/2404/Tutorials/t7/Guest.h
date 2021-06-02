#ifndef GUEST_H
#define GUEST_H

#include <string>

class Guest
{
	public:
		Guest(string="", bool=false);
		string getName();
		bool getPremStat();
		void print();


	private:
		string name;
		bool premium;
		int lPnts;
};

#endif
