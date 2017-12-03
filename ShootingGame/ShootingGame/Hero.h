#pragma once
#include "Character.h"
#include "BulletDatabase.h"
#include "Bullet.h"

class Hero : public Character {
private:
	BulletDatabase* heroBullet;
	int bulletCount;

public:
	Hero();
	~Hero();

	BulletDatabase* getHeroBullet();
	void setHeroBullet(BulletDatabase*);

	void move(int keyboard);
	void attack();
};