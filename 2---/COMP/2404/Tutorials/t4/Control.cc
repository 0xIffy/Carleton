#include <iostream>
using namespace std;
#include <string>

#include "Control.h"

Control::Control()
	: numSubs(0), allCalls(new Array())
{}

Control::~Control(){
	allCalls->cleanup();
	delete allCalls;

	for(int i = 0; i < numSubs; ++i){
		delete subs[i];
	}
}

void Control::launch(){
	initSubscribersTemp();
	initCallsTemp();

	print();
}

void Control::addSub(string pn){
	if(numSubs >= MAX_ARR)
		return;

	Subscriber *s = new Subscriber(pn);

	for(int i = 0; i < numSubs; ++i){
		if(s->getPhoneNum() == subs[i]->getPhoneNum()){
			cout<<"Error: a subscriber with that phone number already exists";
			return;
		}
	}

	subs[numSubs] = s;
	numSubs += 1;
}

void Control::addCall(string srcNum, string destNum, int y, int m, int d, int h, int min, int dur){
	Subscriber *src, *dest;
	Call *c;
	
	findSubNum(srcNum, &src);
	findSubNum(destNum, &dest);

	if(dest == NULL && src == NULL)
		return;

	c = new Call(srcNum, destNum, y, m, d, h, min, dur);
	allCalls->add(c);

	if(src != NULL)
		src->addOutgoing(c);

	if(dest != NULL)
		dest->addIncoming(c);
}

void Control::print(){
	for(int i  = 0; i < numSubs; ++i){
		cout<<"Subscriber"<<": ";
		subs[i]->print();
	}
}

void Control::findSubNum(string num, Subscriber **s){
	*s = NULL;

	for(int i = 0; i < numSubs; ++i){
		if(subs[i]->getPhoneNum() == num){
			*s = subs[i];
			return;
		}
	}

	cout<<"Error: could not find that number in the list of subscribers."<<endl;
}

void Control::initSubscribersTemp()
{
  addSub("6139990000"); 
  addSub("6133334444");
  addSub("6138889999"); 
  addSub("6131112222");
  addSub("6132223333");
  addSub("6134445555"); 
}

void Control::initCallsTemp()
{
  addCall("6139990000", "6133334444", 2020, 1, 1, 0, 31, 12);
  addCall("6139990000", "6132223333", 2019, 2, 2, 10, 54, 2);

  addCall("6132223333", "6139990000", 2019, 2, 23, 6, 33, 11);
  addCall("6132223333", "6139990000", 2019, 3, 2, 10, 54, 2);
  addCall("6132223333", "6139990000", 2019, 2, 20, 14, 22, 5);
  addCall("6132223333", "6131112222", 2019, 12, 18, 4, 5, 15);

  addCall("6131112222", "6132223333", 2019, 6, 30, 6, 2, 5);
  addCall("6131112222", "6139990000", 2019, 8, 9, 8, 29, 7);
  addCall("6131112222", "6130000000", 2019, 8, 9, 8, 29, 7);
  addCall("6131112222", "6138889999", 2019, 3, 10, 15, 12, 11);

  addCall("6134445555", "6138889999", 2019, 3, 10, 15, 22, 1);
  addCall("6134445555", "6138887777", 2019, 3, 10, 15, 24, 10);
}

