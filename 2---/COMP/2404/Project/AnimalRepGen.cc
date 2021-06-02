#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;
#include <string>

#include "AnimalRepGen.h"

AnimalRepGen::AnimalRepGen()
	: ReportGenerator(), report(new ReportData<int>(new DescBehaviour<int>()))
{}

AnimalRepGen::~AnimalRepGen(){
	delete report;
}

void AnimalRepGen::compute(){
	string animal = "Horses-Ponies";
	vector<int> numAnimals;
	vector<Record*> recs;
	vector<string> regions;
	vector<string> subregions;

	int m;
	bool counted;

	recs = (*animalMap)[animal];
	m = recs.size();

	for(int j = 0; j < m; ++j){
		counted = false;
		if(recs[j]->getRegion() == "CAN" || recs[j]->getSubregion() == "All" || recs[j]->getYear() != 2016)
			continue;

		for(int i = 0; i < regions.size(); ++i){
			if(recs[j]->getRegion() == regions[i]){
				subregions[i] = recs[j]->getNumAnimals() > numAnimals[i] ? recs[j]->getSubregion() : subregions[i];
				numAnimals[i] = recs[j]->getNumAnimals() > numAnimals[i] ? recs[j]->getNumAnimals() : numAnimals[i];
				counted = true;
			}
		}

		if(!counted){
			regions.push_back(recs[j]->getRegion());
			subregions.push_back(recs[j]->getSubregion());
			numAnimals.push_back(recs[j]->getNumAnimals());
		}
	}

	formatData(regions, subregions, numAnimals);
}

void AnimalRepGen::formatData(vector<string>& regs, vector<string>& subReg, vector<int>& numA){
	report->resetRows();

	for(int i = 0; i < regs.size(); ++i){
		stringstream ss;

		ss << setfill(' ') << setw(3) << regs[i] << "\t" << setw(35) << subReg[i] << "\t" << setw(6) << numA[i] << endl;

		report->add(numA[i], ss.str());
	}

	printReport();
}

void AnimalRepGen::printReport(){
	printToStream(cout);

	ofstream outfile("subregionsByNumHores.out", ios::out);

  if (!outfile) {
    cout << "Error:  could not open file" << endl;
    exit(1);
  }

	printToStream(outfile);
}

void AnimalRepGen::printToStream(ostream& output){
	output << "    "
			 << "SUB-REGION WITH MOST HORSES/PONIES BY REGION IN 2016" << endl;
	output << "    "
			 << "----------------------------------------------------" << endl << endl;

	output << *report;
}