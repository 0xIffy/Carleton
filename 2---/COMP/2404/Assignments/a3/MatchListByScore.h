#ifndef MATCHLISTBYSCORE_H
#define MATCHLISTBYSCORE_H

/*
	Purpose: A collection class that stores match objects sorted by match score
*/

#include "MatchList.h"

class MatchListByScore : public MatchList
{
  public:
		MatchListByScore();
		void add(Match*);

  private:

};

#endif
