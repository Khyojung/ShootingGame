#include"Monster.h"

//Monster ������ �Ҹ���
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
//�Լ� ������
void Monster::move(){
	y += pattern;
}
/*
void Monster::attack(){
	bulldata.addBullet(new Bullet(x, y));
} */
