#include <iostream>
using namespace std;
#include <string>
#include "Animal.h"

int Animal::nextId = 1001;

Animal::Animal(SpeciesType s, string n, string b, string g, string c, int y, int m)
	: Identifiable(nextId, "A"), name(n), breed(b), gender(g), colour(c), age(y*12+m), species(s)
{}


string Animal::getName(){ return name; }

string Animal::getBreed(){ return breed; }

string Animal::getGender(){ return gender; }

int Animal::getAge(){ return age; }

void Animal::print(){
	cout << id << endl;
}