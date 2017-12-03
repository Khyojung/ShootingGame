#include"Monster.h"
#include"MonsterLarge.h"

//소멸자 생성자
MonsterLarge::MonsterLarge(){
	right = true;
}
MonsterLarge::MonsterLarge(int newX, int newY){
	this->setCharacterX(newX);
	this->setCharacterY(newY);
	this->setShape("C");
	right = true;
}
MonsterLarge::~MonsterLarge(){

}
//getter & setter
bool MonsterLarge::getRight(){
	return right;
}
void MonsterLarge::setRight(bool aRight){
	right = aRight;
}
//함수 재정의

void MonsterLarge::move(){
	if(this->getCharacterY() < 50){
		if(right){
			this->setCharacterX(this->getCharacterX()+1);
			if(getCharacterX() >= 19)
				setRight(false);
		}
		else{
			this->setCharacterX(this->getCharacterX()-1);
			if(getCharacterX() <= 0)
				setRight(true);
		}
	}
}
/*
void Character::attack(){

} 
*/