#include"Character.h"

// ������, �Ҹ���
Character::Character() { // ĳ���Ͱ� �����Ǿ��� ��, �ּ��� ������ �־�� �� ������ �ʱ�ȭ
	hp = 1;
	speed = 1;
	damage = 1;
	atime = 1000;
	characterX = 0;
	characterY = 0;
}
Character::~Character() {
}

// ������ getter, setter
int Character::getHp() {
	return hp;
}
void Character::setHp(int newHp) {
	hp = newHp;
}
int Character::getSpeed() {
	return speed;
}
void Character::setSpeed(int newSpeed) {
	speed = newSpeed;
}
int Character::getDamage() {
	return damage;
}
void Character::setDamage(int newDamage) {
	damage = newDamage;
}
int Character::getTime() {
	return atime;
}
void  Character::setTime(int newTime) {
	atime = newTime;
}
int Character::getCharacterX() {
	return characterX;
}
void Character::setCharacterX(int cx) {
	characterX = cx;
}
int Character::getCharacterY() {
	return characterY;
}
void Character::setCharacterY(int cy) {
	characterY = cy;
}
char* Character::getShape() {
	return shape;
}
void Character::setShape(char* newShape) {
	shape = newShape;
}