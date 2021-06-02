#ifndef DATE_H
#define DATE_H

/*
	Purpose: An entity class that stores relevant information pertaining to a specific date and allows comparisons between dates
*/

class Date
{
  public:
    Date(int=0, int=0, int=2000);
    ~Date();
    void setDate(int, int, int);
		bool greaterThan(Date *);
		bool equals(Date *);
		void print();

  private:
    int day;
    int month;
    int year;
    int  lastDayInMonth();
    bool leapYear();
    string getMonthStr() const;
};

#endif