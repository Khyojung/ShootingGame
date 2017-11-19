#pragma once
#include<iostream>
#include"RankingDatabase.h"

using namespace std;
class Ranking{
	
private:
	RankingDatabase database;
public:
	Ranking();
	~Ranking();
	void rankPrint();
	RankingDatabase getDatabase();
};