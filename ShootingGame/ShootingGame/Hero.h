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
	int moveTime;
	int minAttackTime;

public:
	Hero();
	~Hero();

	BulletDatabase* getHeroBullet();
	void setHeroBullet(BulletDatabase*);
	int getBombCount();
	void setBombCount(int);
	int getBombDamage();
	void setBombDamage(int);
	int getMoveTime();
	void setMoveTIme(int);
	int getMinAttackTime();
	void setMinAttackTime(int);

	void move(int keyboard);
	void attack();
};