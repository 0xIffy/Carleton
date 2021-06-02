#ifndef CRITERIA_H
#define CRITERIA_H

/*
	Purpose: An entity class. Handles criteria data and interactions with other classes
*/

#include <string>
using namespace std;

class Criteria
{
  public:
    Criteria(string="", string="", int=0);
    string getName();
    string getValue();
    int    getWeight();
    void   print();

  private:
    string name;
    string value;
    int    weight;
};

#endif
