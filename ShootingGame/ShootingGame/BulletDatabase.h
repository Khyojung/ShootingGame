#pragma once
#include <map>
#include <iostream>
#include <algorithm>
#include "Bullet.h"
#include "screenBuffer.h"

using namespace std;

class BulletDatabase{
private:
	map <int, Bullet*> bullet;
	int bullNumber;

public:
	BulletDatabase();
	~BulletDatabase();

	map <int, Bullet*>* getBullet();

	void addBullet(int, Bullet*);
	void delBullet(int);
	void printBullet(screenBuffer);
	void moveBullet();
};