#pragma once
#include "Character.h"
#include "BulletDatabase.h"
#include "Bullet.h"

class Hero : public Character {
private:
	BulletDatabase* heroBullet;
	int bulletCount;
	int bombCount;
	int bombDamage;

public:
	Hero();
	~Hero();

	BulletDatabase* getHeroBullet();
	void setHeroBullet(BulletDatabase*);
	int getBombCount();
	void setBombCount(int);
	int getBombDamage();
	void setBombDamage(int);

	void move(int keyboard);
	void attack();
};