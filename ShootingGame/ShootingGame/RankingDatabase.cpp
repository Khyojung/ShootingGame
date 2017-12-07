#include "RankingDatabase.h"

// 생성자, 소멸자
RankingDatabase::RankingDatabase() {
}
RankingDatabase::~RankingDatabase() {
}

// 함수
void RankingDatabase::addRank(int score, char* userID) { // 랭킹의 인원을 추가한다.
	ranking.insert(pair<int,string> (score, userID));
}
void RankingDatabase::delRank() { // 랭킹을 모두 지운다.
	ranking.clear();
}
void RankingDatabase::sorting() { // sorthing이라고 젹혀있지만, 자체적으로 이미 정렬이 되어있으므로, 순서대로 출력을 해준다.
	multimap<int, string, greater<int>>::iterator iter;
	for (iter = ranking.begin(); iter != ranking.end(); ++iter) {
		cout << "(" << iter->second << " : " << iter->first << ") ";
		cout << endl;
	}
	cout << endl;
	cout << "계속하려면 아무 키나 누르십시오 . . ." << endl;
	getch();
}

