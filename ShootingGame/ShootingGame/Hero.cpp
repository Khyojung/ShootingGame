#include "Hero.h"
Hero::Hero() {
	this->setHp(10);
	this->setSpeed(1);
	this->setDamage(1);
	this->setTime(1000);
	this->setCharacterX(10);
	this->setChracterY(49);
	this->setShape("��");
}
Hero::~Hero() {
}
void Hero::move(int keyboard) {
	// ����
	if(keyboard == 72 && this->getCharacterY() > 0) {
		this->getStage()->setMapXY(this->getCharacterX(), this->getCharacterY(), 0);
		this->setChracterY(this->getCharacterY()-1);
		this->getStage()->setMapXY(this->getCharacterX(), this->getCharacterY(), -1);
	}

	// �Ʒ���
	if(keyboard == 80 && this->getCharacterY() < 49) {
		this->getStage()->setMapXY(this->getCharacterX(), this->getCharacterY(), 0);
		this->setChracterY(this->getCharacterY()+1);
		this->getStage()->setMapXY(this->getCharacterX(), this->getCharacterY(), -1);
	}

	// ����
	if(keyboard == 75 && this->getCharacterX() > 0) {
		this->getStage()->setMapXY(this->getCharacterX(), this->getCharacterY(), 0);
		this->setCharacterX(this->getCharacterX()-1);
		this->getStage()->setMapXY(this->getCharacterX(), this->getCharacterY(), -1);
	}

	// ������
	if(keyboard == 77 && this->getCharacterX() < 19) {
		this->getStage()->setMapXY(this->getCharacterX(), this->getCharacterY(), 0);
		this->setCharacterX(this->getCharacterX()+1);
		this->getStage()->setMapXY(this->getCharacterX(), this->getCharacterY(), -1);
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