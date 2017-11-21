#pragma once

#include "RankingDatabase.h"

class Ranking{
	
private:
	RankingDatabase database;
public:
	Ranking();
	~Ranking();
	void rankPrint();
	RankingDatabase getDatabase();
};