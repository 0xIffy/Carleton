#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;
#include <string>

#include "RegionRepGen.h"

RegionRepGen::RegionRepGen()
	: ReportGenerator(), report(new ReportData<float>(new DescBehaviour<float>()))
{}

RegionRepGen::~RegionRepGen(){
	delete report;
}

void RegionRepGen::compute(){
	vector<string> regions = regionMap->getKeys();
	vector<string> animalTypes;
	vector<int> numFarms;
	vector<Record*> recs;

	int totalFarms = 0;
	int n = regionMap->getSize();
	int m;
	bool conuted = false;

	for(int i = 0; i < n; ++i){
		if(regions[i] == "CAN")
			continue;

		recs = (*regionMap)[regions[i]];
		m = recs.size();

		for(int j = 0; j < m; ++j){
			conuted = false;
			if(recs[j]->getYear() != 2016 || recs[j]->getSubregion() != "All")
				continue;
			

			for(int k = 0; k < animalTypes.size(); ++k){
				if(recs[j]->getAnimalType() == animalTypes[k]){
					numFarms[k] += recs[j]->getNumFarms();
					conuted = true;
				}
			}

			if(!conuted){
				animalTypes.push_back(recs[j]->getAnimalType());
				numFarms.push_back(recs[j]->getNumFarms());
			}

			totalFarms += recs[j]->getNumFarms();
		}
	}

	vector<vector<float>> pcts;
	int aniPerReg;
	
	for(int i = 0; i < n; ++i){
		recs = (*regionMap)[regions[i]];
		m = recs.size();

		aniPerReg = 0;
		vector<float> temp;
		for(int k = 0; k < animalTypes.size()+1; ++k){
			temp.push_back(0);
		}

		for(int j = 0; j < m; ++j){
			if(recs[j]->getYear() != 2016 || recs[j]->getSubregion() != "All" || recs[j]->getRegion() == "CAN")
				continue;

			for(int k = 0; k < animalTypes.size(); ++k){
				if(recs[j]->getAnimalType() == animalTypes[k]){
					temp[k] = ((float) recs[j]->getNumFarms() / numFarms[k]) * 100;
				}
			}

			aniPerReg += recs[j]->getNumFarms();
		}	
		
		temp[animalTypes.size()] = ((float) aniPerReg / totalFarms) * 100;
		pcts.push_back(temp);
	}

	formatData(pcts);
}

void RegionRepGen::formatData(vector<vector<float>>& pcts){
	report->resetRows();

	vector<string> regions = regionMap->getKeys();
	int n = regionMap->getSize();

	for(int i = 0; i < n; ++i){
		if(regions[i] == "CAN")
			continue;

		stringstream ss;

		ss << setfill(' ') << setw(3) << regions[i];
		for(int j = 0; j < pcts[i].size(); ++j){
			ss << " " << setw(5) << right << fixed << setprecision(1) << pcts[i][j] << setw(3) << " ";
		}

		ss << endl;
		report->add(pcts[i][pcts[i].size()-1], ss.str());
	}

	printReport();
}

void RegionRepGen::printReport(){
	printToStream(cout);

	ofstream outfile("percentageOfFarmsByRegion.out", ios::out);

  if (!outfile) {
    cout << "Error:  could not open file" << endl;
    exit(1);
  }

	printToStream(outfile);
}

void RegionRepGen::printToStream(ostream& output){
	output << "                                "
			 << "PERCENTAGE OF FARMS BY REGION" << endl;
	output << "                                "
			 << "-----------------------------" << endl << endl;

	output << left << setfill(' ') << setw(3) << " " << " " << setw(8) << "Horses/" << " " << setw(8) << "Goats"
			 << " " << setw(8) << "Llamas/" << " " << setw(8) << "Rabbits" 
			 << " " << setw(8) << "Bison/"
			 << " " << setw(8) << "Elk/" << " " << setw(8) << "Domestic"
			 << " " << setw(1) << " " << setw(7) << "Mink" << " " << setw(8) << "Totals" << endl;
	
	output << left << setfill(' ') << setw(3) << " " << " " << setw(8) << "Ponies" << " " << setw(8) << " "
			 << " " << setw(8) << "Alpacas" << " " << setw(8) << " " 
			 << " " << setw(8) << "Buffalo"
			 << " " << setw(8) << "Wapiti" << " " << setw(8) << "Deer"
			 << " " << setw(8) << " " << " " << setw(8) << " " << endl;

	output << *report;
}