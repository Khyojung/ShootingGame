#include "Ranking.h"

// ������, �Ҹ���
Ranking::Ranking() {
}
Ranking::~Ranking() {
}

// ������ getter, setter
RankingDatabase Ranking::getDatabase() {
	return database;
}
void Ranking::setDatabase(RankingDatabase newRankingDatabase) {
	database = newRankingDatabase;
}

// �Լ�
void Ranking::rankPrint() { // ��ŷ �����ͺ��̽��κ��� ������ ����� �Ѵ�.
	getDatabase().sorting();
}