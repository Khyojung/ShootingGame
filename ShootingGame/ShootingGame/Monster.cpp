#include"Monster.h"

//Monster ������ �Ҹ���
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
//�Լ� ������
/*
void Monster::attack(){
	bulldata.addBullet(new Bullet(x, y));
} */