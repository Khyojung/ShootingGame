#include"Character.h"

//생성자 소멸자
Character::Character(){
	hp = 0;
	speed = 1;
	damage = 1;
	time = 1000;
	characterX = 0;
	characterY = 0;
}
Character::~Character(){

}

//변수의 getter, setter
int Character::getCharacterX(){
	return characterX;
}
void Character::setCharacterX(int cx){
	characterX = cx;
}
int Character::getCharacterY(){
	return characterY;
}
void Character::setCharacterY(int cy){
	characterY = cy;
}
int Character::getTime(){
	return time;
}
void  Character::setTime(int newTime){
	time = newTime;
}
int Character::getDamage(){
	return damage;
}
void Character::setDamage(int newDamage){
	damage = newDamage;
}
int Character::getSpeed(){
	return speed;
}
void Character::setSpeed(int newSpeed){
	speed = newSpeed;
}
int Character::getHp(){
	return hp;
}
void Character::setHp(int newHp){
	hp = newHp;
}
char* Character::getShape() {
	return shape;
}
void Character::setShape(char* newShape) {
	shape = newShape;
}

//함수
void Character::move(){

}
void Character::attack(){

}