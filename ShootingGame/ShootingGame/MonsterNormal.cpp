#include"Monster.h"
#include"MonsterNormal.h"

//소멸자 생성자
MonsterNormal::MonsterNormal() {
}
MonsterNormal::MonsterNormal(int newX, int newY, int newStageDifficult) {
	char* temp[1] = {"◈"};
	setShape(temp);
	setCharacterX(newX);
	setCharacterY(newY);
	setHp(1 * newStageDifficult);
	setDamage(-1 * newStageDifficult);
}
MonsterNormal::~MonsterNormal(){

}
//함수 재정의

void MonsterNormal::move(){
	if(this->getCharacterY() < 50){
		this->setCharacterY(this->getCharacterY()+1);
	}
}

bool MonsterNormal::attack() {
	return false;
} 