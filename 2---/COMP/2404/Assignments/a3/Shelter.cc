#include <iostream>
using namespace std;
#include <string>
#include <time.h>
#include <cstdlib>

#include "Shelter.h"

Shelter::Shelter(string n)
	: numClients(0), numAnimals(0), name(n)
{}

Shelter::~Shelter(){
	for(int i = 0; i < numAnimals; ++i){
		delete animals[i];
	}

	for(int i = 0; i < numClients; ++i){
		delete clients[i];
	}
}

bool Shelter::add(Animal *a){
	if(numAnimals >= MAX_SIZE)
		return false;

	animals[numAnimals] = a;
	numAnimals++;

	return true;
}

bool Shelter::add(Client *c){
	if(numClients >= MAX_SIZE)
		return false;

	clients[numClients] = c;
	numClients++;

	return true;
}

void Shelter::computeMatches(MatchListByScore& ms, MatchListByClient& mc){
	Match *m;
	CriteriaArray *ca;
	Criteria *crit;
	int age, y;
	float prop, score;

	for(int i = 0; i < numClients; i++){
		ca = &(clients[i]->getCriteria());

		for(int j = 0; j < numAnimals; j++){
			score = 0;

			for(int k = 0; k < ca->getSize(); k++){
				crit = ca->get(k);

				if(crit->getName() == "Species" && crit->getValue() == animals[j]->getSpeciesName()){
					score += 10;
				} else if(crit->getName() == "Breed" && crit->getValue() == animals[j]->getBreed()){
					score += crit->getWeight();
				} else if(crit->getName() == "Gender" && crit->getValue() == animals[j]->getGender()){
					score += crit->getWeight();
				} else if(crit->getName() == "Age"){
					y = stoi(crit->getValue());
					age = animals[j]->getAge() / 12;

					prop = (float) abs(y - age) / 10 < 1 ? (float) abs(y - age) / 10 : 1.0;

					score += crit->getWeight() * (1 - prop);
				}	
			}

			if(score == 0)
				continue;

			m = new Match(animals[j], clients[i], score);

			ms.add(m);
			mc.add(m);
		}
	}
}

void Shelter::printAnimals(){
	cout << endl << "Animals:" << endl;
	for(int i = 0; i < numAnimals; i++){
		animals[i]->print();
	}
}

void Shelter::printClients(){
	cout << endl << "Clients:" << endl;
	for(int i = 0; i < numClients; i++){
		clients[i]->print();
	}
}

