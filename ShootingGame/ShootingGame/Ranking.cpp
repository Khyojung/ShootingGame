#include "Ranking.h"

// 생성자, 소멸자
Ranking::Ranking() {
}
Ranking::~Ranking() {
}

// 변수의 getter, setter
RankingDatabase Ranking::getDatabase() {
	return database;
}
void Ranking::setDatabase(RankingDatabase newRankingDatabase) {
	database = newRankingDatabase;
}

// 함수
void Ranking::rankPrint() { // 랭킹 데이터베이스로부터 순위를 출력을 한다.
	getDatabase().sorting();
}