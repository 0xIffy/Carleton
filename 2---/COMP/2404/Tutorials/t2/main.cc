#include <iostream>
using namespace std;
#include <string>
#include "Calendar.h"
#include "Date.h"

void initDates(Calendar *, Calendar *);

int main(){
	Calendar *c1, *c2;

	c1 = new Calendar("Work");
	c2 = new Calendar("Home");

	initDates(c1, c2);

	cout<<endl;
	
	c1->print();
	c2->print();

	delete c1;
	delete c2;
	return 0;
}


void initDates(Calendar *c1, Calendar *c2)
{
	c1->add(new Date("D1",23,45,2221,33));
	c1->add(new Date("D2",4,9,2001,3,23,24*60,false));
	c1->add(new Date("D3",3,4,221,9,40,50,true,10));
	c1->add(new Date("D4",10,5,1,3,40,53,true,3));

	c2->add(new Date("D5",23,5,2019,12,40,800,false));
	c2->add(new Date("D6",23,8,1921,3,40,70));
	c2->add(new Date("D7",31,1,2010,33,40));
	c2->add(new Date("D8",7,6,2005,7,40,533,true,35));
}

