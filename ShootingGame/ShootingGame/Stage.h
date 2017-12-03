#pragma once
#include <iostream>
#include "Hero.h"
#include <conio.h>
#include "screenBuffer.h"
#include "Bullet.h"
#include "MonsterDatabase.h"
#include "ItemHouse.h"

using namespace std;

class Stage {
private:
	// ������ �迭 ���� ������. ��ü�μ� �ڷ���� �����ϹǷ� �迭�� ������ ������ �ʿ䰡 ����.
	screenBuffer buffer;
	Hero* hero;
	ItemHouse<Item>* item;
	int score;
	int atime;
	int gameRunSpead;
	MonsterDatabase* monsterDatabase;

public:
	Stage();
	~Stage();
	
	int getScore();
	void setScore(int);
	int getTime();
	void setTime(int);
	int getMonsterCount();
	void setMonsterCount(int);

	void start();
	void showMap();
	int scoreCount();
	int timeFlow();
	void showMonster();
};