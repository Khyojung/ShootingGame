#include<iostream>
#include<string>
#include"Monster.h"


//Monster ������ �Ҹ���
Monster :: Monster(){
}
Monster :: ~Monster(){
}

//Monster getter, setter
char ** Monster::getShape(){
	return shape;
}
void Monster::setShape(char ** newShape){
	shape = newShape;
}
int Monster::getPattern(){
	return pattern;
}
void Monster::setPattern(int newPattern){
	pattern = newPattern;
}
//�Լ� ������
void Character::move(){

}
void Character::attack(){

}                          