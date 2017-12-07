#include"Monster.h"
#include"MonsterLarge.h"

//소멸자 생성자
MonsterLarge::MonsterLarge(){
	right = true;
}
MonsterLarge::MonsterLarge(int newX, int newY){
	this->setCharacterX(newX);
	this->setCharacterY(newY);
	char* temp[3] = {"CCCCCC","CCCCCC","CCCCCC"};
	setShape(temp);
	right = true;
	setDamage(-1);
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
			if(getCharacterX() >= 17)
				setRight(false);
		}
		else{
			this->setCharacterX(this->getCharacterX()-1);
			if(getCharacterX() <= 0)
				setRight(true);
		}
	}
}
bool MonsterLarge::attack(){
	if(((clock()-begin)/CLOCKS_PER_SEC) > 0) {
		begin = clock();
		return true;
		//attack();
	}
	return false;
}