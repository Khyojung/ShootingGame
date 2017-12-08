#include "MonsterDatabase.h"

MonsterDatabase::MonsterDatabase() {
	monsterCount = 0;
	monsterBullet = new MonsterBulletDatabase();
	bulletCount = 0;
	bossDied = false;
	boss = NULL;
}
MonsterDatabase::~MonsterDatabase() {
}

MonsterBulletDatabase* MonsterDatabase::getMonsterBullet() {
	return monsterBullet;
}
void MonsterDatabase::setMonsterBullet(MonsterBulletDatabase* newMonsterBulletDatabase) {
	monsterBullet = newMonsterBulletDatabase;
}
//getter setter
MonsterBoss* MonsterDatabase::getBoss(){
	return boss;
}
bool MonsterDatabase::getBossDied(){
	return bossDied;
}
void MonsterDatabase::setBossDied(bool aDied){
	bossDied = aDied;
}


void MonsterDatabase::addMonster(int monsterNumber, Monster* newMonster) {
	monster.insert(pair<int,Monster*> (monsterNumber, newMonster));
}
void MonsterDatabase::delMonster(int monsterNumber) {
	monster.erase(monsterNumber);
}
void MonsterDatabase::delBossMonster(){
	bossDied = true;
	boss->~MonsterBoss();
	boss = NULL;
}
/*Monster* MonsterDatabase::findMonster(int IDNumber){
	monster.find(IDNumber);
}*/
void MonsterDatabase::print(screenBuffer buffer){
	map<int, Monster*>::iterator monsterIter;
	for (monsterIter = monster.begin(); monsterIter != monster.end(); ++monsterIter) {
		for(int i = 0; i < strlen(*monsterIter->second->getShape())/2; i++) {
			buffer.BufferWrite(monsterIter->second->getCharacterX()*2+2, monsterIter->second->getCharacterY()+i+2, *(monsterIter->second->getShape()+i)); 
		}
	}
	if(boss != NULL)
		buffer.BufferWrite(boss->getCharacterX()*2+2, boss->getCharacterY()+1, boss->getShape());
}
void MonsterDatabase::randomCreateMonster(){
	srand((unsigned int)time(NULL));
	int newX = (rand()*rand()) % 19;

	if(monsterCount % 10 == 0){
		addMonster(monsterCount, new MonsterLarge(0, newX));
		monsterCount++;
	}
	else if(monsterCount % 5 == 0){
		srand((unsigned int)time(NULL));
		addMonster(monsterCount, new MonsterMiddle(newX, 0));
		monsterCount++;
	}
	else{
		addMonster(monsterCount, new MonsterNormal(newX, 0));
		monsterCount++;
	}
}
void MonsterDatabase::createBossMoster(){
	boss = new MonsterBoss();
}
void MonsterDatabase::moveMonster(){
	map<int, Monster*>::iterator iter;
	map<int, int> temp;
	for (iter = monster.begin(); iter != monster.end(); ++iter) {
		iter->second->move();
		if(iter->second->attack()) {
			Bullet* newBullet = new Bullet(); // 총알의 기본 속성 설정
			newBullet->setCharacterX(iter->second->getCharacterX()+1);
			newBullet->setCharacterY(iter->second->getCharacterY()+4);
			newBullet->setDamage(iter->second->getDamage());
			newBullet->changeShape(); // 총알의 공격력을 기준으로 모양을 바꾸어 줌.
			newBullet->setTime(2);

			// 데이터베이스에 총알 추가
			monsterBullet->addBullet(bulletCount, newBullet);
			bulletCount++;
		}
		if(iter->second->getCharacterY() > 48)
			temp.insert(pair<int, int> (iter->first,iter->first)); 
	}
	map<int, int>::iterator tempIter;
	for(tempIter = temp.begin();tempIter != temp.end(); ++tempIter) {
		this->delMonster(tempIter->second); // 반복자를 통하여 위에서 제거할 총알의 번호들에 해당하는 총알들을 제거해줌.
	}
	//monsterBullet->moveBullet(); 여기서 총알을 움직여 주면 이동속도가 A랑 같아짐..
}
int MonsterDatabase::whenHeroUseBomb(int bombDamage) {
	int count = 0;
	map<int, Monster*>::iterator iter;
	map<int, int> temp;

	for (iter = monster.begin(); iter != monster.end(); ++iter) {
		iter->second->setHp(iter->second->getHp() - bombDamage);
		if(iter->second->getHp() <= 0) {
			count++;
			temp.insert(pair<int, int> (iter->first,iter->first)); 
		}
	}
	map<int, int>::iterator tempIter;
	for(tempIter = temp.begin();tempIter != temp.end(); ++tempIter) {
		this->delMonster(tempIter->second); // 반복자를 통하여 위에서 제거할 총알의 번호들에 해당하는 총알들을 제거해줌.
	}
	return count;
}
int MonsterDatabase::whenCrashWithHero(Hero* hero) {
	int count = 0;
	map<int, Monster*>::iterator iter;
	map<int, int> temp;
	
	for (iter = monster.begin(); iter != monster.end(); ++iter) {
		if((iter->second->getCharacterX() <= hero->getCharacterX() && hero->getCharacterX() <= iter->second->getCharacterX()+strlen(*iter->second->getShape())/2-1) &&
			(iter->second->getCharacterY() <= hero->getCharacterY() && hero->getCharacterY() <= iter->second->getCharacterY()+strlen(*iter->second->getShape())/2)) {
			iter->second->setHp(iter->second->getHp() - 10);
			hero->setHp(hero->getHp() - 1);
		}
		if(iter->second->getHp() <= 0) {
			count++;
			temp.insert(pair<int, int> (iter->first,iter->first)); 
		}
	}
	map<int, int>::iterator tempIter;
	for(tempIter = temp.begin();tempIter != temp.end(); ++tempIter) {
		this->delMonster(tempIter->second); // 반복자를 통하여 위에서 제거할 총알의 번호들에 해당하는 총알들을 제거해줌.
	}
	return count;

}
int MonsterDatabase::whenCrashWithBullet(Hero* hero) {
	int count = 0;
	map<int, Monster*>::iterator monsterIter;
	map<int, Bullet*>::iterator bulletIter;

	map<int, int> deleteMonster;
	map<int, int> deleteBullet;
	for (monsterIter = monster.begin(); monsterIter != monster.end(); ++monsterIter) {
		for (bulletIter = hero->getHeroBullet()->getBullet()->begin(); bulletIter != hero->getHeroBullet()->getBullet()->end(); ++bulletIter) {
			if((monsterIter->second->getCharacterX() <= bulletIter->second->getCharacterX() && bulletIter->second->getCharacterX() <= monsterIter->second->getCharacterX()+strlen(*monsterIter->second->getShape())/2-1) &&
				(monsterIter->second->getCharacterY() <= bulletIter->second->getCharacterY() && bulletIter->second->getCharacterY() <= monsterIter->second->getCharacterY()+strlen(*monsterIter->second->getShape())/2)) {
				monsterIter->second->setHp(monsterIter->second->getHp() - hero->getDamage());
				deleteBullet.insert(pair<int, int> (bulletIter->first, bulletIter->first));
			}
		}
		if(monsterIter->second->getHp() <= 0) {
			count++;
			deleteMonster.insert(pair<int, int> (monsterIter->first,monsterIter->first)); 
		}
	}
	map<int, int>::iterator del;
	for(del = deleteMonster.begin(); del != deleteMonster.end(); ++del) {
		this->delMonster(del->second); // 반복자를 통하여 위에서 제거할 총알의 번호들에 해당하는 총알들을 제거해줌.
	}
	for(del = deleteBullet.begin(); del != deleteBullet.end(); ++del) {
		hero->getHeroBullet()->delBullet(del->second);
	}
	return count;
}
int MonsterDatabase::whenBossMCrashWithBullet(Hero* hero){
	map<int, Bullet*>::iterator bulletIter;
	map<int, int> deleteBullet;
	for (bulletIter = hero->getHeroBullet()->getBullet()->begin(); bulletIter != hero->getHeroBullet()->getBullet()->end(); ++bulletIter) {
		int bossX = boss->getCharacterX();
		int bossY = boss->getCharacterY();
		int bullX = bulletIter->second->getCharacterX();
		int bullY = bulletIter->second->getCharacterY();
		if((bossX <= bullX) && ((bossX + 15) >= bullX) && bossY == bullY) {
			boss->setHp(boss->getHp() - hero->getDamage());
			deleteBullet.insert(pair<int, int> (bulletIter->first, bulletIter->first));
		}
	}
	map<int, int>::iterator del;
	for(del = deleteBullet.begin(); del != deleteBullet.end(); ++del) {
		hero->getHeroBullet()->delBullet(del->second);
	}
  	if(boss->getHp() <= 0) {
		delBossMonster();
		return 100;
	}
	return 0;
}
