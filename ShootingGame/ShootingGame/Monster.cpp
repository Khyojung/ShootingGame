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
	for(int i = 0; i < strlen(*newShape)/2; i++) {
		shape[i] = newShape[i];
	}
}
//함수 재정의
/*
void Monster::attack(){
	bulldata.addBullet(new Bullet(x, y));
} */