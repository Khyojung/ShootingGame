#include "Hero.h"

// 생성자, 소멸자
Hero::Hero() { // 히어로의 기본 속성 설정
	setHp(3);
	setSpeed(1);
	setDamage(1);
	setTime(10);
	setCharacterX(10);
	setCharacterY(49);
	setShape("▲");
	bulletCount=0;
	setBombCount(2);
	setBombDamage(10);

	// 총알 데이터베이스 초기화
	heroBullet = new BulletDatabase();
}
Hero::~Hero() {
}

// 변수의 getter, setter
BulletDatabase* Hero::getHeroBullet()  {
	return heroBullet;
}
void Hero::setHeroBullet(BulletDatabase* newBulletDatabase) {
	heroBullet = newBulletDatabase;
}
int Hero::getBombCount() {
	return bombCount;
}
void Hero::setBombCount(int newBombCount) {
	bombCount = newBombCount;
}
int Hero::getBombDamage() {
	return bombDamage;
}
void Hero::setBombDamage(int newBombDamage) {
	bombDamage = newBombDamage;
}

// 함수
void Hero::move(int keyboard) { // 캐릭터의 이동
	// 위로
	if(keyboard == 72 && this->getCharacterY() > 0) {
		this->setCharacterY(this->getCharacterY()-1);
	}

	// 아래로
	if(keyboard == 80 && this->getCharacterY() < 49) {
		this->setCharacterY(this->getCharacterY()+1);
	}

	// 왼쪽
	if(keyboard == 75 && this->getCharacterX() > 0) {
		this->setCharacterX(this->getCharacterX()-1);
	}

	// 오른쪽
	if(keyboard == 77 && this->getCharacterX() < 19) {
		this->setCharacterX(this->getCharacterX()+1);
	}
}
void Hero::attack() { // 총알생성
	Bullet* newBullet = new Bullet(); // 총알의 기본 속성 설정
	newBullet->setCharacterX(getCharacterX());
	newBullet->setCharacterY(getCharacterY()-1);
	newBullet->setDamage(getDamage());
	newBullet->changeShape(); // 총알의 공격력을 기준으로 모양을 바꾸어 줌.
	newBullet->setTime(2);

	// 데이터베이스에 총알 추가
	heroBullet->addBullet(bulletCount, newBullet);
	bulletCount++;
}