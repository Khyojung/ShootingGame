#pragma once
#include <map>
#include <iostream>
#include <algorithm>
#include <string>
#include <conio.h>

using namespace std;

class RankingDatabase {
private:
	multimap<int,string,greater<int>> ranking;

public:
	RankingDatabase();
	~RankingDatabase();

	void addRank(int, char*);
	void delRank();
	void sorting();
};