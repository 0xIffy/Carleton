#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Date.h"


// Date::Date(int d, int m, int y)
// {
//   cout<<"in default constructor"<<endl;
//   setDate(d, m, y);
// }

Date::Date(string n, int d, int m, int y, int h, int min, int du, bool r, int rWeeks){
	eventName = n;
	recurs = r;
	
	setDate(d, m, y);
	valid = validate(d, m, y, h, m, du);

	int hour = h >= 0 && h < 24 ? h : 0;
	int minute = min >= 0 && min < 60 ? min : 0;

	startTime = hour * 60 + minute;
	duration = du >= 0 ? du : 0;

	rWeeks = rWeeks > 0 ? rWeeks : 10;
	weeksRecurring = recurs ? rWeeks : 0;
}

Date::Date(Date& oldDate){
	eventName = oldDate.eventName;
	recurs = oldDate.recurs;
	valid = oldDate.valid;
	day = oldDate.day;
	month = oldDate.month;
	year = oldDate.year;
	startTime = oldDate.startTime;
	duration = oldDate.duration;
	weeksRecurring = oldDate.weeksRecurring;
}

void Date::setDate(int d,int m,int y)
{
  year  = ( ( y > 0) ? y : 0 );
  month = ( ( m > 0 && m <= 12 ) ? m : 0 );
  day   = ( ( d > 0 && d <= lastDayInMonth() ) ? d : 0 );
}

bool Date::lessThan(Date *d){
	if(year == d->year){
		if(month == d->month){
			if(day == d->day){
				if(startTime == d->startTime){
					return false;
				} else{
					return startTime < d->startTime;
				}
			} else{
				return day < d->day;
			}
		} else{
		return month < d->month;
	}
	} else{
		return year < d->year;
	}
}

bool Date::validate(int d, int m, int y, int h, int min, int du){
	return y > 0 && m > 0 && m <= 12 && d > 0 && d <= lastDayInMonth() && 
				 h >= 0 && h < 24 && min >= 0 && min < 60 && du >= 0;
}

bool Date::isValid(){
	return valid;
}

bool Date::doesRecur(){
	return recurs;
}

void Date::print(){
	cout<<setfill(' ')<<setw(35)<<eventName<<":";

	printLong();

	int h = startTime / 60;
	int min = startTime % 60;

	cout<<" @ "<<setfill('0')<<setw(2)<<h<<":"
		  <<setfill('0')<<setw(2)<<min;

	h = (startTime + duration) / 60;
	min = (startTime + duration) % 60;

	cout<<" - "<<setfill('0')<<setw(2)<<h<<":"
		  <<setfill('0')<<setw(2)<<min;

	if(recurs){
		cout<<", recurs weekly for "<< weeksRecurring <<" weeks"<<endl;
	} else{
		cout<<endl;
	}
}

int Date::lastDayInMonth()
{
  switch(month)
  {
    case 2:
      if (leapYear())
        return 29;
      else
        return 28;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    default:
      return 30;
  }
}

bool Date::leapYear()
{
  if ( year%400 == 0 ||
       (year%4 == 0 && year%100 != 0) )
    return true;
  else
    return false;
}

string Date::getMonthStr()
{
  string monthStrings[] = { 
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December" };

  if ( month >= 1 && month <= 12 )
    return monthStrings[month-1];
  else
    return "Unknown";
}

void Date::printLong()
{
  cout<<setfill(' ')<<setw(10)<<getMonthStr()<<" "<<setw(2)<<day<<", "<<setw(4)<<year;
}
