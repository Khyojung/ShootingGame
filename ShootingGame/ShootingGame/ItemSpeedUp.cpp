#include"ItemSpeedUp.h"

ItemSpeedUp::ItemSpeedUp(){
	setCharacterY(itemRandomY());
	setCharacterX(itemRandomX());
	setTime(3);
	setShape("��");
}
ItemSpeedUp::~ItemSpeedUp() {
}

int ItemSpeedUp::itemFunction(Hero* hero){
	hero->setBombCount(hero->getBombCount()+1);
	return getScore();
}
