#include <iostream>
using namespace std;
#include <string>
#include "Date.h"

#define MAX_ARR  10

void addDate(Date* arr, int& size, string name, int day, int month, int year, int startHour, int startMinutes, int duration);
void initDates(Date *arr, int& size);
void printDates(Date *arr, int& size);

int main()
{
	Date arr[MAX_ARR];
	int size = 0;

	initDates(arr, size);
	printDates(arr, size);

  return 0;
}

void addDate(Date* arr, int& size, string name, int day, int month, int year, int startHour, int startMinutes, int duration){
	if(size >= MAX_ARR){
		cout<<"Date could not be added, array is full."<<endl;
		return;
	}

	Date d1(name,day,month,year,startHour,startMinutes,duration);
	arr[size] = d1;
	size += 1;
}

void initDates(Date *arr, int& size){
	addDate(arr,size,"D1",23,45,2221,33,40,533);
	addDate(arr,size,"D2",2,7,2001,3,23,213);
	addDate(arr,size,"D3",3,4,221,9,40,3);
	addDate(arr,size,"D4",1000,5,-1,3,40,53);
	addDate(arr,size,"D5",23,45,2221,12,40,800);
	addDate(arr,size,"D6",7,23,1921,3,40,70);
	addDate(arr,size,"D7",23,4,21,33,40,533);
	addDate(arr,size,"D8",23,45,2221,33,40,533);
}

void printDates(Date *arr, int& size){
	for(int i = 0; i < size; ++i){
		arr[i].print();
	}
}