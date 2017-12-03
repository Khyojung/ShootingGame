#pragma once
#include <map>
#include <iostream>
#include <algorithm>
#include "Monster.h"
#include "MonsterNormal.h"
#include "MonsterLarge.h"
#include "MonsterMiddle.h"
#include "screenBuffer.h"

using namespace std;

class MonsterDatabase{
	
private:
	map <int, Monster*> monster;
	int dum[20];
	int monsterCount;
public:
	MonsterDatabase();
	~MonsterDatabase();
	void addMonster(int, Monster*);
	void delMonster(int);
	Monster* findMonster(int);
	void print(screenBuffer);
	void randomCreateMonster();
	void moveMonster();
};