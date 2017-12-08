#pragma once
#include <map>
#include <iostream>
#include <algorithm>
#include "Monster.h"
#include "MonsterNormal.h"
#include "MonsterLarge.h"
#include "MonsterMiddle.h"
#include "MonsterBoss.h"
#include "screenBuffer.h"
#include "Hero.h"
#include <cstdlib>
#include <ctime>

using namespace std;

class MonsterDatabase{
	
private:
	map <int, Monster*> monster;
	int dum[20];
	int monsterCount;
	bool bossDied;
	MonsterBoss* boss;

public:
	MonsterDatabase();
	~MonsterDatabase();

	MonsterBoss* getBoss();
	void setBossDied(bool);
	bool getBossDied();


	void addMonster(int, Monster*);
	void delMonster(int);
	void delBossMonster();
	Monster* findMonster(int);
	void print(screenBuffer);
	void randomCreateMonster();
	void createBossMoster();
	void moveMonster();
	int whenHeroUseBomb(int);
	int whenCrashWithHero(Hero*);
	int whenCrashWithBullet(Hero*);
	int MonsterDatabase::whenBossMCrashWithBullet(Hero* hero);
};