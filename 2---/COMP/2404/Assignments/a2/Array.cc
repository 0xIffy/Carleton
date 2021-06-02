#include <iostream>
using namespace std;

#include "Array.h"

Array::Array()
{
  size = 0;
}

Array::Array(Array& arr){
	size = 0;

	add(arr);
}

Array::~Array()
{
  // for (int i=0; i<size; ++i)
    // delete elements[i];
}

bool Array::add(Call* c)
{
  if (size >= MAX_ARR)
    return false;

  for(int i = size; i >= 0; --i){
		if(i > 0 && c->greaterThan(elements[i-1])){
			elements[i] = elements[i-1];
		} else{
			elements[i] = c;
			break;
		}
	}

	size += 1;

	return true;
}

bool Array::add(Array& arr){
	for(int i = 0; i < arr.size; ++i){
		if(!add(arr.elements[i]))
			return false;
	}

	return true;
}

void Array::print()
{
  // cout << endl << "Calls:" << endl;
  for (int i=0; i<size; ++i)
    elements[i]->print();

  cout << endl;
}

void Array::cleanup(){
	for (int i=0; i<size; ++i)
    delete elements[i];
}

int Array::getSize(){
	return size;
}

Call* Array::get(int i){
	return elements[i]; // Can pointer be modified after this?
}