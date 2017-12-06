#include "RankingDatabase.h"

// ������, �Ҹ���
RankingDatabase::RankingDatabase() {
}
RankingDatabase::~RankingDatabase() {
}

// �Լ�
void RankingDatabase::addRank(int score, char* userID) { // ��ŷ�� �ο��� �߰��Ѵ�.
	ranking.insert(pair<int,string> (score, userID));
}
void RankingDatabase::delRank() { // ��ŷ�� ��� �����.
	ranking.clear();
}
void RankingDatabase::sorting() { // sorthing�̶�� ����������, ��ü������ �̹� ������ �Ǿ������Ƿ�, ������� ����� ���ش�.
	multimap<int, string, greater<int>>::iterator iter;
	for (iter = ranking.begin(); iter != ranking.end(); ++iter) {
		cout << "(" << iter->second << " : " << iter->first << ") ";
		cout << endl;
	}
	cout << endl;
	cout << "����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . ." << endl;
	getch();
}

