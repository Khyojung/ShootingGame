#pragma once
#include <map>
#include <iostream>
#include <algorithm>
#include "Monster.h"
#include "screenBuffer.h"

using namespace std;

class MonsterDatabase{
	
private:
	map <int, Monster*> monster;
	int monsterCount;
public:
	MonsterDatabase();
	~MonsterDatabase();
	void addMonster(int, Monster*);
	void delMonster(int);
	Monster* findMonster(int);
	void print(screenBuffer);
	void randomCreateMonster();
};