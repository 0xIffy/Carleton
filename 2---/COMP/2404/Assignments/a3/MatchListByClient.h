#ifndef MATCHLISTBYCLIENT_H
#define MATCHLISTBYCLIENT_H

/*
	Purpose: A collection class that stores match objects sorted by client id
*/

#include "MatchList.h"

class MatchListByClient : public MatchList
{
  public:
		MatchListByClient();
		void add(Match*);

  private:

};

#endif
