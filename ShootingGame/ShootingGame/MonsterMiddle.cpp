#include"Monster.h"
#include"MonsterMiddle.h"
#include <cstdlib>
#include <ctime>

//�Ҹ��� ������
MonsterMiddle::MonsterMiddle(){

}
MonsterMiddle::MonsterMiddle(int newX, int newY){
	this->setCharacterX(newX);
	this->setCharacterY(newY);
	char* temp[2] = {"�آ�","�ע�"};
	setShape(temp);
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