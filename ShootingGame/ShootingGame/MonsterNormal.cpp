#include"Monster.h"
#include"MonsterNormal.h"

//�Ҹ��� ������
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
//�Լ� ������

void MonsterNormal::move(){
	if(this->getCharacterY() < 50){
		this->setCharacterY(this->getCharacterY()+1);
	}
}
/*
void MonsterNormal::attack(){

} 
*/