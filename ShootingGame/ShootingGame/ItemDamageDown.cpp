#include"ItemDamageDown.h"

ItemDamageDown::ItemDamageDown(){
	setCharacterY(itemRandomY());
	setCharacterX(itemRandomX());
	setTime(3);
	setShape("бщ");
}
ItemDamageDown::~ItemDamageDown() {
}

int ItemDamageDown::itemFunction(Hero* hero){
	if(hero->getDamage() > 1)
		hero->setDamage(hero->getDamage()-1);

		return getScore();
}
