#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;
#include <string>

#include "YearRepGen.h"

YearRepGen::YearRepGen()
	: ReportGenerator(), report(new ReportData<float>(new AscBehaviour<float>()))
{}

YearRepGen::~YearRepGen(){
	delete report;
}

void YearRepGen::compute(){
	vector<int> years = yearMap->getKeys();
	vector<int> numAnimals;
	vector<Record*> recs;
	vector<string> animalTypes;

	int n = yearMap->getSize();
	int m;
	bool counted;

	for(int i = 0; i < n; ++i){
		recs = (*yearMap)[years[i]];
		m = recs.size();

		numAnimals.push_back(0);

		for(int j = 0; j < m; ++j){
			counted = false;
			if(recs[j]->getRegion() != "CAN" || recs[j]->getSubregion() != "All")
				continue;

			numAnimals[i] += recs[j]->getNumAnimals();

			for(int k = 0; k < animalTypes.size(); ++k){
				if(recs[j]->getAnimalType() == animalTypes[k]){
					counted = true;
				}
			}

			if(!counted){
				animalTypes.push_back(recs[j]->getAnimalType());
			}
		}
	}

	vector<vector<float>> aniPcts;

	for(int i = 0; i < n; ++i){
		recs = (*yearMap)[years[i]];
		m = recs.size();

		vector<float> temp;
		for(int k = 0; k < animalTypes.size(); ++k){
			temp.push_back(0);
		}

		for(int j = 0; j < m; ++j){
			if(recs[j]->getRegion() != "CAN" || recs[j]->getSubregion() != "All")
				continue;

			for(int k = 0; k < animalTypes.size(); ++k){
				if(recs[j]->getAnimalType() == animalTypes[k]){
					temp[k] = ((float) recs[j]->getNumAnimals() / numAnimals[i]) * 100;
				}
			}
		}

		aniPcts.push_back(temp);
	}

	vector<float> temp;
	for(int k = 0; k < animalTypes.size(); ++k){
		temp.push_back(aniPcts[1][k] - aniPcts[0][k]);
	}

	aniPcts.push_back(temp);

	formatData(aniPcts, animalTypes);
}

void YearRepGen::formatData(vector<vector<float>>& pcts, vector<string>& aniType){
	report->resetRows();
	
	int n = aniType.size();

	for(int i = 0; i < n; ++i){
		stringstream ss;

		ss << setfill(' ') << setw(15) << right << aniType[i];

		for(int j = 0; j < pcts.size(); ++j){
			if(j == pcts.size()-1){
				if(pcts[j][i] > 0)
					ss << "\t" << setw(2) << right << fixed << setprecision(1) << "+" << pcts[j][i];
				else
					ss << "\t" << " " << setw(2) << right << fixed << setprecision(1) << pcts[j][i];	

				ss << endl;
				report->add(pcts[j][i], ss.str());
			} else
				ss << "\t" << setw(6) << right << fixed << setprecision(1) << pcts[j][i];
		}
	}

	printReport();
}

void YearRepGen::printReport(){
	printToStream(cout);

	ofstream outfile("percentChangOfAnimals.out", ios::out);

  if (!outfile) {
    cout << "Error:  could not open file" << endl;
    exit(1);
  }

	printToStream(outfile);
}

void YearRepGen::printToStream(ostream& output){
	output << "    "
			 << "PERCENTAGE CHANGE OF ANIMALS (2011-2016)" << endl;
	output << "    "
			 << "-----------------------------------------" << endl << endl;

	output << setfill(' ') << setw(15) << " " 
			 << "\t" << setw(6) << "2011" << "\t" << setw(6) << "2016"
			 << "\t" << setw(6) << "Change" << endl;

	output << *report;
}