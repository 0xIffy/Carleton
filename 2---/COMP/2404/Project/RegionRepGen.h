#ifndef REGREPGEN_H
#define REGREPGEN_H

/*
	Purpose: Derived entity class from ReportGenerator. Computes and prints data for report 1.
*/

#include <iostream>
#include <string>
using namespace std;

#include "ReportGenerator.h"
#include "ReportData.h"
#include "Record.h"


class RegionRepGen : public ReportGenerator
{
  public:
		RegionRepGen();
		virtual ~RegionRepGen();
		virtual void compute();
		void printReport();

	private:
		ReportData<float> *report;
		void formatData(vector<vector<float>>&);
		void printToStream(ostream&);

};

#endif