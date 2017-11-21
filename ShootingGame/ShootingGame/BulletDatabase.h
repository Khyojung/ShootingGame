#pragma once
#include <map>
#include <iostream>
#include <algorithm>
#include "Bullet.h"

using namespace std;

class BulletDatabase{
	
private:
	multimap <int, Bullet*> bullet;
public:
	BulletDatabase();
	~BulletDatabase();
	void addBullet(int, Bullet*);
	void delBullet(int);

};