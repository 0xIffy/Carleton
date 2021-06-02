#ifndef DATE_H
#define DATE_H

/*
	Purpose: An entity class that stores relevant information pertaining to a specific date and allows comparisons between dates
*/

class Date
{
  public:
    Date(int=0, int=0, int=2000);
		Date(Date&);
    void setDate(int, int, int);
		bool lessThan(Date&);
		bool equals(Date&);
		void print();
		void add(int);

  private:
    int day;
    int month;
    int year;
    int  lastDayInMonth();
    bool leapYear();
    string getMonthStr() const;
};

#endif