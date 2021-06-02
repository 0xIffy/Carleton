#include <iostream>
using namespace std;
#include <string>

#include "Telco.h"

Telco::Telco(string n)
	: name(n), numSubs(0), allCalls(new Array())
{}

Telco::~Telco(){
	allCalls->cleanup();
	delete allCalls;

	for(int i = 0; i < numSubs; ++i){
		delete subs[i];
	}
}

void Telco::addSub(Subscriber *s){
	if(numSubs >= MAX_ARR)
		return;

	for(int i = 0; i < numSubs; ++i){
		if(s->getPhoneNum() == subs[i]->getPhoneNum()){
			cout<<"Error: a subscriber with that phone number already exists";
			return;
		}
	}

	subs[numSubs] = s;
	numSubs += 1;
}

void Telco::addCall(string srcNum, string destNum, int y, int m, int d, int h, int min, int dur){
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

void Telco::computeFreqCaller(string destNum){
	Subscriber *dest;
	string message;

	if(destNum != "all"){
		findSubNum(destNum, &dest);

		if(dest == NULL){
			return;
		}
	}

	string (Call::*getNum)();
	getNum = &Call::getSrc;

	message = "Most frequent caller to " + destNum + ": ";

	if(destNum == "all"){
		calcFreq(*allCalls, getNum, message);
	} else{
		calcFreq(dest->getIncoming(), getNum, message);
	}
}

void Telco::computeFreqCalled(string srcNum){
	Subscriber *src;
	string message;

	if(srcNum != "all"){
		findSubNum(srcNum, &src);

		if(src == NULL){
			return;
		}
	}

	string (Call::*getNum)();
	getNum = &Call::getDest;

	message = "Most frequently called by " + srcNum + ": ";

	if(srcNum == "all"){
		calcFreq(*allCalls, getNum, message);	
	} else{
		calcFreq(src->getOutgoing(), getNum, message);
	}
}

void Telco::print(){
	cout<<"Company Name: "<<name<<endl<<endl;

	for(int i  = 0; i < numSubs; ++i){
		cout<<"Subscriber"<<": ";
		subs[i]->print();
	}
}

void Telco::findSubNum(string num, Subscriber **s){
	*s = NULL;

	for(int i = 0; i < numSubs; ++i){
		if(subs[i]->getPhoneNum() == num){
			*s = subs[i];
			return;
		}
	}

	cout<<"Error: could not find that number in the list of subscribers."<<endl;
}

void Telco::calcFreq(Array& arr, string (Call::*getNum)(), string message){
	int size = arr.getSize();
	Call *c;
	string phoneNums[size];
	int numCount[size];
	string temp;
	int n = 0;
	int maxCount;

	for(int i = 0; i < size; ++i){
		c = arr.get(i);
		temp = (c->*getNum)();

		for(int j = 0; j <= n; ++j){
			if(j == n){
				if(n == 0)
					maxCount = 1;

				phoneNums[j] = temp;
				numCount[j] = 1;
				n += 1;
				break;
			}

			if(temp == phoneNums[j]){
				numCount[j] += 1;

				if(numCount[j] > maxCount)
					maxCount = numCount[j];
					
				break;
			}
		}
	}

	for(int i = 0; i < n; ++i){
		if(numCount[i] < maxCount)
			continue;

		cout<<message<<phoneNums[i]<<endl;

		for(int j = 0; j < size; ++j){
			c = arr.get(j);

			if((c->*getNum)() == phoneNums[i]){
				c->print();
			}
		}

		cout<<endl;
	}
}