#include"Monster.h"
#include"MonsterMiddle.h"

//�Ҹ��� ������
MonsterMiddle::MonsterMiddle() {
}
MonsterMiddle::MonsterMiddle(int newX, int newY, int newStageDifficult) {
	char* temp[2] = {"�آ�","�ע�"};
	setShape(temp);
	setCharacterX(newX);
	setCharacterY(newY);
	setHp(2 * newStageDifficult);
	setDamage(-1 * newStageDifficult);
}
MonsterMiddle::~MonsterMiddle(){

}
//�Լ� ������

void MonsterMiddle::move(){
	if(this->getCharacterY() < 50){
		srand((unsigned int)time(NULL));
		int derection = (rand()*rand()) % 3;

		if(derection == 0 && this->getCharacterX() < 18)
			this->setCharacterX(this->getCharacterX()+1);
		else if(derection == 1 && this->getCharacterX() > 0)
			this->setCharacterX(this->getCharacterX()-1);
		else
			this->setCharacterY(this->getCharacterY()+1);
	}
}

bool MonsterMiddle::attack(){
	return false;
} 