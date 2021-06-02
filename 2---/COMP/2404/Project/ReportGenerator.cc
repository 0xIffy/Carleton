#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <string>

#include "ReportGenerator.h"

vector<Record*> ReportGenerator::records;
Map<int>*    ReportGenerator::yearMap = new Map<int>();
Map<string>* ReportGenerator::regionMap = new Map<string>();
Map<string>* ReportGenerator::animalMap = new Map<string>();

ReportGenerator::ReportGenerator(){}

ReportGenerator::~ReportGenerator(){}

void ReportGenerator::getData(){
	int n1, n2, n3;
	string s1, s2, s3;
	Record *rec;

	ifstream infile("farms.dat", ios::in);

  if (!infile) {
    cout << "Error: could not open file" << endl;
    exit(1);
  }

  while ( infile >> n1 >> s1 >> s2 >> s3 >> n2 >> n3 ) {
   	rec = new Record(n1, s1, s2, s3, n2, n3);
    records.push_back(rec);

		yearMap->add(n1,rec);
		regionMap->add(s1,rec);
		animalMap->add(s3,rec);
  }
}

void ReportGenerator::cleanup(){
	delete yearMap;
	delete regionMap;
	delete animalMap;

	for(int i = 0; i < records.size(); ++i){
		delete records[i];
	}
}
