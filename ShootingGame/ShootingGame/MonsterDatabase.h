#include<iostream>
#include<map>
#include"Monster.h"

using namespace std;

class MonsterDatabase{
	
private:
	map <int, Monster*> monster;
public:
	MonsterDatabase();
	~MonsterDatabase();
	void addMonster(int, string);
	void delMonster();

};