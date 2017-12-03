#pragma once
#include <iostream>
#include "Hero.h"
#include <conio.h>
#include "screenBuffer.h"
#include "Bullet.h"
#include "MonsterDatabase.h"
#include "ItemHouse.h"
#include <cstdlib>
#include <ctime>

using namespace std;

class Stage {
private:
	// 이차원 배열 맵을 제거함. 객체로서 자료들을 관리하므로 배열에 값들을 저장할 필요가 없음.
	screenBuffer buffer;
	Hero* hero;
	ItemHouse<Item>* item;
	int score;
	int atime;
	int gameRunSpead;
	MonsterDatabase* monsterDatabase;
	clock_t begin, end;

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