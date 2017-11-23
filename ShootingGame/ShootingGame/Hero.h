#pragma once
#include "Character.h"
#include "BulletDatabase.h"
#include "Bullet.h"

using namespace std;

class Hero : public Character{

private:
	BulletDatabase* heroBullet;
	int bulletCount;
public:
	Hero();
	~Hero();
	void move(int keyboard);
	void attack();

	void setHeroBullet(BulletDatabase*);
	BulletDatabase* getHeroBullet();
};