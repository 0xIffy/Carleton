#ifndef MATCHLIST_H
#define MATCHLIST_H

/*
	Purpose: A collection class that stores match objects. Serves as base class for any class that stores matches
*/

#include "Match.h"

class MatchList
{
	protected:
		class Node
		{
			public:
				Match* data;
				Node*    next;
		};
		Node* head;

  public:
    MatchList();
    ~MatchList();
    void print() const;
		void cleanup();
};

#endif
