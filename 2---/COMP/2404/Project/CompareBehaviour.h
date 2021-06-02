#ifndef COMPBEHAV_H
#define COMPBEHAV_H

/*
	Purpose: Template base entity class. Allows comparison between 2 data types of the same type.
*/

#include <iostream>
#include <string>
using namespace std;

template <class T>
class CompareBehaviour
{
  public:
    virtual bool compare(T, T) = 0;
};

#endif

#ifndef ASCBEHAV_H
#define ASCBEHAV_H

/*
	Purpose: Template derived entity class fromm CompareBehaviour. Compares data types for increasing order.
*/

template <class T>
class AscBehaviour : public CompareBehaviour<T>
{
  public:
    virtual bool compare(T, T);
};

template <class T>
bool AscBehaviour<T>::compare(T v1, T v2){
	if(v1 < v2){
		return true;
	} else{
		return false;
	}
}

#endif

#ifndef DESCBEHAV_H
#define DESCBEHAV_H

/*
	Purpose: Template derived entity class fromm CompareBehaviour. Compares data types for decreasing order.
*/

template <class T>
class DescBehaviour : public CompareBehaviour<T>
{
  public:
    virtual bool compare(T, T);
};

template <class T>
bool DescBehaviour<T>::compare(T v1, T v2){
	if(v1 > v2){
		return true;
	} else{
		return false;
	}
}

#endif

