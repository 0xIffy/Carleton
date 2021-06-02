#ifndef MATCHLIST_H
#define MATCHLIST_H

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
    // void add(Match*);
    void print() const;
		void cleanup();

  private:
    

};

#endif
