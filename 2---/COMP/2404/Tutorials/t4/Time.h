#ifndef TIME_H
#define TIME_H

class Time
{
  public:
    Time(int=0, int=0);
    void setTime(int, int);
    bool greaterThan(Time*);
    void print();

  private:
    int hours;
    int minutes;
    int convertToMins();
};

#endif
