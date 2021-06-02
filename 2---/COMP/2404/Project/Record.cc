#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

#include "Record.h"

Record::Record(int y, string r, string sr, string a, int nf, int na)
	: year(y), region(r), subregion(sr), animalType(a), numFarms(nf), numAnimals(na)
{}

int Record::getYear(){ return year; }

string Record::getRegion(){ return region; }

string Record::getSubregion(){ return subregion; }

string Record::getAnimalType(){ return animalType; }

int Record::getNumFarms(){ return numFarms; }

int Record::getNumAnimals(){ return numAnimals; }