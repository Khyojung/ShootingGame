#pragma once
#include <map>
#include <iostream>
#include <algorithm>
#include "Bullet.h"
#include "screenBuffer.h"
#include "Hero.h"

using namespace std;

class MonsterBulletDatabase{
private:
	map <int, Bullet*> bullet;
	int bullNumber;

public:
	MonsterBulletDatabase();
	~MonsterBulletDatabase();

	map <int, Bullet*>* getBullet();

	void addBullet(int, Bullet*);
	void delBullet(int);
	void printBullet(screenBuffer);
	void moveBullet(Hero*);
};