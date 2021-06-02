#ifndef ANIREPGEN_H
#define ANIREPGEN_H

/*
	Purpose: Derived entity class from ReportGenerator. Computes and prints data for report 3.
*/

#include <iostream>
#include <string>
using namespace std;

#include "ReportGenerator.h"
#include "ReportData.h"
#include "Record.h"

class AnimalRepGen : public ReportGenerator
{
  public:
		AnimalRepGen();
		virtual ~AnimalRepGen();
		virtual void compute();
		void printReport();

	private:
		ReportData<int> *report;
		void formatData(vector<string>&, vector<string>&, vector<int>&);
		void printToStream(ostream&);
};

#endif