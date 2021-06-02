#ifndef REPDATA_H
#define REPDATA_H

/*
	Purpose: Template entity/collection class. Stores a collection of formatted report data.
*/

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

#include "CompareBehaviour.h"

template <class T>
class ReportData
{
	class ReportRow{

		/*
			Purpose: Template entity class. Stores one row of formatted report data.
		*/

		public:
			ReportRow(T k, string d=""){
				key = k;
				data = d;
			}
	
			T key;
			string data;
	};
	
	template <class V>
	friend ostream& operator<<(ostream&, ReportData<V>&);
  public:
    ReportData(CompareBehaviour<T> *);
		~ReportData();
		void add(T, string);
		void resetRows();

	private:
		vector<ReportRow*> rows;
		CompareBehaviour<T> *comp;
};

template <class T>
ReportData<T>::ReportData(CompareBehaviour<T> *c)
	: comp(c)
{}

template <class T>
ReportData<T>::~ReportData(){
	resetRows();

	delete comp;
}

template <class T>
void ReportData<T>::add(T key, string d){
	typename vector<ReportRow*>::iterator itr;
	ReportRow *row;
	row = new ReportRow(key, d);

	for(itr = rows.begin(); itr != rows.end(); ++itr){
		if(!comp->compare((*itr)->key,key)){
			rows.insert(itr, row);

			return;
		}
	}

	rows.insert(itr, row);
}

template <class T>
void ReportData<T>::resetRows(){
	for(int i = 0; i < rows.size(); ++i){
		delete rows[i];
	}

	rows.clear();
}

template <class T>
ostream& operator<<(ostream& output, ReportData<T>& r){
	for(int i = 0; i < r.rows.size(); ++i)
		output << r.rows[i]->data;

	return output;
}

#endif