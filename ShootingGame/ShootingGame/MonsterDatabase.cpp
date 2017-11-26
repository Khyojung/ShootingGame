#include "MonsterDatabase.h"
#include <cstdlib>
#include <ctime>

MonsterDatabase::MonsterDatabase() {
	monsterCount = 0;
	srand((unsigned int)time(NULL));
	for(int i = 0 ; i<20; i++){
		dum[i] = rand()%20;
	}
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
	//srand((unsigned int)time(NULL));
	//int newX = rand() % 18;

	int newX = dum[monsterCount % 20];
	addMonster(monsterCount, new Monster(newX, 0));
	monsterCount++;
}
void MonsterDatabase::moveMonster(){
	map<int, Monster*>::iterator iter;
	map<int, int> temp;
	for (iter = monster.begin(); iter != monster.end(); ++iter) {
		iter->second->move();
		if(iter->second->getCharacterY() > 49)
			temp.insert(pair<int, int> (iter->first,iter->first)); 
	}
	map<int, int>::iterator tempIter;
	for(tempIter = temp.begin();tempIter != temp.end(); ++tempIter) {
		this->delMonster(tempIter->second); // �ݺ��ڸ� ���Ͽ� ������ ������ �Ѿ��� ��ȣ�鿡 �ش��ϴ� �Ѿ˵��� ��������.
	}
}