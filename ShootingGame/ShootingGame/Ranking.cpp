#include "Ranking.h"

Ranking::Ranking() {
}
Ranking::~Ranking() {
}
void Ranking::rankPrint() {
	getDatabase().sorting();
}
RankingDatabase Ranking::getDatabase() {
	return database;
}