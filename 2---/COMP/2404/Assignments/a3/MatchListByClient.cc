#include <iostream>
#include <string>
using namespace std;

#include "MatchListByClient.h"

MatchListByClient::MatchListByClient()
	: MatchList()
{}

void MatchListByClient::add(Match *m){
	Node* newNode;
  Node* currNode;
  Node* prevNode;

  newNode = new Node();
  newNode->data = m;
  newNode->next = NULL;

  currNode = head;
  prevNode = NULL;

  while (currNode != NULL) {
    if (newNode->data->getClientId() < currNode->data->getClientId())
      break;
		else if(newNode->data->getClientId() == currNode->data->getClientId() && newNode->data->getScore() > currNode->data->getScore())
			break;
			
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (prevNode == NULL)
    head = newNode;
  else
    prevNode->next = newNode;

  newNode->next = currNode;
}