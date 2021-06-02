#ifndef RECORD_H
#define RECORD_H

/*
	Purpose: An entity class. Stores data for individual records from the data file.
*/

#include <iostream>
#include <string>
using namespace std;


class Record
{
  public:
		Record(int=0, string="", string="", string="", int=0, int=0);
		int getYear();
		string getRegion();
		string getSubregion();
		string getAnimalType();
		int getNumFarms();
		int getNumAnimals();
    
	private:
		int year;
		string region;
		string subregion;
		string animalType;
		int numFarms;
		int numAnimals;
};

#endif