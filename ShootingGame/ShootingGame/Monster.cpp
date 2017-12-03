#include"Monster.h"

//Monster 생성자 소멸자
Monster :: Monster(){
}
Monster :: Monster(int newX, int newY){
	this->setCharacterX(newX);
	this->setCharacterY(newY);
	setShape("W");
}
Monster :: ~Monster(){
}

//Monster getter, setter
char* Monster::getShape(){
	return shape;
}
void Monster::setShape(char* newShape){
	shape = newShape;
}
//함수 재정의
/*
void Monster::attack(){
	bulldata.addBullet(new Bullet(x, y));
} */