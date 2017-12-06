#include"Monster.h"
#include"MonsterNormal.h"

//소멸자 생성자
MonsterNormal::MonsterNormal(){
}
MonsterNormal::MonsterNormal(int newX, int newY){
	this->setCharacterX(newX);
	this->setCharacterY(newY);
	char* temp[2] = {"AAAA","AAAA"};
	setShape(temp);
}

MonsterNormal::~MonsterNormal(){

}
//함수 재정의

void MonsterNormal::move(){
	if(this->getCharacterY() < 50){
		this->setCharacterY(this->getCharacterY()+1);
	}
}
/*
void MonsterNormal::attack(){

} 
*/