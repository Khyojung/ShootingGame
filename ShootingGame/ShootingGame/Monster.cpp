#include"Monster.h"

//Monster 생성자 소멸자
Monster :: Monster(){
}
Monster :: Monster(int newX, int newY){
	this->setCharacterX(newX);
	this->setCharacterY(newY);
	setShape("A");
	pattern = 1;
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
int Monster::getPattern(){
	return pattern;
}
void Monster::setPattern(int newPattern){
	pattern = newPattern;
}
//함수 재정의
void Monster::move(){
	if(this->getCharacterY() < 50){
		this->setCharacterY(this->getCharacterY()+pattern);
	}
}
/*
void Monster::attack(){
	bulldata.addBullet(new Bullet(x, y));
} */