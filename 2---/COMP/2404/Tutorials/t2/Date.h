#include <string>
#ifndef DATE_H
#define DATE_H

class Date
{
  public:
		Date(string="", int=0, int=0, int=2000, int=0, int=0, int=0, bool=false, int=10);
		Date(Date&);
    void setDate(int,int,int);
		bool lessThan(Date*);
		void print();
		bool isValid();
		bool doesRecur();

  private:
    int day;
    int month;
    int year;
		string eventName;
		int startTime;
		int duration;
		bool recurs;
		int weeksRecurring;
		bool valid;

    int  lastDayInMonth();
		bool validate(int,int,int,int,int,int);
    bool leapYear();
		void printLong();
    string getMonthStr();
};

#endif
