#include "Hero.h"

Hero::Hero() {
	this->setHp(10);
	this->setSpeed(1);
	this->setDamage(1);
	this->setTime(10);
	this->setCharacterX(10);
	this->setCharacterY(49);
	this->setShape("▲");
	this->bulletCount=0;
	heroBullet = new BulletDatabase();
}
Hero::~Hero() {
}
void Hero::move(int keyboard) {
	// 위로
	if(keyboard == 72 && this->getCharacterY() > 0) {
		this->setCharacterX(this->getCharacterX());
		this->setCharacterY(this->getCharacterY()-1);
	}

	// 아래로
	if(keyboard == 80 && this->getCharacterY() < 49) {
		this->setCharacterX(this->getCharacterX());
		this->setCharacterY(this->getCharacterY()+1);
	}

	// 왼쪽
	if(keyboard == 75 && this->getCharacterX() > 0) {
		this->setCharacterX(this->getCharacterX()-1);
		this->setCharacterY(this->getCharacterY());
	}

	// 오른쪽
	if(keyboard == 77 && this->getCharacterX() < 19) {
		this->setCharacterX(this->getCharacterX()+1);
		this->setCharacterY(this->getCharacterY());
	}
}
void Hero::attack() {
	Bullet* newBullet = new Bullet();
	newBullet->setCharacterX(getCharacterX());
	newBullet->setCharacterY(getCharacterY()-1);
	newBullet->setDamage(getDamage());
	newBullet->changeShape();
	newBullet->setTime(3);
	heroBullet->addBullet(bulletCount, newBullet);
	bulletCount++;
}
void Hero::setHeroBullet(BulletDatabase* newBulletDatabase) {
	heroBullet = newBulletDatabase;
}
BulletDatabase* Hero::getHeroBullet()  {
	return heroBullet;
}