#include <iostream>
#include <string>
using namespace std;

#include "Subscriber.h"

Subscriber::Subscriber(string pn)
	: phoneNum(pn), inCalls(new Array()), outCalls(new Array())
{

}

Subscriber::~Subscriber(){
	delete inCalls;
	delete outCalls;
}

void Subscriber::addIncoming(Call *c){
	inCalls->add(c);
}

void Subscriber::addOutgoing(Call *c){
	outCalls->add(c);
}

void Subscriber::print(){
	Array arr(*inCalls);
	arr.add(*outCalls);

	cout<<phoneNum<<endl;
	arr.print();
}

string Subscriber::getPhoneNum(){
	return phoneNum;
}

Array& Subscriber::getIncoming(){
	return *inCalls;
}

Array& Subscriber::getOutgoing(){
	return *outCalls;
}