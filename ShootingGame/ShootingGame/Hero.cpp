#include "Hero.h"

Hero::Hero() {
	this->setHp(10);
	this->setSpeed(1);
	this->setDamage(1);
	this->setTime(1000);
	this->setCharacterX(10);
	this->setCharacterY(49);
	this->setShape("▲");
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
}
void Hero::setShape(char* newShape) {
	shape = newShape;
}
char* Hero::getShape() {
	return shape;
}