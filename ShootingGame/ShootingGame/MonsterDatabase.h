#pragma once
#include <map>
#include <iostream>
#include <algorithm>
#include "Monster.h"

using namespace std;

class MonsterDatabase{
	
private:
	map <int, Monster*> monster;
public:
	MonsterDatabase();
	~MonsterDatabase();
	void addMonster(int, Monster*);
	void delMonster(int);

};