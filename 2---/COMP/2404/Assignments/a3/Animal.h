#ifndef ANIMAL_H
#define ANIMAL_H

/*
	Purpose: An entity class. Handles animal data and interactions with other classes
*/

#include <string>
#include "Identifiable.h"
#include "defs.h"

class Animal : public Identifiable
{
  public:
		Animal(SpeciesType, string="", string="", string="", string="", int=0, int=0);
		string getName();
		string getBreed();
		string getGender();
		string getSpeciesName();
		int getAge();
		void print();

  private:
		static int nextId;
		string name;
		string breed;
		string gender;
		string colour;
		SpeciesType species;
		int age;

};

#endif
