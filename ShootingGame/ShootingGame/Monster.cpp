#include"Monster.h"

//Monster 생성자 소멸자
Monster :: Monster(){
}
Monster :: Monster(int newX, int newY){
	this->setCharacterX(newX);
	this->setCharacterY(newY);
	char* temp[] = {"MMMM","MMMM"};
	setShape(temp);
}
Monster :: ~Monster(){
}

//Monster getter, setter
char** Monster::getShape(){
	return shape;
}
void Monster::setShape(char** newShape){
	if(newShape[0]=="CCCCCC") {
		shape[0] = newShape[0];
		shape[1] = newShape[1];
		shape[2] = newShape[2];
	}
	else {
		shape[0] = newShape[0];
		shape[1] = newShape[1];
	}
}
//함수 재정의
/*
void Monster::attack(){
	bulldata.addBullet(new Bullet(x, y));
} */