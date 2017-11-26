#pragma once
#include <map>
#include <iostream>
#include <algorithm>
#include "Bullet.h"
#include "screenBuffer.h"

using namespace std;

class BulletDatabase{
private:
	multimap <int, Bullet*> bullet;
	int bullNumber;

public:
	BulletDatabase();
	~BulletDatabase();

	void addBullet(int, Bullet*);
	void delBullet(int);
	void printBullet(screenBuffer);
	bool moveBullet();
};