#include"Monster.h"
#include"MonsterBoss.h"

MonsterBoss::MonsterBoss(){
	this->setCharacterX(1);
	this->setCharacterY(5);
	this->setShape("DDDDDDDDDDDDDDDDDDDDDDDDDDDDDD");
	this->setHp(10);
	right = true;
}
MonsterBoss::~MonsterBoss(){

}
//getter setter
bool MonsterBoss::getRight(){
	return right;
}
void MonsterBoss::setRight(bool aRight){
	right = aRight;
}


//함수 재정의
void MonsterBoss::move(){
	if(right){
		this->setCharacterX(this->getCharacterX()+1);
		if((getCharacterX() + 15) >= 19)
			setRight(false);
	}
	else{
		this->setCharacterX(this->getCharacterX()-1);
		if(getCharacterX() <= 1)
			setRight(true);
	}
}
/*
void Character::attack(){

} 
*/