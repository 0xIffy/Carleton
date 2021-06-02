#ifndef TIME_H
#define TIME_H

/*
	Purpose: An entity class that stores relevant information pertaining to a specific time and allows comparisons between times
*/

class Time
{
  public:
    Time(int=0, int=0);
    bool greaterThan(Time*);
    void print();

  private:
    int  hours;
    int  minutes;
    void setTime(int, int);
    int  convertToMins();
};

#endif
