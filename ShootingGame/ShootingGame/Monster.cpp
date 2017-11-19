#include<iostream>
#include<string>
#include"Monster.h"


//Monster 생성자 소멸자
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
//함수 재정의
void Character::move(){

}
void Character::attack(){

}                          