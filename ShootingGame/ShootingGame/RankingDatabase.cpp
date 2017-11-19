#pragma once
#include "RankingDatabase.h"

using namespace std;

RankingDatabase::RankingDatabase() {
}
RankingDatabase::~RankingDatabase() {
}
void RankingDatabase::addRank(int score, string userID) {
	ranking.insert(pair<int,string> (score, userID));
}
void RankingDatabase::delRank() {
	ranking.clear();
}
void RankingDatabase::sorting() {
	multimap<int, string>::iterator iter;
	for (iter = ranking.begin(); iter != ranking.end(); ++iter) {
		printf("(%s : %d)",iter->second,iter->first);
	}
}