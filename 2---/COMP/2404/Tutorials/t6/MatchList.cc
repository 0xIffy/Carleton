#include <iostream>
#include <string>
using namespace std;

#include "MatchList.h"

MatchList::MatchList() : head(NULL) { }

MatchList::~MatchList()
{
  Node* currNode;
  Node* nextNode;

  currNode = head;

  while (currNode != NULL) {
    nextNode = currNode->next;
    // delete currNode->data;
    delete currNode;
    currNode = nextNode;
  }
}

void MatchList::print() const
{
  Node* currNode = head;

  while (currNode != NULL) {
    currNode->data->print();
    currNode = currNode->next;
  }
}

void MatchList::cleanup(){
	Node* currNode;
  Node* nextNode;

  currNode = head;

	while (currNode != NULL) {
    nextNode = currNode->next;
    delete currNode->data;
    currNode = nextNode;
  }
}

