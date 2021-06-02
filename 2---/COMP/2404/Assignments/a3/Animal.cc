#include <iostream>
#include <iomanip>
using namespace std;
#include <string>
#include "Animal.h"

int Animal::nextId = 1001;

Animal::Animal(SpeciesType s, string b, string c, string n, string g, int y, int m)
	: Identifiable(nextId, "A"), name(n), breed(b), gender(g), colour(c), age(y*12+m), species(s)
{}


string Animal::getName(){ return name; }

string Animal::getBreed(){ return breed; }

string Animal::getGender(){ return gender; }

string Animal::getSpeciesName(){
	string s;

	switch(species){
		case C_DOG:
			s = "Dog";
			break;
		case C_CAT:
			s = "Cat";
			break;
		case C_BIRD:
			s = "Bird";
			break;
		case C_RABBIT:
			s = "Rabbit";
			break;
		case C_OTHER:
			s = "Other";
			break;
		default:
			s = "Undefined";
	}

	return s;
}

int Animal::getAge(){ return age; }

void Animal::print(){
	cout << left << setfill(' ') << setw(8) << id
	<< left << setfill(' ') << setw(10) << getSpeciesName()
	<< left << setfill(' ') << setw(25) << breed
	<< left << setfill(' ') << setw(3) << gender
	<< left << setfill(' ') << setw(25) << name
	<< left << setfill(' ') << setw(15) << colour
	<< right << setfill(' ') << setw(2) << age/12 << "y, " 
	<< right << setfill(' ') << setw(2) << age%12 << "m" <<	endl;
}