#include<iostream>
#include<string>
#include"Character.h"

//������ �Ҹ���

Character::Character(){

}
Character::~Character(){

}
//������ getter, setter
int Character::getCharacterX(){
	return characterX;
}
void Character::setCharacterX(int cx){
	characterX = cx;
}
int Character::getCharacterY(){
	return characterY;
}
void Character::setChracterY(int cy){
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

//�Լ�
void Character::move(){

}
void Character::attack(){

}