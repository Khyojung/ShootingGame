#include "MonsterDatabase.h"
#include <cstdlib>
#include <ctime>

MonsterDatabase::MonsterDatabase() {
	monsterCount = 0;
}
MonsterDatabase::~MonsterDatabase() {
}
void MonsterDatabase::addMonster(int monsterNumber, Monster* newMonster) {
	monster.insert(pair<int,Monster*> (monsterNumber, newMonster));
}
void MonsterDatabase::delMonster(int monsterNumber) {
	monster.erase(monsterNumber);
}
/*Monster* MonsterDatabase::findMonster(int IDNumber){
	monster.find(IDNumber);
}*/
void MonsterDatabase::print(screenBuffer buffer){
	map<int, Monster*>::iterator iter;
	for (iter = monster.begin(); iter != monster.end(); ++iter) {
		buffer.BufferWrite(iter->second->getCharacterX()*2+2, iter->second->getCharacterY()+1, iter->second->getShape()); 
	}
}
void MonsterDatabase::randomCreateMonster(){
	srand((unsigned int)time(NULL));
	int newX = rand() % 18;
	addMonster(monsterCount, new Monster(newX, 0));
}