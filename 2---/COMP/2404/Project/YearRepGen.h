#ifndef YEARREPGEN_H
#define YEARREPGEN_H

/*
	Purpose: Derived entity class from ReportGenerator. Computes and prints data for report 2.
*/

#include <iostream>
#include <string>
using namespace std;

#include "ReportGenerator.h"
#include "ReportData.h"
#include "Record.h"

class YearRepGen : public ReportGenerator
{
  public:
		YearRepGen();
		virtual ~YearRepGen();
		virtual void compute();
		void printReport();

	private:
		ReportData<float> *report;
		void formatData(vector<vector<float>>&, vector<string>&);
		void printToStream(ostream&);
};

#endif