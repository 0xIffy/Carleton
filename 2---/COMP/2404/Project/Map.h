#ifndef MAP_H
#define MAP_H

/*
	Purpose: Template collection class. Stores a collection of keys of the given data type and their mapping to a collection of records.
*/

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

#include "Record.h"

template <class T>
class Map
{
  public:
		Map();
		~Map();
		void add(T, Record*);
		int getSize();
		vector<T>& getKeys();
		vector<Record*>& operator[](T&);

	private:
		vector<T> keys;
		vector<vector<Record*>> values;
};

template <class T>
Map<T>::Map(){}

template <class T>
Map<T>::~Map(){}

template <class T>
void Map<T>::add(T key, Record* rec){
	for(int j = 0; j < keys.size(); j++){
		if(keys[j] == key){
			values[j].push_back(rec);

			return;
		}
	}

	keys.push_back(key);
	vector<Record*> temp;
	temp.push_back(rec);
	values.push_back(temp);
}

template <class T>
int Map<T>::getSize(){ return keys.size(); }

template <class T>
vector<T>& Map<T>::getKeys(){ return keys; }

template <class T>
vector<Record*>& Map<T>::operator[](T& i){ 
	try{
		for(int j = 0; j < keys.size(); j++){
			if(keys[j] == i){
				return values[j];
			}
		}

		throw "No such key exception"; 
	} catch(const char* err){
		cout << err << endl;

	}
}

#endif