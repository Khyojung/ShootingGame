#include"Monster.h"

//Monster 생성자 소멸자
Monster :: Monster(){
}
Monster :: Monster(int newX, int newY){
	x = newX;
	y = newY;
	setShape("A");
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
	y += pattern;
}
/*
void Monster::attack(){
	bulldata.addBullet(new Bullet(x, y));
} */
