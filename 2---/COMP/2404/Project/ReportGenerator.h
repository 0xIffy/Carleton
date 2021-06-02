#ifndef REPGEN_H
#define REPGEN_H

/*
	Purpose: Base entity class with some aspects of a control class. Reads from data file
					 stores collection of records.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Record.h"
#include "Map.h"

class ReportGenerator
{
  public:
		ReportGenerator();
		virtual ~ReportGenerator();
		static void getData();
		static void cleanup();
		virtual void compute() = 0;

	protected:
    static vector<Record*> records;
		static Map<int> *yearMap;
		static Map<string> *regionMap;
		static Map<string> *animalMap;
};

#endif