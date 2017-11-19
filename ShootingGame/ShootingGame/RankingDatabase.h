#pragma once
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

class RankingDatabase{

private:
	multimap<int,string> ranking;
public:
	RankingDatabase();
	~RankingDatabase();
	void addRank(int, string);
	void delRank();
	void sorting();

};