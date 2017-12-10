#include"ItemSpeedUp.h"

ItemSpeedUp::ItemSpeedUp(){
	setCharacterY(itemRandomY());
	setCharacterX(itemRandomX());
	setTime(3);
	setShape("¡Ù");
}
ItemSpeedUp::~ItemSpeedUp() {
}

int ItemSpeedUp::itemFunction(Hero* hero){
	hero->setMinAttackTime(hero->getMinAttackTime()-1);
	return getScore();
}
