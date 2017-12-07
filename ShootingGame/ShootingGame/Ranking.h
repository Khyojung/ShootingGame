#pragma once
#include "RankingDatabase.h"

class Ranking{
private:
	RankingDatabase* database;

public:
	Ranking();
	~Ranking();

	RankingDatabase* getDatabase();
	void setDatabase(RankingDatabase*);

	void rankPrint();
};